#include <stdio.h>
#include <string.h>
#include <openssl/rsa.h>

#define DEFBITS 512
#define DEFPRIMES 2

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

void test01()
{
    printf("test01\n");
    int bits = 512, ret, len;
    unsigned long e = RSA_3;
    RSA *r = RSA_generate_key(bits, e, NULL, NULL);
    printf("\n成功生成RSA密钥对\n");
    RSA_print_fp(stdout, r, 11);
}

void test02()
{
    printf("test02\n");

    const BIGNUM *bnn_const, *bne_const, *bnd_const;
    int num = DEFBITS, primes = DEFPRIMES;
    unsigned long f4 = RSA_F4;

    BN_GENCB *cb = BN_GENCB_new();
    BIGNUM *bn = BN_new();
    RSA *rsa = RSA_new();

    if (NULL == bn || NULL == cb || NULL == rsa)
    {
        printf("bn || cb || rsa ==  NULL\n");
        goto end;
    }

    BN_GENCB_set(cb, genrsa_cb, NULL);

    printf("Generating RSA private key, %d bit long modulus (%d primes)\n",
           num, primes);

    if (!BN_set_word(bn, f4) || !RSA_generate_multi_prime_key(rsa, num, primes, bn, cb))
    {
        printf("BN_set_word error ||  RSA_generate_multi_prime_key error\n");
        goto end;
    }

    RSA_print_fp(stdout, rsa, 11);

    RSA_get0_key(rsa, &bnn_const, &bne_const, &bnd_const);

    static char g_e_str[20] = {0};
    static char g_d_str[512] = {0};
    static char g_n_str[512] = {0};

    sscanf(BN_bn2dec(bne_const), "%s", g_e_str);
    sscanf(BN_bn2hex(bnn_const), "%s", g_n_str);
    sscanf(BN_bn2hex(bnd_const), "%s", g_d_str);

    printf("bne_const:%s len %d\n", g_e_str, strlen(g_e_str));
    printf("bnn_const:%s len %d\n", g_n_str, strlen(g_n_str));
    printf("bnd_const:%s len %d\n", g_d_str, strlen(g_d_str));
    printf("\n\n\n");

end:
    BN_free(bn);
    BN_GENCB_free(cb);
    RSA_free(rsa);
}

void test03()
{
   //无注释版生成RSA
    int num = DEFBITS, primes = DEFPRIMES;
    unsigned long f4 = RSA_F4;

    RSA *rsa = RSA_new();
    if (NULL == rsa)
    {
        printf("rsa ==  NULL\n");
        goto end;
    }

    BN_GENCB *cb = BN_GENCB_new();
    BIGNUM *bn = BN_new();
    if (NULL == bn || NULL == cb)
    {
        printf("bn || cb ==  NULL\n");
        goto end;
    }

    BN_GENCB_set(cb, genrsa_cb, NULL);

    if (!BN_set_word(bn, f4) || !RSA_generate_multi_prime_key(rsa, num, primes, bn, cb))
    {
        printf("BN_set_word error ||  RSA_generate_multi_prime_key error\n");
        goto end;
    }
    BN_free(bn);
    BN_GENCB_free(cb);
    
    RSA_print_fp(stdout, rsa, 11);
    printf("\n\n\n");
end:
    RSA_free(rsa);
}

int main(int argc, char **argv)
{
    printf("main\n");

    //test01();

    //test02();

    for (int i = 0; i < 20; i++)
    {
        test03();
    }
    
    return 0;
}

