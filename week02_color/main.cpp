#include <GL/glut.h> ///�ϥ�GLUT�~��,²�Ƶ{��
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///���M���Ϲ�
    glBegin(GL_POLYGON);///�h���
        glColor3f(1,0,0);//����
        glVertex2f(-1,-1);

        glColor3f(0,1,0);//���
        glVertex2f(+1,-1);

        glColor3f(0,0,1);//�Ŧ�
        glVertex2f(0,+1);
    glEnd();

    glutSwapBuffers();///�e�n��A�洫�X��
}

int main(int argc, char** argv)///Main�D�禡
{
    glutInit( &argc, argv);///��Ѽưe��glutInit ��l��
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH); ///�إ� ���Buffer + 3D�`�ץ\��
    glutCreateWindow("��2�g���m��T����!");///�}GLUT�����A�᭱���W�ٳ]�w

    glutDisplayFunc(display);///�Ψ���ܪ��禡

    glutMainLoop();///�D�n�{���j��B�@
}
