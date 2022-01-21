import binascii
import base64
from cryptography.hazmat.primitives.kdf.pbkdf2 import PBKDF2HMAC
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import hashes, hmac
from cryptography.hazmat.primitives.asymmetric.rsa import RSAPublicNumbers, RSAPublicKey
from cryptography.hazmat.primitives.asymmetric.padding import PKCS1v15
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.primitives.padding import PKCS7

import requests

url_base = "http://192.168.3.1/api/"

firstnonce = "a224e4aca9beeb03482e729fb9d6e98c36a95727587b27aa427af23d9076dbd4"

s = requests.Session()

# first login
first_login_body = '{"csrf":{"csrf_param":"mybjJv9oLpAf8VQAsNGWcN03E8EfK0w0","csrf_token":"kwQp0dyj5YNTQMQNQbyz0Maep1ts7XsN"},"data":{"username":"admin","firstnonce":"c7f7b43fcc9443e4b6355cfe47e3ff8a3b42334f6222f8264f8e879f2ae14bd3"}}'
headers = {'Content-Type': 'application/json;charset=UTF-8'}
r = s.post(url_base + "system/user_login_nonce", headers=headers, data=first_login_body)
resp_json = r.json()
print(resp_json)
csrf_param = resp_json['csrf_param']
csrf_token = resp_json['csrf_token']
print(csrf_param, csrf_token)

# second login
second_login_body = '{"csrf":{"csrf_param":"' + csrf_param + '","csrf_token":"' + csrf_token + '"},"data":{"username":"admin","firstnonce":"' + firstnonce + '"}}'
print(second_login_body)
r = s.post(url_base + "system/user_login_nonce", headers=headers, data=second_login_body)
resp_json = r.json()
print(resp_json)
csrf_param = resp_json['csrf_param']
csrf_token = resp_json['csrf_token']
iterations = int(resp_json['iterations'])
servernonce = resp_json['servernonce']
saltHexStr = resp_json['salt']
salt = binascii.unhexlify(saltHexStr)

backend = default_backend()
# Salts should be randomly generated
hash_algo = "sha256"
password = "qwer1234"
# derive
kdf = PBKDF2HMAC(
    algorithm=hashes.SHA256(),
    length=32,
    salt=salt,
    iterations=iterations,
    backend=backend
)
# 使用PBKDF2HMAC算法推导加盐秘钥
salt_password = kdf.derive(password.encode(encoding="utf8"))
print("salt_password: " + salt_password.hex())

# 使用salt_password来HMAC一个固定内容作为交互client key
hmac_sha256 = hmac.HMAC(b"Client Key", hashes.SHA256(), backend=default_backend())
hmac_sha256.update(salt_password)
client_key = hmac_sha256.finalize()
print("client key: " + client_key.hex())

# 使用salt_password得出store key
sha256 = hashes.Hash(hashes.SHA256(), backend=default_backend())
sha256.update(client_key)
store_key = sha256.finalize()
print("store key:" + store_key.hex())

# 使用salt_password得出server key
hmac_sha256 = hmac.HMAC(salt_password, hashes.SHA256(), backend=default_backend())
hmac_sha256.update(b"Server Key")
server_key = hmac_sha256.finalize()

# 签名前的原始内容
auth_message = firstnonce + "," + servernonce + "," + servernonce;
print(auth_message)

# 使用store key 签名
hmac_sha256_sign = hmac.HMAC(auth_message.encode("utf8"), hashes.SHA256(), backend=default_backend())
hmac_sha256_sign.update(store_key)
client_sign = hmac_sha256_sign.finalize()
print("client_sign: " + client_sign.hex())

# client_sign ^ client_key 得出client_proof
client_proof = bytearray(len(client_sign))
client_sign = bytearray(client_sign)
client_key = bytearray(client_key)
for i in range(0, len(client_sign)):
    client_proof[i] = client_sign[i] ^ client_key[i]

print("client proof: " + client_proof.hex())

# final login
login_final_body = '{"csrf":{"csrf_param":"' + csrf_param + '","csrf_token":"' + csrf_token + '"},"data":{"clientproof":"' + client_proof.hex() + '","finalnonce":"' + servernonce + '"}}'
r = s.post(url_base + "system/user_login_proof", headers=headers, data=login_final_body)
resp_json = r.json()
print(resp_json)
csrf_param = resp_json['csrf_param']
csrf_token = resp_json['csrf_token']
rsae = int(resp_json['rsae'], 16)
rsan = int(resp_json['rsan'], 16)
print("rsae:", rsae)
print("rsan:", hex(rsan))

