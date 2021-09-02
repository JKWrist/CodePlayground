#include <stdio.h>  
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
 
RSA *_pub_key;
RSA *_pri_key;
 

static char *e_str = "10001";//
static char *d_str  = "AD340D955EBEABD9D498E7E51AE49ADD5A0CD8C0ED4AEDF509B9D3CD0A74A03C47611BC020E3C27BE7442941063097EB7A86043AEC4D80EC1504CEE1BC9F249633511CDB6752479E8A0D98D6D795810D2F0DBCC93FABD5D316B985DEC7CE7A609F6DA04273A5AF74C7F79A6767A434BF822F3CE75E52B95D9A8F6FB9F15B0781";
static char *n_str  = "BFFE5091BF6C57A865F4D27AAE02D273F8066BA448772CA9D1CB615CE20C5A1E748ADDD8A92988D8C852457BCDD4DB56ACB60B148130BF6413F93EADB09101BFB7B83B92BA15A0298392EDF13C45EC65E5EA4AFFDA4AA81582689BF41339B5F9DADD607B33982F1ECE1AD57150BA67ECDADCA79D3483D09F3EE6210A12084369";

//把16进制字符串转成BIGNUM
BIGNUM* bignum_decode(const char* base64bignum) {
   BIGNUM* bn = NULL;
   int len;
   len = BN_hex2bn(&bn,base64bignum);
   return bn;
}

// 打开私钥
int open_prikey_pubkey()
{
//构建RSA数据结构
	_pri_key = RSA_new();
	_pri_key->e = bignum_decode(e_str);
	_pri_key->d = bignum_decode(d_str);
	_pri_key->n = bignum_decode(n_str);
 
	RSA_print_fp(stdout, _pri_key, 0);
 
	return 0;
}
 

// 打开公钥
int open_pubkey()
{
	//构建RSA数据结构
	_pub_key = RSA_new();
	_pub_key->e = bignum_decode(e_str);
	//_pub_key->d = BN_bin2bn(_pri_expd, _pri_expd_len, _pub_key->d);
	_pub_key->n = bignum_decode(n_str);
 
	RSA_print_fp(stdout, _pub_key, 0);
 
	return 0;
}
// 私钥加密函数
int prikey_encrypt(const unsigned char *in, int in_len,
				   unsigned char **out, int *out_len)
{
	*out_len =  RSA_size(_pri_key);
	printf("out len:%d\n",*out_len);
	*out =  (unsigned char *)malloc(*out_len);
	if(NULL == *out)
	{	
		printf("prikey_encrypt:malloc error!\n");
		return -1;
	}
	memset((void *)*out, 0, *out_len);
 
	printf("prikey_encrypt:Begin RSA_private_encrypt ...\n");
	int ret =  RSA_private_encrypt(in_len, in, *out, _pri_key, RSA_PKCS1_PADDING);
	//RSA_public_decrypt(flen, encData, decData, r,  RSA_NO_PADDING);
 
	return ret;
}
// 公钥解密函数，返回解密后的数据长度
int pubkey_decrypt(const unsigned char *in, int in_len,
						   unsigned char **out, int *out_len)
{
	*out_len =  RSA_size(_pub_key);
	printf("out len:%d\n",*out_len);
	*out =  (unsigned char *)malloc(*out_len);
	if(NULL == *out)
	{
		printf("pubkey_decrypt:malloc error!\n");
		return -1;
	}
	memset((void *)*out, 0, *out_len);
 
	printf("pubkey_decrypt:Begin RSA_public_decrypt ...\n");
	int ret =  RSA_public_decrypt(in_len, in, *out, _pub_key, RSA_PKCS1_PADDING);
 
	return ret;
}
// 公钥加密函数
int pubkey_encrypt(const unsigned char *in, int in_len,
					       unsigned char **out, int *out_len)
{
	*out_len =  RSA_size(_pub_key);
	printf("out len:%d\n",*out_len);
	*out =  (unsigned char *)malloc(*out_len);
	if(NULL == *out)
{
		printf("pubkey_encrypt:malloc error!\n");
		return -1;
	}
        memset((void *)*out, 0, *out_len);
 
	printf("pubkey_encrypt:Begin RSA_public_encrypt ...\n");
	int ret =  RSA_public_encrypt(in_len, in, *out, _pub_key, RSA_PKCS1_PADDING/*RSA_NO_PADDING*/);
 
 
	return ret;
}
 
// 私钥解密函数，返回解密后的长度
int prikey_decrypt(const unsigned char *in, int in_len,
						   unsigned char **out, int *out_len)
{
	*out_len =  RSA_size(_pri_key);
	printf("out len:%d\n",*out_len);
	*out =  (unsigned char *)malloc(*out_len);
	if(NULL == *out)
	{
		printf("prikey_decrypt:malloc error!\n");
		return -1;
	}
	memset((void *)*out, 0, *out_len);
 
	printf("prikey_decrypt:Begin RSA_private_decrypt ...\n");
	int ret =  RSA_private_decrypt(in_len, in, *out, _pri_key, RSA_PKCS1_PADDING);
 
	return ret;
}
 

 
// 释放公钥和私钥结构资源
int close_key()
{
	if(_pub_key)
	{
		RSA_free(_pub_key);
		_pub_key = NULL;
	}
 
	if(_pri_key)
	{
		RSA_free(_pri_key);
		_pri_key = NULL;
	}
 
	return 0;
}

