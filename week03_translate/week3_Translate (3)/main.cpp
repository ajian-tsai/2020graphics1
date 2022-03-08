#include <GL/glut.h>
#include <stdio.h>
float mousex=0,mousey=0;
void tea(float x, float y)
{
    glPushMatrix();///備份舊的位置的矩陣
        glTranslatef( x , y , 0);///改變位置，不過這個移動會累積，所以要用push 跟pop 來固定位置。Translatef(f前面沒有數字)
        glColor3f(1,1,0);
        glutSolidTeapot(0.1);
    glPopMatrix();///還原矩陣
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
    glutCreateWindow("第三周Translate");
    glutMouseFunc(mouse);

    glutDisplayFunc(display);

    glutMainLoop();
}
