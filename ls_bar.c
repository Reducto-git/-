#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define max 9//如有必要，方便调整

int f(int* player);
int playerdata[max],death[1],num_over,player_num,hole;
int main() {
    //游戏初始化
    printf("本程序无报错功能，如遇问题建议重新Debug\n初始化之后在名字处键入all可查询当前所有玩家状态\n玩家人数(支持1-9人，建议2-6人)：");
    scanf("%d", &player_num);
    printf("弹孔数（一般为6）：");
    scanf("%d", &hole);
    printf("当剩余存活玩家数为？时游戏结束：");
    scanf("%d", &num_over);
    char namebase[max][4];
    for (int j = 0; j < player_num; j++) {
        printf("第%d位玩家的名字缩写：", j + 1);
        scanf("%3s", namebase[j]);
    }
    begin:
    for(int m=0;m<max;m++)
        playerdata[m]=hole;//填充hole
    death[0]=0;
    int i;
    srand(time(0));   
    printf("回合\t名字缩写\t情况\n");
    for (i = 1; i > 0; i++) {
        char name[4];
        //写表
        printf("%d\t", i);
        scanf_s("%3s", &name);
        printf("\t\t\t");
        //子弹判定       
        if (strcmp(name, "all") == 0){
            i--;
            printf("\n玩家\t状态\n");
            for(int k=0;k<player_num;k++){
                printf("%s\t",namebase[k]);
                if (playerdata[k]<0)
                    printf("%d枪内死亡\n",hole+playerdata[k]+1);
                else
                    printf("(%d/%d)\n",hole-playerdata[k],hole);
            }
            printf("********************************************\n");
        }else if(1==1){
            for(int l=0;l<player_num;l++){
                if (strcmp(name, namebase[l]) == 0){
                    if(playerdata[l]>0)
                        f( &playerdata[l]);
                    else{
                        printf("请勿鞭尸");
                        i--;
                    }
                    printf("\n");
                }
            }
        }else{
            printf("错误\n");
            i--;
        }
        if(death[0]==(player_num-num_over)){
            break;
        }
    }
    printf("\n游戏结束，胜利者是");
    for(int k=0;k<player_num;k++){
        if(playerdata[k]>0)
            printf("%s\t",namebase[k]);
    }
    printf("\n玩家\t状态\n");
    for(int k=0;k<player_num;k++){
        printf("%s\t",namebase[k]);
        if (playerdata[k]<0)
            printf("%d枪内死亡\n",hole+playerdata[k]+1);
        else
            printf("(%d/%d)\n",hole-playerdata[k],hole);
    }
    printf("********************************************\n");
    int dec;
    printf("\n键入1以再来一局，重启以更改玩家配置:");
    scanf("%d",&dec);
    if(dec==1)
        goto begin;
}

int f(int* player) {
    int random_number = rand() % *player;
    if (random_number == 0){
        printf("You DIED!within time %d.", hole - (*player)+1);
        *player=-(*player);
        death[0] ++;
    }else {
        printf("You LIVE! %dLEFT in most.", *player-1);
        --(*player);    
    }
}