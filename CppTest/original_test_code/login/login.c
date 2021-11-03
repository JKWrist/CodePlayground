#include <stdio.h>

const char *errorCategory[] = {
    "ok",
    "Three_time_err",  //用户名密码三次错误，已经锁定。
    "Duplicate_login", //统一用户重复登陆。
    "Too_Many_user",   //登录用户数过多。
    "user_pass_err",   //用户名密码错误。
    "Token_Expire",    //本地登录Token过期
};

typedef enum _ERR_CODE{
    OK = 0,
    THREE_TIME_ERROR = 1,
    DUPLICATE_LOGIN = 2,
    TOO_MANY_USER = 3,
    USER_PASS_ERR = 4,
    TOKEN_EXPIRE = 5,
} ERR_CODE;

int main()
{
    for(int i = 0; i < 6; i++)
    {
        ERR_CODE user_error = i;
        printf("errorCategory %s\n", errorCategory[user_error]);
    }
    printf("\n");
    return 0;
}