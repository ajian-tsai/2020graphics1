#include <windows.h>
#include <stdio.h>
int main()
{
    printf("PlaySound()���e\n");
            ///�S�����ɮɡA�٬O�|�����~����
    PlaySound("07072028.wav",NULL,SND_SYNC);
    printf("PlaySound()����\n");
}
