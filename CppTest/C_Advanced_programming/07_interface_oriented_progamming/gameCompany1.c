#include "gameCompany1.h"

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-03 16:57:28
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//初始化游戏                      玩家指针        玩家姓名
void INIT_GAME_COMPANY1(void **player, char *name)
{
    struct Player *player1 = (struct Player *)malloc(sizeof(struct Player));
    if(NULL == player1)
    {
        printf("初始化失败\n");
        return;
    }
    *player = player1;

    strcpy(player1->name, name);
    player1->level = 0;
    player1->exp = 0;
}
/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-03 17:07:24
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//判断游戏是否胜利
isWin(int winRate, int diff)
{
    int random = rand() % 100 + 1;
    if(random <= winRate)
    {
        return diff * 10;
    }

    return 0;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-03 17:10:01
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//副本战斗 返回战斗是否胜利 1胜利 0失败 玩家     副本难度
int FIGHT_GAME_COMPANY1(void *p, int gameDiff)
{
    struct Player * player = p;
    printf("name:%s, level:%d ,exp:%d", player->name, player->level, player->exp);
    int addExp = 0;
    switch (gameDiff)
    {
    case 1:
        addExp = isWin(90, 1);
        break;
    case 2:
        addExp = isWin(70, 2);
        break;
    case 3:
        addExp = isWin(50, 3);
        break;
    default:
        break;
    }
    player->exp += addExp;
    player->level = addExp / 10;
    if(addExp == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}   

//打印玩家信息
void PRINTF_GAME_COMPANY1(void *p)
{
    struct Player * player = p;
    printf("name:%s, level:%d ,exp:%d", player->name, player->level, player->exp);
}

//离开游戏
void EXIT_GAME_COMPANY1(void *player)
{
    if(NULL == player)
    {
        return;
    }

    free(player);
    player = NULL;
}

