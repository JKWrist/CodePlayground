#include <iostream>
#include <string>
#include <openssl/evp.h>
#include <openssl/hmac.h>
#include <openssl/sha.h>

#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/ossl_typ.h>
#define OPENSSLKEY "test.key"
#define PUBLICKEY "test_pub.key"
#define BUFFSIZE 1024

#define MODULUS "C8FBCF21"
#define PUBLIC_EXPONENT RSA_F4
#define PRIVATE_EXPONENT "97B55D7D"

char *my_encrypt(char *str, char *path_key); //加密
char *my_decrypt(char *str, char *path_key); //解密

void PrintHex(unsigned char *str, unsigned int len)
{
    int i = 0;
    for (i = 0; i < len; i++)
    {
        if (i % 4 == 0)
        {
            printf("0x");
        }
        printf("%02x", str[i]);
        if (i % 4 == 3)
        {
            printf(" ");
        }
        if (i % 16 == 15)
        {
            printf("\n");
        }
    }
    printf("\n");
}

unsigned char hex2num(char c)
{
    if (c >= '0' && c <= '9')
        return (unsigned char)(c - '0');
    if (c >= 'a' && c <= 'z')
        return (unsigned char)(c - 'a' + 10);
    if (c >= 'A' && c <= 'Z')
        return (unsigned char)(c - 'A' + 10);

    printf("unexpected char: %c", c);
    return '0';
}

void hex_string_to_bytes(const char *hexstr, int hexstrlen, unsigned char *bytes)
{
    for (int i = 0; i < hexstrlen; i = i + 2)
    {
        bytes[i / 2] = hex2num(hexstr[i]) << 4 | hex2num(hexstr[i + 1]);
    }
}

void print_hex_str(const unsigned char *data, int length)
{
    for (int i = 0; i < length; i++)
        printf("%02x", (unsigned char)255 & data[i]);
    std::cout << std::endl;
}

int main()
{

    printf("1 g_salt : \n");
    const char *pass = "wwlh1234"; //"qwer1234";
    //const char *salt_str = "845c242ea25e7960b075c281f14abb27a31fef4ca1b1bb9338ac7e5c2a01490b";
    const char *salt_str = "7744714847384f494c637575444749467633686f6c706f4b6a434b69554f386b";
    const char *firstnonce = "a5ca2b47a55257b73d46d73bed5db1e3";
    const char *servernonce = "a5ca2b47a55257b73d46d73bed5db1e3erWFiHTbFJA1KzQ47KbC1JEknePMh0Y0";
    unsigned char g_salt[32];
    hex_string_to_bytes(salt_str, 64, g_salt);
    print_hex_str(g_salt, 32);
    int32_t iterations = 1000;
    uint32_t outputBytes = 32;

    printf("2 salt_password : \n");
    unsigned char salt_password[outputBytes];
    PKCS5_PBKDF2_HMAC(pass, (int)strlen(pass), g_salt, 32, iterations, EVP_sha256(), outputBytes, salt_password);
    print_hex_str(salt_password, 32);

    printf("3 clientKey : \n");
    const char *clientKeyStr = "Client Key";
    unsigned char clientKey[32];
    unsigned int digestLen = 32;
    HMAC(EVP_sha256(), clientKeyStr,
         (int)strlen(clientKeyStr), salt_password, 32,
         clientKey, &digestLen);
    print_hex_str(clientKey, 32);

    printf("4 g_storeKey : \n");
    unsigned char g_storeKey[32];
    SHA256(clientKey, 32, g_storeKey);
    print_hex_str(g_storeKey, 32);

    printf("5 serverKey : \n");
    const char *serverKeyStr = "Server Key";
    unsigned char g_serverKey[32];
    HMAC(EVP_sha256(), serverKeyStr,
         (int)strlen(serverKeyStr), salt_password, 32,
         g_serverKey, &digestLen);
    print_hex_str(g_serverKey, 32);

    printf("6 clientSign : \n");
    std::string authMsg;
    authMsg += firstnonce;
    authMsg += ",";
    authMsg += servernonce;
    authMsg += ",";
    authMsg += servernonce;
    std::cout << "6661 " << authMsg << std::endl;

    char authMsg2[512] = {0};
    strcpy(authMsg2, firstnonce);
    strcat(authMsg2, ",");
    strcat(authMsg2, servernonce);
    strcat(authMsg2, ",");
    strcat(authMsg2, servernonce);
    std::cout << "6662 " << authMsg2 << std::endl << std::endl;

    unsigned char clientSign[32];
    HMAC(EVP_sha256(), (const unsigned char *)authMsg.c_str(), (int)authMsg.length(), g_storeKey, 32,
         clientSign, &digestLen);
    print_hex_str(clientSign, 32);

    printf("7 clientProof : \n");
    unsigned char clientProof[32];
    unsigned int i;
    for (i = 0; i < 32; i++)
    {
        clientProof[i] = clientKey[i] ^ clientSign[i];
    }
    print_hex_str(clientProof, 32);

    ///////////////////////////////////////////////////////////////////////////////////

    RSA *r;
    int bits = 512, ret, len;
    unsigned long e = RSA_3;
    BIGNUM *bnn, *bne, *bnd;
    printf("1111111111111\n");
    r = RSA_generate_key(bits, e, NULL, NULL);
    RSA_print_fp(stdout, r, 11);
    RSA_free(r);

    printf("22222222222222\n");
    bne = BN_new();
    ret = BN_set_word(bne, e);
    r = RSA_new();
    ret = RSA_generate_key_ex(r, bits, bne, NULL);
    RSA_print_fp(stdout, r, 11);
    if (ret != 1)
    {
        printf("RSA_generate_key_ex err!\n");
        return -1;
    }

    RSA_free(r);

    ///////////////////////////////////////////////////////////////////////////////////////////
    char *source = "i like dancing !!!";

    char *ptf_en, *ptf_de;

    printf("source is   :%s\n", source);

    //1.加密
    ptf_en = my_encrypt(source, PUBLICKEY);
    printf("ptf_en is   :%s\n", ptf_en);

    //2.解密
    ptf_de = my_decrypt(ptf_en, OPENSSLKEY);
    printf("ptf_de is   :%s\n", ptf_de);

    if (ptf_en)
        free(ptf_en);
    if (ptf_de)
        free(ptf_de);
    //////////////////////////////////////////////////////////////////////////////////


    FILE *Private_key_file;
    FILE *Public_key_file;

    Private_key_file = fopen("./prikey.pem", "w+");
    Public_key_file = fopen("./pubkey.pem", "w+");

    RSA *rsa = RSA_generate_key(2048, 65537, NULL, NULL);
    // PEM_write_RSAPrivateKey(Private_key_file, rsa, NULL, NULL, 0, NULL, NULL);
    // PEM_write_RSA_PUBKEY(Public_key_file, rsa);
    char str[4096] = {0};
    PEM_write_RSAPrivateKey(Private_key_file, rsa, NULL, NULL, 0, NULL, NULL);
    fscanf(Private_key_file, "%s", str);
    printf("6666666666\n %s", str);

    PEM_write_RSA_PUBKEY(Public_key_file, rsa);
    fscanf(Public_key_file, "%s", str);
    printf("7777777\n %s", str);

    RSA_free(rsa);

    fclose(Private_key_file);

    return 0;
}

