#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define max 9//���б�Ҫ���������

int f(int* player);
int playerdata[max],death[1],num_over,player_num,hole;
int main() {
    //��Ϸ��ʼ��
    printf("�������ޱ����ܣ��������⽨������Debug\n��ʼ��֮�������ִ�����all�ɲ�ѯ��ǰ�������״̬\n�������(֧��1-9�ˣ�����2-6��)��");
    scanf("%d", &player_num);
    printf("��������һ��Ϊ6����");
    scanf("%d", &hole);
    printf("��ʣ���������Ϊ��ʱ��Ϸ������");
    scanf("%d", &num_over);
    char namebase[max][4];
    for (int j = 0; j < player_num; j++) {
        printf("��%dλ��ҵ�������д��", j + 1);
        scanf("%3s", namebase[j]);
    }
    begin:
    for(int m=0;m<max;m++)
        playerdata[m]=hole;//���hole
    death[0]=0;
    int i;
    srand(time(0));   
    printf("�غ�\t������д\t���\n");
    for (i = 1; i > 0; i++) {
        char name[4];
        //д��
        printf("%d\t", i);
        scanf_s("%3s", &name);
        printf("\t\t\t");
        //�ӵ��ж�       
        if (strcmp(name, "all") == 0){
            i--;
            printf("\n���\t״̬\n");
            for(int k=0;k<player_num;k++){
                printf("%s\t",namebase[k]);
                if (playerdata[k]<0)
                    printf("%dǹ������\n",hole+playerdata[k]+1);
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
                        printf("�����ʬ");
                        i--;
                    }
                    printf("\n");
                }
            }
        }else{
            printf("����\n");
            i--;
        }
        if(death[0]==(player_num-num_over)){
            break;
        }
    }
    printf("\n��Ϸ������ʤ������");
    for(int k=0;k<player_num;k++){
        if(playerdata[k]>0)
            printf("%s\t",namebase[k]);
    }
    printf("\n���\t״̬\n");
    for(int k=0;k<player_num;k++){
        printf("%s\t",namebase[k]);
        if (playerdata[k]<0)
            printf("%dǹ������\n",hole+playerdata[k]+1);
        else
            printf("(%d/%d)\n",hole-playerdata[k],hole);
    }
    printf("********************************************\n");
    int dec;
    printf("\n����1������һ�֣������Ը����������:");
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