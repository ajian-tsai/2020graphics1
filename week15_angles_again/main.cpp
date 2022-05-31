///week13_rect_TRT_TRT
#include <GL/glut.h>
#include <stdio.h>
float angle[20],oldX=0;
int angleID=0;///紀錄可調整哪個關節
FILE *fout =NULL, * fin =NULL;//初始檔案為空的
void mywrite(){
    if(fout == NULL) fout = fopen("file.txt","w+");//如果是空的就開檔案

    for(int i=0;i<20;i++){///因為我們angle有20個
        printf("%.1f",angle[i]);///從小黑印出來
        fprintf(fout,"%.1f ",angle[i]);///從檔案印出
    }
    printf("\n");
    fprintf(fout ,"\n");
}
void myRead(){
    if(fout !=NULL ){ fclose(fout); fout = NULL; } ///當我們按下r時，fout不是空的就關掉他並清除
    if( fin == NULL ) fin = fopen("file.txt","r");
    for(int i=0;i<20;i++){
        fscanf( fin, "%f" , &angle[i] );///讀入剛剛寫的角度
    }
    glutPostRedisplay();///重畫畫面
}
void keyboard(unsigned char key,int x, int y){
    if( key=='s') mywrite(); ///調好後，按S才一次存檔
    if(key == 'r') myRead(); ///當按著r就會動，長按
    if(key=='0') angleID=0; ///當按下0時，angleID=0
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
    angle[angleID]+=(x-oldX);///改變角度量值///陣列數值改成angleID
    ///mywrite();//這裡會一直存檔
    oldX=x;
    glutPostRedisplay();///請他重新畫display
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);//白色
    glRectf(0.3,0.5,-0.3,-0.5);///身體
    glPushMatrix();///右上手臂
        glTranslatef(0.3,0.4,0);///3.把手一到哪個位置
        glRotatef(angle[0],0.3,0.4,1);///2.旋轉
        glColor3f(0,1,0);///綠色
        glTranslatef(-0.3,-0.4,0);///1.把旋轉中心放中間
        glRectf(0.3,0.5,0.7,0.3);
            glPushMatrix();///下手臂
                glTranslatef(0.7,0.4,0);///3.把手一到哪個位置
                glRotatef(angle[1],0,0,1);///2.旋轉
                glTranslatef(-0.7,-0.4,0);///1.把旋轉中心放中間
                glColor3f(1,0,0);///紅色
                glRectf(0.7,0.5,1.0,0.3);
            glPopMatrix();
    glPopMatrix();

    glPushMatrix();///上手臂
        glTranslatef(-0.3,0.4,0);///3.把手一到哪個位置
        glRotatef(angle[2],0.3,-0.4,1);///2.旋轉
        glColor3f(0,1,0);///綠色
        glTranslatef(0.3,-0.4,0);///1.把旋轉中心放中間
        glRectf(-0.3,0.5,-0.7,0.3);
            glPushMatrix();///下手臂
                glTranslatef(-0.7,0.4,0);///3.把手一到哪個位置
                glRotatef(angle[3],0,0,1);///2.旋轉
                glTranslatef(0.7,-0.4,0);///1.把旋轉中心放中間
                glColor3f(1,0,0);///紅色
                glRectf(-0.7,0.5,-1.0,0.3);
            glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc,char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(300,300);///控制視窗大小
    glutCreateWindow("week15_TRT_angles");

    //glutIdleFunc(display);
    glutKeyboardFunc(keyboard);//呼叫keyboard
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutMainLoop();
}