//加密
char *my_encrypt(char *str, char *path_key)
{
    char *p_en = NULL;
    RSA *p_rsa = NULL;
    FILE *file = NULL;

    int rsa_len = 0; //flen为源文件长度�?? rsa_len为�?�钥长度

    //1.打开秘钥文件
    if ((file = fopen(path_key, "rb")) == NULL)
    {
        perror("fopen() error 111111111 ");
        goto End;
    }

    //2.从公钥中获取 加密的�?�钥
    if ((p_rsa = PEM_read_RSA_PUBKEY(file, NULL, NULL, NULL)) == NULL)
    {
        ERR_print_errors_fp(stdout);
        goto End;
    }

    //3.获取秘钥的长�??
    rsa_len = RSA_size(p_rsa);

    //4.为加密后的内�?? 申�?�空间（根据秘钥的长�??+1�??
    p_en = (char *)malloc(rsa_len + 1);
    if (!p_en)
    {
        perror("malloc() error 2222222222");
        goto End;
    }
    memset(p_en, 0, rsa_len + 1);

    //5.对内容进行加�??
    if (RSA_public_encrypt(rsa_len, (unsigned char *)str, (unsigned char *)p_en, p_rsa, RSA_NO_PADDING) < 0)
    {
        perror("RSA_public_encrypt() error 2222222222");
        goto End;
    }

End:

    //6.释放秘钥空间�?? 关闭文件
    if (p_rsa)
        RSA_free(p_rsa);
    if (file)
        fclose(file);

    return p_en;
}

//解密
char *my_decrypt(char *str, char *path_key)
{
    char *p_de = NULL;
    RSA *p_rsa = NULL;
    FILE *file = NULL;
    int rsa_len = 0;

    //1.打开秘钥文件
    file = fopen(path_key, "rb");
    if (!file)
    {
        perror("fopen() error 22222222222");
        goto End;
    }

    //2.从�?�钥�??获取 解密的�?�钥
    if ((p_rsa = PEM_read_RSAPrivateKey(file, NULL, NULL, NULL)) == NULL)
    {
        ERR_print_errors_fp(stdout);
        goto End;
    }

    //3.获取秘钥的长度，
    rsa_len = RSA_size(p_rsa);

    //4.为加密后的内�?? 申�?�空间（根据秘钥的长�??+1�??
    p_de = (char *)malloc(rsa_len + 1);
    if (!p_de)
    {
        perror("malloc() error ");
        goto End;
    }
    memset(p_de, 0, rsa_len + 1);

    //5.对内容进行加�??
    if (RSA_private_decrypt(rsa_len, (unsigned char *)str, (unsigned char *)p_de, p_rsa, RSA_NO_PADDING) < 0)
    {
        perror("RSA_public_encrypt() error ");
        goto End;
    }

End:
    //6.释放秘钥空间�?? 关闭文件
    if (p_rsa)
        RSA_free(p_rsa);
    if (file)
        fclose(file);

    return p_de;
}