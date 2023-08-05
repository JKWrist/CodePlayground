import os
import binascii
from cryptography.hazmat.primitives.kdf.pbkdf2 import PBKDF2HMAC
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import hashes, hmac

backend = default_backend()

# Salts should be randomly generated
hash_algo = "sha256"
password = "qwer1234"
firstnonce = "a224e4aca9beeb03482e729fb9d6e98c36a95727587b27aa427af23d9076dbd4"
iterations = 100
servernonce = "a224e4aca9beeb03482e729fb9d6e98c36a95727587b27aa427af23d9076dbd49ys7zHd8m0EzNabQBr2qo8O7dCtV1bCx"
salt = binascii.unhexlify("845c242ea25e7960b075c281f14abb27a31fef4ca1b1bb9338ac7e5c2a01490b")
# derive
kdf = PBKDF2HMAC(
    algorithm=hashes.SHA256(),
    length=32,
    salt=salt,
    iterations=iterations,
    backend=backend
)
salt_password = kdf.derive(password.encode(encoding="utf8"))
print("salt_password: " + salt_password.hex())

hmac_sha256 = hmac.HMAC(b"Client Key", hashes.SHA256(), backend=default_backend())
hmac_sha256.update(salt_password)
client_key = hmac_sha256.finalize()
print("client key: " + client_key.hex())

sha256 = hashes.Hash(hashes.SHA256(), backend=default_backend())
sha256.update(client_key)
store_key = sha256.finalize()
print("store key:" + store_key.hex())

hmac_sha256 = hmac.HMAC(salt_password, hashes.SHA256(), backend=default_backend())
hmac_sha256.update(b"Server Key")
server_key = hmac_sha256.finalize()

auth_message = firstnonce + "," + servernonce + "," + servernonce;
print(auth_message)

hmac_sha256_sign = hmac.HMAC(auth_message.encode("utf8"), hashes.SHA256(), backend=default_backend())
hmac_sha256_sign.update(store_key)
client_sign = hmac_sha256_sign.finalize()
print("client_sign: " + client_sign.hex())

client_proof = bytearray(len(client_sign))
client_sign = bytearray(client_sign)
client_key = bytearray(client_key)
for i in range(0, len(client_sign)):
    client_proof[i] = client_sign[i] ^ client_key[i]

print("client proof: " + client_proof.hex())
