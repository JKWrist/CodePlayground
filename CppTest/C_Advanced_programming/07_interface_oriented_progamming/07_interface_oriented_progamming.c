#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "gameCompany1.h"


//初始化游戏                      玩家指针        玩家姓名
typedef void(*INIT_GAME)(void ** player, char * name);

//副本战斗 返回战斗是否胜利 1胜利 0失败 玩家     副本难度
typedef int(*FIGHT_GAME)(void * player, int gameDiff);

//打印玩家信息
typedef void(*PRINTF_GAME)(void * player);

//离开游戏
typedef void(*EXIT_GAME)(void * player);

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-03 16:31:15
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void playGame(INIT_GAME init, FIGHT_GAME fight, PRINTF_GAME printGame, EXIT_GAME exitGame)
{
    //初始化游戏
    void *player = NULL;
    printf("请输入姓名：\n");
    char userName[64];
    scanf("%s", userName);

    init(&player, userName);
    printf("0000000\n");
    //副本难度 变量
    int diff = -1;

    while (1)
    {
        getchar();
        system("cls");
        printf("请选择游戏难度：\n");
        printf("1、简单\n");
        printf("2、中等\n");
        printf("3、困难\n");

        scanf("%d", &diff);

        getchar(); //取走换行符
        printf("11111111\n");

        //战斗
        int ret = fight(player, diff);
        printf("222222222\n");
        if (ret == 0)
        {

            printf("游戏失败\n");
            break;
        }
        else
        {
            printf("挑战成功，玩家当前信息如下：\n");

            printGame(player);
        }
    }

    //关闭游戏
    exitGame(player);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-03 16:31:15
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
   srand(time(NULL));

   playGame(INIT_GAME_COMPANY1, FIGHT_GAME_COMPANY1, PRINTF_GAME_COMPANY1, EXIT_GAME_COMPANY1);

   return 0;
}
