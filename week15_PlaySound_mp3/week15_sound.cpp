#include <windows.h>
#include <stdio.h>
int main()
{
    printf("PlaySound()之前\n");
            ///沒有音檔時，還是會有錯誤音效
    PlaySound("07072028.wav",NULL,SND_SYNC);
    printf("PlaySound()之後\n");
}
