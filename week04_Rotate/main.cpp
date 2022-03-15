#include <GL/glut.h>
void Rota(float a)
void display()
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

     glPushMatrix();///備份舊的矩陣
          glRotatef( 90 ,0 ,0,1);///旋轉Z軸
          glColor3f(1,1,0);
          glutSolidTeapot(0.3);
     glPopMatrix();///還原矩陣

    glutSwapBuffers();
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("第三周 Rotate");


    glutDisplayFunc(display);

    glutMainLoop();
}
