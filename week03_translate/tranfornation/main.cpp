#include <GL/glut.h>
void tea(float x, float y)
{
    glPushMatrix();///�ƥ��ª���m���x�}
        glTranslatef( x , y , 0);///���ܦ�m�A���L�o�Ӳ��ʷ|�ֿn�A�ҥH�n��push ��pop �өT�w��m�CTranslatef(f�e���S���Ʀr)
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///�٭�x�}
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

    tea(0.5,0.5);
    tea(0.5,-0.5);
    tea(-0.5,-0.5);
    tea(-0.5,0.5);

    glutSwapBuffers();
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("�ĤT�PTranslate");

    glutDisplayFunc(display);

    glutMainLoop();
}
