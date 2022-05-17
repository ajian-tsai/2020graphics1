///week13_rect_TRT_TRT
#include <GL/glut.h>
float angle=0,oldX=0;
void mouse(int button,int state,int x,int y)
{
    oldX=x;
}
void motion(int x,int y)
{
    angle+=(x-oldX);///���ܨ��׶q��
    oldX=x;
    glutPostRedisplay();///�ХL���s�edisplay
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);//�զ�
    glRectf(0.3,0.5,-0.3,-0.5);///����
    glPushMatrix();///�W���u
        glTranslatef(0.3,0.4,0);///3.���@����Ӧ�m
        glRotatef(angle,0.3,0.4,1);///2.����
        glColor3f(0,1,0);///���
        glTranslatef(-0.3,-0.4,0);///1.����त�ߩ񤤶�
        glRectf(0.3,0.5,0.7,0.3);
            glPushMatrix();///�U���u
                glTranslatef(0.7,0.4,0);///3.���@����Ӧ�m
                glRotatef(angle,0,0,1);///2.����
                glTranslatef(-0.7,-0.4,0);///1.����त�ߩ񤤶�
                glColor3f(1,0,0);///����
                glRectf(0.7,0.5,1.0,0.3);
            glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc,char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(300,300);
    glutCreateWindow("week13");

    //glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);


    glutMainLoop();
}
