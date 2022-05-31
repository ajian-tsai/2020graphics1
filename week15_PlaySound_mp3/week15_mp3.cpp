#include "CMP3_MCI.h"///記得要放同目錄
#include <stdio.h>
CMP3_MCI mp3;///宣告變數
int main()
{
    mp3.Load("Dream.mp3");
    mp3.Play();

    printf("等你輸入數字，輸入數字程式就卡住\n");
    int n;///為了卡住程式，不要直接結束
    scanf("%d",&n);
}
