#include <stdio.h>
int main()
{///將檔案指到fout，開啟檔案
    FILE * fout = fopen("file.txt","w+");///("檔名"，"w+"是寫入模式)
    fprintf(fout,"3.1415926");
    fclose(fout);///關閉檔案

    float angle=0;
    FILE * fin = fopen("file.txt","r");///打開檔案，讀入file.txt指到fin
    fscanf(fin,"%f",&angle); ///讀到"檔名"檔案的浮點數，後面記得要&讀入。
    printf("讀到了角度:%f",angle);//印出
    fclose(fin);
}
