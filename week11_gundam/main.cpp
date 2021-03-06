#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>///<>在系統找
#include "glm.h"  ///""指在專案目錄找glm.h
GLMmodel * pmodel =NULL; ///一開始沒有模型檔
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        if(pmodel == NULL){
            pmodel = glmReadOBJ("data/Gundam.obj");///讀進模型
            glmUnitize( pmodel );///換算成unit單位大小(-1~+1)
            glmFacetNormals( pmodel );///重新計算模型每個面的法向量
            glmVertexNormals( pmodel, 90);///重新計算模型Vertex的法向量
        }

    glPushMatrix();
        glRotatef(angle,0,1,0);
        glmDraw(pmodel, GLM_TEXTURE);
    glPopMatrix();

    glutSwapBuffers();
    angle += 0.1;
}
int main(int argc,char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week11_Gundam");

    glutIdleFunc(display);
    glutDisplayFunc(display);
    myTexture("data/Diffuse.jpg");///圖檔從這讀入
    glEnable(GL_DEPTH_TEST);///開啟深度功能

    glutMainLoop();
}
