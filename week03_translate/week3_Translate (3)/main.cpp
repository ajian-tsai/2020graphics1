#include <GL/glut.h>
#include <stdio.h>
float mousex=0,mousey=0;
void tea(float x, float y)
{
    glPushMatrix();///�ƥ��ª���m���x�}
        glTranslatef( x , y , 0);///���ܦ�m�A���L�o�Ӳ��ʷ|�ֿn�A�ҥH�n��push ��pop �өT�w��m�CTranslatef(f�e���S���Ʀr)
        glColor3f(1,1,0);
        glutSolidTeapot(0.1);
    glPopMatrix();///�٭�x�}
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

    tea( (mousex-150)/150.0 , -(mousey-150)/150.0 );

    glutSwapBuffers();
}
void mouse( int button,int state ,int x , int y)
{
    printf(" glVertex2f((%d-150)/150.0 ,-(%d-150)/150.0)\n",x,y);
    mousex=x; mousey=y;
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("�ĤT�PTranslate");
    glutMouseFunc(mouse);

    glutDisplayFunc(display);

    glutMainLoop();
}
