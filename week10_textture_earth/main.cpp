#include <GL/glut.h>
#include <opencv/highgui.h>
#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include <GL/glut.h>
GLUquadric * sphere = NULL; ///���СA����G������
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCVŪ��
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV���m (�ݭncv.h)
    glEnable(GL_TEXTURE_2D); ///1. �}�ҶK�ϥ\��
    GLuint id; ///�ǳƤ@�� unsigned int ���, �s �K��ID
    glGenTextures(1, &id); /// ����Generate �K��ID
    glBindTexture(GL_TEXTURE_2D, id); ///�j�wbind �K��ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��T, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��S, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// �K�ϰѼ�, ��j�ɪ�����, �γ̪��I
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// �K�ϰѼ�, �Y�p�ɪ�����, �γ̪��I
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glPushMatrix();
            glRotatef(90, 1 , 0 , 0);///��a�y�ॿ�A�ϥL����Ө��D����C
            glRotatef(angle, 0 , 0 , 1);
            gluQuadricTexture(sphere,1);///�]�n�K��(����,�O�_�}��)
            gluSphere(sphere,1,30,30);///�e��ΡAgluSphere(����, �b�|, ����(���g��),���|(���n��))
        glPopMatrix();
    glutSwapBuffers();
    angle+=1;
}
int main(int argc,char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week10_texture_earth");

    glEnable(GL_DEPTH_TEST);///�}�Ҳ`�ץ\��
    glutIdleFunc(display);///����idle�I�sdisplay
    glutDisplayFunc(display);
    myTexture("earth.jpg");///���ɱq�oŪ�J
    sphere = gluNewQuadric();///�ǳƦn2������
    glutMainLoop();
}