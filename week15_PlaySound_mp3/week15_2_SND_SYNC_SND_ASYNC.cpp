#include <windows.h>
#include <stdio.h>
int main()
{
    PlaySound("07072028.wav",NULL,SND_ASYNC);///NULL����p�G���F��A�|��L�@�_�X�{
    while(1){///�ǥѰj�����L�@������
        printf("�п�J:");
        int n;
        scanf("%d",&n);
        if(n==1)PlaySound("re.wav",NULL,SND_ASYNC);
        if(n==2)PlaySound("mi.wav",NULL,SND_ASYNC);
        if(n==3)PlaySound("do.wav",NULL,SND_ASYNC);
    }
}
