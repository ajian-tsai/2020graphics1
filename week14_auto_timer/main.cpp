#include <stdio.h>
#include <GL\glut.h>
#include <mmsystem.h>
void timer(int t){
    printf("�_�ɡA�{�b�ɶ�: %d\n",t);
    PlaySound("do.wav", NULL , SND_ASYNC);
    glutTimerFunc(1000,timer, t+1);///�A�I�s�U�@��timer
}
void display(){
}
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14_auto_timer");

    glutTimerFunc(5000,timer, 0);///�]�w�����A�~�|�X�{timer 0
    ///glutTimerFunc(���h�[�ɶ�, timer ,t�Ѽ�)
    glutDisplayFunc(display);
    glutMainLoop();
}
