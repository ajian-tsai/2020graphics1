#include <GL/glut.h>
float angle,oldx=0;///角度
void display()
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

     glPushMatrix();///備份舊的矩陣
          glRotatef( angle ,0 ,0,1);///旋轉Z軸
          glColor3f(1,1,0);
          glutSolidTeapot(0.3);
     glPopMatrix();///還原矩陣

    glutSwapBuffers();
}
void motion(int x,int y)
{
    angle += (x-oldx); ///將移動到最後的位置-滑鼠按下去的第一個位置=移動量。
    oldx=x;///將最後的位置紀錄
    display();///每滑動滑鼠，就重畫茶壺
}
void mouse(int buttom, int state,int x,int y)
{
    oldx = x; ///紀錄滑鼠按下去的位置(定錨)
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("第三周 Rotate");

    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}
