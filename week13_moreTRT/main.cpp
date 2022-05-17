///week13_rect_TRT_TRT
#include <GL/glut.h>
float angle[20],oldX=0;
int angleID=0;///紀錄可調整哪個關節
void keyboard(unsigned char key,int x, int y){
    if(key=='0') angleID=0; ///當按下0時，angleID=0
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
}
void mouse(int button,int state,int x,int y)
{
    oldX=x;
}
void motion(int x,int y)
{
    angle[angleID]+=(x-oldX);///改變角度量值///陣列數值改成angleID
    oldX=x;
    glutPostRedisplay();///請他重新畫display
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);//白色
    glRectf(0.3,0.5,-0.3,-0.5);///身體
    glPushMatrix();///右上手臂
        glTranslatef(0.3,0.4,0);///3.把手一到哪個位置
        glRotatef(angle[0],0.3,0.4,1);///2.旋轉
        glColor3f(0,1,0);///綠色
        glTranslatef(-0.3,-0.4,0);///1.把旋轉中心放中間
        glRectf(0.3,0.5,0.7,0.3);
            glPushMatrix();///下手臂
                glTranslatef(0.7,0.4,0);///3.把手一到哪個位置
                glRotatef(angle[1],0,0,1);///2.旋轉
                glTranslatef(-0.7,-0.4,0);///1.把旋轉中心放中間
                glColor3f(1,0,0);///紅色
                glRectf(0.7,0.5,1.0,0.3);
            glPopMatrix();
    glPopMatrix();

    glPushMatrix();///上手臂
        glTranslatef(-0.3,0.4,0);///3.把手一到哪個位置
        glRotatef(angle[2],0.3,-0.4,1);///2.旋轉
        glColor3f(0,1,0);///綠色
        glTranslatef(0.3,-0.4,0);///1.把旋轉中心放中間
        glRectf(-0.3,0.5,-0.7,0.3);
            glPushMatrix();///下手臂
                glTranslatef(-0.7,0.4,0);///3.把手一到哪個位置
                glRotatef(angle[3],0,0,1);///2.旋轉
                glTranslatef(0.7,-0.4,0);///1.把旋轉中心放中間
                glColor3f(1,0,0);///紅色
                glRectf(-0.7,0.5,-1.0,0.3);
            glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc,char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(300,300);///控制視窗大小
    glutCreateWindow("week13");

    //glutIdleFunc(display);
    glutKeyboardFunc(keyboard);//呼叫keyboard
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutMainLoop();
}
