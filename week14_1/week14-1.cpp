#include <stdio.h>
int main()
{///將檔案指到fout，開啟檔案
    FILE * fout = fopen("file.txt","w+");///("檔名"，"w+"是寫入模式)
     printf("Hello world\n");
    fprintf(fout,"Hello world");
    fclose(fout);///關閉檔案
}
