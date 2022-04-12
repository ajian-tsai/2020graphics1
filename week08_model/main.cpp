#include <GL/glut.h>
#include "glm.h"
GLMmodel* pmodel = NULL;///指到GLMmode模型的指標，NULL代表還沒好
void
drawmodel(void)
{
    if (!pmodel) {
	pmodel = glmReadOBJ("data/dolphins.obj");///找模型的位置
	if (!pmodel) exit(0);
	glmUnitize(pmodel);
	glmFacetNormals(pmodel);
	glmVertexNormals(pmodel, 90.0);
    }

    glmDraw(pmodel, GLM_SMOOTH);
}///用來畫3D模型的程式碼

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };///z的加負號

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glColor3f(1,1,0);
        ///glutSolidTeapot( 0.3 );
        drawmodel();///呼叫畫模型
    glutSwapBuffers();
}
int main( int argc ,char **argv){
    glutInit(&argc , argv);
    glutInitDisplayMode( GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glutCreateWindow("week08 model");
    ///複製的程式碼要放glutCreateWindow內!!

    glutDisplayFunc(display);

    glEnable(GL_DEPTH_TEST);///開啟深度功能
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0); ///打開/建立燈光
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
    ///之後要放在glutMainLoop以前!!

}
