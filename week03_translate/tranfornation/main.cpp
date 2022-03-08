#include <GL/glut.h>
void tea(float x, float y)
{
    glPushMatrix();///備份舊的位置的矩陣
        glTranslatef( x , y , 0);///改變位置，不過這個移動會累積，所以要用push 跟pop 來固定位置。Translatef(f前面沒有數字)
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
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
    glutCreateWindow("第三周Translate");

    glutDisplayFunc(display);

    glutMainLoop();
}
