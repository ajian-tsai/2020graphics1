#include <GL/glut.h>
float angle,oldx=0;///����
void display()
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

     glPushMatrix();///�ƥ��ª��x�}
          glRotatef( angle ,0 ,0,1);///����Z�b
          glColor3f(1,1,0);
          glutSolidTeapot(0.3);
     glPopMatrix();///�٭�x�}

    glutSwapBuffers();
}
void motion(int x,int y)
{
    angle += (x-oldx); ///�N���ʨ�̫᪺��m-�ƹ����U�h���Ĥ@�Ӧ�m=���ʶq�C
    oldx=x;///�N�̫᪺��m����
    display();///�C�ưʷƹ��A�N���e����
}
void mouse(int buttom, int state,int x,int y)
{
    oldx = x; ///�����ƹ����U�h����m(�w��)
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("�ĤT�P Rotate");

    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}
