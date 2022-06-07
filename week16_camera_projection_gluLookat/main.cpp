#include <GL/glut.h>
void reshape(int width, int height)///�����ư��k
{ ///ar�N�Oaspect ratio
     float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);///��Matrix�Ҧ��� PROJECTION��3D��2D
    glLoadIdentity();
    gluPerspective( 60, ar , 0.1 , 100);

    glMatrixMode(GL_MODELVIEW);///3D Model+view
    glLoadIdentity() ;
    gluLookAt( 0, 0, 3, //eye
               0, 0, 0, //center
               0, 1, 0);//up
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(1);
    glutSwapBuffers();

}
void motion(int x,int y){
    glMatrixMode(GL_MODELVIEW);///3D Model+view
    glLoadIdentity();
    gluLookAt((x-150)/150.0,(y-150)/150.0,3,
                    0,0,0,
                    0,1,0);
    glutPostRedisplay();
}
int main(int argc,char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week16_camera");

    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);///��ڭ̧��ܵ����A�h���ܤj�p

    glutMainLoop();
}
