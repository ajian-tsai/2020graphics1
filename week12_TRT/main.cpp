#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glutSolidTeapot( 0.3 );///白身體
    glPushMatrix();
        glTranslatef(0.4,0.15,0);///3.把它往右放
        glRotatef(angle,0,0,1);///2.旋轉
        glTranslatef(0.2,0,0);///1.旋轉中心放到世界中心，希望 手茶壺的中心旋轉軸 在把手位置，因大小是0.2，才往右0.2
        glColor3f(1,0,0);
        glutSolidTeapot( 0.2 );///紅手臂

        glPushMatrix();
            glTranslatef(0.4,0.15,0);///3.把它往右放
            glRotatef(angle,0,0,1);///2.旋轉
            glTranslatef(0.2,0,0);///1.旋轉中心放到世界中心，希望 手茶壺的中心旋轉軸 在把手位置，因大小是0.2，才往右0.2
            glColor3f(1,0,0);
            glutSolidTeapot( 0.2 );///下面手肘
        glPopMatrix();

    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.4,0.15,0);///3.把它往右放
        glRotatef(-angle,0,0,1);///2.旋轉
        glTranslatef(-0.2,0,0);///1.旋轉中心放到世界中心，希望 手茶壺的中心旋轉軸 在把手位置，因大小是0.2，才往右0.2
        glColor3f(1,0,0);
        glutSolidTeapot( 0.2 );///紅手臂

        glPushMatrix();
            glTranslatef(-0.4,0.15,0);///3.把它往右放
            glRotatef(-angle,0,0,1);///2.旋轉
            glTranslatef(-0.2,0,0);///1.旋轉中心放到世界中心，希望 手茶壺的中心旋轉軸 在把手位置，因大小是0.2，才往右0.2
            glColor3f(1,0,0);
            glutSolidTeapot( 0.2 );///下面手肘
        glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
    angle+=0.1;
}
int main(int argc,char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week12");

    glutIdleFunc(display);
    glutDisplayFunc(display);


    glutMainLoop();
}
