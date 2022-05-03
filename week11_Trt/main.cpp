#include <GL/glut.h>
void hand(){///設定好手的部分
    glColor3f(0,1,0);
    glutSolidTeapot( 0.2 );
}
void body(){///設定好身體的部分
    glColor3f(0,0.5,0.5);
    glutSolidTeapot( 0.3 );
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        body();
        glPushMatrix();
            glTranslatef(0.5 , 0.2 ,0);///移到右邊
            glRotatef(angle, 0 , 0 ,1);///旋轉
            glTranslatef(0.3 , 0 ,0);
            hand();
        glPopMatrix();
    glutSwapBuffers();
    angle+=0.1;
}
int main(int argc,char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week11_TRT");

    glutIdleFunc(display);///一段時間再去跑一次display。
    glutDisplayFunc(display);

    glutMainLoop();
}