# get password
wifiNonce = "c2b6ae5d6f6779065af11cdf2eb9bf8251e7a4fbedb8359847fac167a1f1c08a"
wifiSalt = "dabe0b02a56272d985575991af4c705944eb90cc2fc0e1268f4b8b6c6243d7fc"
nonceStr = wifiNonce + wifiSalt

base64NonneStr = base64.b64encode(nonceStr.encode(encoding="utf8"))
print(base64NonneStr.decode(encoding="utf8"))

publicKey = RSAPublicNumbers(rsae, rsan).public_key(default_backend())
# TODO:这里需要考虑加密的串长度(字节数组)大于245的情形,要分段加密（245一段）
encResult = publicKey.encrypt(base64NonneStr, PKCS1v15())
encNonceStr = encResult.hex()
print(encNonceStr)
# encNonceStr = "49ee5372533a0848cf0111bf6842ef1c3d845aaf80572c061646586fa8691c77a3b4e61050eb88ee7c03baf84c58f41a73f70a506cf6e487d69ccb3d9d43769defe22f6a4bbbac531f373114b2f1a1ed1afc1593fb4623efd12b336593a86f46e668c00a10094c82114f3d7964ee16818cc784d64c8fb42489317a06f61b253846e7611f255264b54424331fd8ae7b2cd6138bdcf62ce9f0f5fab259ed01eb46840fd1b7aa03b61ec06b295f4723011309cb4eb02144f12875ca4d10047ebe5b509395fc5947168de299652a536098649478469bbe544c07fccaf2daf37ae948ab687f4c721d674276f6d27615e5227eb0e50ef2b7bea27bb55af02264743afb"
print(encNonceStr)

getPwdBody = '{"csrf":{"csrf_param":"' + csrf_param + '","csrf_token":"' + csrf_token + '"},"data":{"module":"2gwifi","nonce":"' + encNonceStr + '"}}'
print(getPwdBody)
r = s.post(url_base + "system/pwd", headers=headers, data=getPwdBody)
resp_json = r.json()
print(resp_json)
csrf_param = resp_json['csrf_param']
csrf_token = resp_json['csrf_token']

encryptedPwd = resp_json['pwd']
print(encryptedPwd)

kdf = PBKDF2HMAC(
    algorithm=hashes.SHA256(),
    length=32,
    salt=binascii.unhexlify(wifiSalt),
    iterations=iterations,
    backend=backend
)
saltedHexStr = kdf.derive(wifiNonce.encode(encoding="utf8")).hex()
print("salt_password: ", saltedHexStr)

aesKey = saltedHexStr[0:32]
aesIV = saltedHexStr[32:64]

cipher = Cipher(algorithms.AES(binascii.unhexlify(aesKey)), modes.CBC(binascii.unhexlify(aesIV)), backend=backend)
decryptor = cipher.decryptor()
thePasswordResult = decryptor.update(binascii.unhexlify(encryptedPwd)) + decryptor.finalize()
print(thePasswordResult)
unpadder = PKCS7(128).unpadder()
thePasswordResult = unpadder.update(thePasswordResult) + unpadder.finalize()
print(thePasswordResult)

#
r = s.get(url_base + "ntwk/wlanwifisync")
resp_json = r.json()
print(resp_json)

#  contentType:"application/json;charset=UTF-8;enp",
newPassword = "qwer1234"
base64NewPassword = base64.b64encode(newPassword.encode(encoding="utf8"))
# 同获取秘钥的加密方式，注意也是要先base64
publicKey = RSAPublicNumbers(rsae, rsan).public_key(default_backend())
# TODO:这里需要考虑加密的串长度(字节数组)大于245的情形,要分段加密（245一段）
newEncryptedPassword = publicKey.encrypt(base64NewPassword, PKCS1v15())
newEncryptedPassword = newEncryptedPassword.hex()
print(newEncryptedPassword)
# modify password
modifyPasswordBody = '{"csrf":{"csrf_param":"' + csrf_param + '","csrf_token":"' + csrf_token + '"},"action":"SsidSettings","data":{"config2g":{"ID":"InternetGatewayDevice.X_Config.Wifi.Radio.1.Ssid.1.","ssid":"HUAWEI-EDYT7G","ssidenable":true,"channel":0,"wmm":true,"advertisement":1,"beacontype":"11i","wpaencmode":"AES","wpakey":"' + newEncryptedPassword + '","notsetwebpassword":true},"setGuestSsid":false}}';
headers = {'Content-Type': 'application/json;charset=UTF-8;enp'}
r = s.post(url_base + "ntwk/WlanGuideBasic?type=notshowpassall", headers=headers, data=modifyPasswordBody)
resp_json = r.json()
print("Modify Password Result:", resp_json)
csrf_param = resp_json['csrf_param']
csrf_token = resp_json['csrf_token']
