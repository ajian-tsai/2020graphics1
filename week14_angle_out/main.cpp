///week13_rect_TRT_TRT
#include <GL/glut.h>
#include <stdio.h>
float angle[20],oldX=0;
int angleID=0;///�����i�վ�������`
FILE *fout =NULL;//��l�ɮ׬��Ū�
void mywrite(){
    if(fout==NULL) fout = fopen("file.txt","w+");//�p�G�O�Ū��N�}�ɮ�

    for(int i=0;i<20;i++){///�]���ڭ�angle��20��
        printf("%.1f",angle[i]);///�q�p�¦L�X��
        fprintf(fout,"%.1f",angle[i]);///�q�ɮצL�X
    }
    printf("\n");
    fprintf(fout ,"\n");
}
void keyboard(unsigned char key,int x, int y){
    if(key=='0') angleID=0; ///����U0�ɡAangleID=0
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
    angle[angleID]+=(x-oldX);///���ܨ��׶q��///�}�C�ƭȧ令angleID
    mywrite();
    oldX=x;
    glutPostRedisplay();///�ХL���s�edisplay
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);//�զ�
    glRectf(0.3,0.5,-0.3,-0.5);///����
    glPushMatrix();///�k�W���u
        glTranslatef(0.3,0.4,0);///3.���@����Ӧ�m
        glRotatef(angle[0],0.3,0.4,1);///2.����
        glColor3f(0,1,0);///���
        glTranslatef(-0.3,-0.4,0);///1.����त�ߩ񤤶�
        glRectf(0.3,0.5,0.7,0.3);
            glPushMatrix();///�U���u
                glTranslatef(0.7,0.4,0);///3.���@����Ӧ�m
                glRotatef(angle[1],0,0,1);///2.����
                glTranslatef(-0.7,-0.4,0);///1.����त�ߩ񤤶�
                glColor3f(1,0,0);///����
                glRectf(0.7,0.5,1.0,0.3);
            glPopMatrix();
    glPopMatrix();

    glPushMatrix();///�W���u
        glTranslatef(-0.3,0.4,0);///3.���@����Ӧ�m
        glRotatef(angle[2],0.3,-0.4,1);///2.����
        glColor3f(0,1,0);///���
        glTranslatef(0.3,-0.4,0);///1.����त�ߩ񤤶�
        glRectf(-0.3,0.5,-0.7,0.3);
            glPushMatrix();///�U���u
                glTranslatef(-0.7,0.4,0);///3.���@����Ӧ�m
                glRotatef(angle[3],0,0,1);///2.����
                glTranslatef(0.7,-0.4,0);///1.����त�ߩ񤤶�
                glColor3f(1,0,0);///����
                glRectf(-0.7,0.5,-1.0,0.3);
            glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc,char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(300,300);///��������j�p
    glutCreateWindow("week13");

    //glutIdleFunc(display);
    glutKeyboardFunc(keyboard);//�I�skeyboard
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutMainLoop();
}
