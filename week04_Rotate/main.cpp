#include <GL/glut.h>
void Rota(float a)
void display()
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

     glPushMatrix();///�ƥ��ª��x�}
          glRotatef( 90 ,0 ,0,1);///����Z�b
          glColor3f(1,1,0);
          glutSolidTeapot(0.3);
     glPopMatrix();///�٭�x�}

    glutSwapBuffers();
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("�ĤT�P Rotate");


    glutDisplayFunc(display);

    glutMainLoop();
}
