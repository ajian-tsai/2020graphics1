#include <stdio.h>
int main()
{///�N�ɮ׫���fout�A�}���ɮ�
    FILE * fout = fopen("file.txt","w+");///("�ɦW"�A"w+"�O�g�J�Ҧ�)
    fprintf(fout,"3.1415926");
    fclose(fout);///�����ɮ�

    float angle=0;
    FILE * fin = fopen("file.txt","r");///���}�ɮסAŪ�Jfile.txt����fin
    fscanf(fin,"%f",&angle); ///Ū��"�ɦW"�ɮת��B�I�ơA�᭱�O�o�n&Ū�J�C
    printf("Ū��F����:%f",angle);//�L�X
    fclose(fin);
}
