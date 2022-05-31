#include <windows.h>
#include <stdio.h>
int main()
{
    PlaySound("07072028.wav",NULL,SND_ASYNC);///NULL那邊如果有東西，會跟他一起出現
    while(1){///藉由迴圈讓他一直執行
        printf("請輸入:");
        int n;
        scanf("%d",&n);
        if(n==1)PlaySound("re.wav",NULL,SND_ASYNC);
        if(n==2)PlaySound("mi.wav",NULL,SND_ASYNC);
        if(n==3)PlaySound("do.wav",NULL,SND_ASYNC);
    }
}
