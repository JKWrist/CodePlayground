/*
 * Copyright 1995-2020 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <openssl/bn.h>
#include <openssl/rsa.h>
#include <openssl/rand.h>

#define DEFBITS 512
#define DEFPRIMES 2

static int genrsa_cb(int p, int n, BN_GENCB *cb);

typedef struct pw_cb_data
{
    const void *password;
    const char *prompt_info;
} PW_CB_DATA;

void test01()
{
    printf("11111  test01\n");
    int bits = 512, ret, len;
    unsigned long e = RSA_3;
    RSA *r = RSA_generate_key(bits, e, NULL, NULL);
    //RSA *r = RSA_new();
    printf("\n成功生成RSA密钥对\n");
    RSA_print_fp(stdout, r, 11);
}

int main(int argc, char **argv)
{
    printf("1111   main\n");
    BN_GENCB *cb = BN_GENCB_new();
    //PW_CB_DATA cb_data;
    ENGINE *eng = NULL;
    BIGNUM *bn = BN_new();
    // BIGNUM *bn = BN_new();
    // int len, alen, bits, top, bottom;
    // bits = 160;
    // top = 1;
    // bottom = 1;
    // BN_rand(bn, bits, top, bottom);

    BIO *out = NULL;
    const BIGNUM *e;
    RSA *rsa = NULL;
    const EVP_CIPHER *enc = NULL;
    int ret = 1, num = DEFBITS, primes = DEFPRIMES;
    unsigned long f4 = RSA_F4;
    char *prog, *hexe, *dece;

    if (bn == NULL)
    {
        printf("bn == NULL\n");
        goto end;
    }

    if (cb == NULL)
    {
        printf("cb == NULL\n");
        goto end;
    }
    
    BN_GENCB_set(cb, genrsa_cb, NULL);

    printf("Generating RSA private key, %d bit long modulus (%d primes)\n",
               num, primes);
    rsa = eng ? RSA_new_method(eng) : RSA_new();
    if (rsa == NULL)
    {
        printf("rsa == NULL\n"); 
        goto end;
    }

    if (!BN_set_word(bn, f4) )
    {
        printf("BN_set_word\n");
        goto end;
    }

    if (!RSA_generate_multi_prime_key(rsa, num, primes, bn, cb))
    {
        printf("RSA_generate_multi_prime_key\n");
        //goto end;
    }

    RSA_print_fp(stdout, rsa, 11);

    test01();
    RSA_get0_key(rsa, NULL, &e, NULL);
    hexe = BN_bn2hex(e);
    dece = BN_bn2dec(e);
    printf("%s %s\n", hexe, dece);
    
    if (hexe && dece) 
    {
        printf("e is %s (0x%s)\n", dece, hexe);
    }
    OPENSSL_free(hexe);
    OPENSSL_free(dece);

    ret = 0;
 end:
    BN_free(bn);
    BN_GENCB_free(cb);
    RSA_free(rsa);
    BIO_free_all(out);
    //release_engine(eng);
    //OPENSSL_free(passout);
    // if (ret != 0)
    //     ERR_print_errors(stdout);
    return ret;
}

static int genrsa_cb(int p, int n, BN_GENCB *cb)
{
    char c = '*';

    if (p == 0)
        c = '.';
    if (p == 1)
        c = '+';
    if (p == 2)
        c = '*';
    if (p == 3)
        c = '\n';
    BIO_write(BN_GENCB_get_arg(cb), &c, 1);
    (void)BIO_flush(BN_GENCB_get_arg(cb));
    return 1;
}
