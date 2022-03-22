#include <GL/glut.h>
#include <stdio.h>
float x=150,y=150,z=0,scale=1.0;
int oldX=0,oldY=0;
void display()
{
    glClearColor( 0.8 , 0.8 , 0.8 , 1);///R G B A (A為半透明功能，目前沒有開)
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glTranslatef( (x-150)/150.0 ,-(y-150)/150.0 ,z);
        glScalef(scale ,scale,scale);
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void keyboard( unsigned char key,int mouseX,int mouseY)
{
}
void mouse(int botton,int state,int mouseX,int mouseY)
{///為了解決圖會瞬間移動的問題
    oldX=mouseX; oldY=mouseY;
}
void motion(int mouseX,int mouseY)
{
    if(mouseX-oldX>0) scale*=1.01;///當滑鼠往右，則放大
    if(mouseX-oldX<0) scale*=0.99;///當滑鼠往左，則縮小
    ///x+=(mouseX-oldX);
    oldX=x;
   /// y+=(mouseY-oldY);
    oldY=y;
    display();
}
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week05 keyboard");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);///鍵盤
    glutMotionFunc(motion);///滑鼠轉動
    glutMouseFunc(mouse);///滑鼠

    glutMainLoop();
}
