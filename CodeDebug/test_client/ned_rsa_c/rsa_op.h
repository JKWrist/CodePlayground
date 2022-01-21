#ifndef __OPENSSL_RSA_CODEC_H__    // rsa_op.h
#define __OPENSSL_RSA_CODEC_H__

int open_prikey_pubkey();
int open_pubkey();
int prikey_encrypt(const unsigned char *in, int in_len,
				   unsigned char **out, int *out_len);
int pubkey_decrypt(const unsigned char *in, int in_len,
						   unsigned char **out, int *out_len);
int pubkey_encrypt(const unsigned char *in, int in_len,
					       unsigned char **out, int *out_len);
int prikey_decrypt(const unsigned char *in, int in_len,
						   unsigned char **out, int *out_len);
int close_key();
 
#endif

