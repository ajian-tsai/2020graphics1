#include <stdio.h>
#include <GL\glut.h>
#include <mmsystem.h>
void timer(int t){
    printf("起床，現在時間: %d\n",t);
    PlaySound("do.wav", NULL , SND_ASYNC);
    glutTimerFunc(1000,timer, t+1);///再呼叫下一個timer
}
void display(){
}
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14_auto_timer");

    glutTimerFunc(5000,timer, 0);///設定五秒後，才會出現timer 0
    ///glutTimerFunc(等多久時間, timer ,t參數)
    glutDisplayFunc(display);
    glutMainLoop();
}
