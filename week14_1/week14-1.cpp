#include <stdio.h>
int main()
{///�N�ɮ׫���fout�A�}���ɮ�
    FILE * fout = fopen("file.txt","w+");///("�ɦW"�A"w+"�O�g�J�Ҧ�)
     printf("Hello world\n");
    fprintf(fout,"Hello world");
    fclose(fout);///�����ɮ�
}
