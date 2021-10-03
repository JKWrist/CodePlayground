#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Player
{
    char name[64];//姓名
    int level;   //等级
    int exp;    //玩家经验
};

//初始化游戏                      玩家指针        玩家姓名
void INIT_GAME_COMPANY1(void **player, char *name);

//副本战斗 返回战斗是否胜利 1胜利 0失败 玩家     副本难度
int FIGHT_GAME_COMPANY1(void *player, int gameDiff);

//打印玩家信息
void PRINTF_GAME_COMPANY1(void *player);

//离开游戏
void EXIT_GAME_COMPANY1(void *player);

//判断游戏是否胜利
isWin(int winRate, int diff);

