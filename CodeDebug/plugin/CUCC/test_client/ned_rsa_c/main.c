#include <stdio.h>                   // main.cpp
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include "rsa_op.h"
 

int main(int argc, char **argv)
{
	char origin_text[] = "hello world!";
 
	// 由于采用RSA_PKCS1_PADDING方式，因此最大长度不要超过（即- 11）
	int origin_len = sizeof(origin_text);
	int enc_len = 0;
	int dec_len = 0;
	unsigned char *enc_data = NULL;
	unsigned char *dec_data = NULL;
 
	open_prikey_pubkey();
	open_pubkey();
 	#if 0
	// 下面两行是私钥加密，公钥解密
	prikey_encrypt((const unsigned char *)origin_text, origin_len, (unsigned char **)&enc_data, &enc_len);
	pubkey_decrypt(enc_data, enc_len, (unsigned char **)&dec_data, &dec_len);
	printf("decode:%s\n",dec_data);
 	#else
	// 下面两行是公钥加密，私钥解密
	pubkey_encrypt((const unsigned char *)origin_text, origin_len, (unsigned char **)&enc_data, &enc_len);
	prikey_decrypt(enc_data, enc_len, (unsigned char **)&dec_data, &dec_len);
	printf("decode:%s\n",dec_data);
	#endif
	close_key();
 
	free(enc_data);
	free(dec_data);
 
	return 0;
}
