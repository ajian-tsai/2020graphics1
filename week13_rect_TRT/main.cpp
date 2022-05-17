#include <GL/glut.h>
float angle=45,oldX=0;
void mouse(int button,int state,int x,int y)
{
    oldX=x;
}
void motion(int x,int y)
{
    angle+=(x-oldX);///改變角度量值
    oldX=x;
    glutPostRedisplay();///請他重新畫display
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);//白色
    glRectf(0.3,0.5,-0.3,-0.5);///身體
    glPushMatrix();//右手
        glTranslatef(0.3,0.4,0);///3.把手一到哪個位置
        glRotatef(angle,0.3,0.4,1);///2.旋轉
        glTranslatef(-0.3,-0.4,0);///1.把旋轉中心放中間
        glColor3f(0,1,0);//綠色
        glRectf(0.3,0.5,0.7,0.3);
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
