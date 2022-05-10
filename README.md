# 2020graphics1
# week01
## 第一個 OpenGL程式:
```
    1.安裝CodeBlock 17.12版後，打開

    2.按File-New-Project→選OpenGL專案
    3.選桌面+打檔名，按下一步
     4.建立好後，按Build&Run就能看到彩色旋轉三角形
```
## 第一個GLUT專案:
```
  1.上Moodle →上課用軟體中下載freeglut-MinGW-3.0.0-1.mp.zip檔→解壓縮到桌面
  2.解壓縮後，點開 freeglut 資料夾裡的 lib 資料夾
  3.其中libfreeglut.a檔複製一份改檔名→libglut32.a (這樣才能讓CodeBlock 的GLUT專案連結使用) 
  4.開啟CodeBlock→File-New-Project→選GLUT專案
  5.取檔名 
  6.設定 GLUT 目錄 C:\Users\????\Desktop\freeglut  (中間會跳出一個視窗直接關掉就行)
  7.按Build&Run，就會有六個東西在跑(按+/-可以調整圖的精細度)
```
## 建立新的Github倉庫/和備份(步驟4以後):
```
1.登入Github，新增新的專案倉庫
2.取名為2020graphics1
3.Public ，Add README ，gitignore 選C++ →建立完成
4.下載 Git for windows並安裝
5.開啟Git Bash 
6. 輸入cd desktop → git clone https://github.com/ajian-tsai/2020graphics1 
    → cd 2020graphics1 (將github有的東西載下來)
7.將要存的檔案放入2020graphics1 資料夾
8.輸入 git status 查看狀態(有紅色的代表有新存入的東西)
9.輸入 git add . 把資料加進去 → 再次查看資料是否完成(輸入 git status，都綠色代表完成 )
  =推入雲端=
*10.第一次登入需要commit →輸入 git config --global user.email " 你的信箱 " 
    →輸入 git config --global user.name "名字"*
11. 輸入 git commit -m "輸入你要的訊息"
12. 最後輸入 git push 推上雲端
```
# week02
## 練習範例
```
1.去 http://https://jsyeh.org/3dcg10 下載三個範例:
    data.zip、windows.zip 、glut32.dll
2. windows.zip 解壓縮成 下載\windows\Shaps.exe

    data.zip 解壓縮成 下載\windows\data\模型 (將解壓縮完的資料夾放進windows.zip解壓縮後的資料夾)

    glut32.dll 複製到 下載\windows\glut32.dll
3.打開Shaes.exe 看範例，試試看

    左邊視窗按右鍵選單:調頂點、改顏色..

    右邊視窗按右鍵選單:可以選點線面...等等圖形。

```
## 跑上週的程式
```
    1.安裝 git for windows→打開Git Bash → 輸入cd desktop 
       →再輸入git clone https://github.com/ajian-tsai/2020graphics1 下載下來
    2.上週下載的 freeglut資料夾裡 lib資料夾裡記得改檔名成 libglut32.a
    3.在CodeBlock 打開 week01_CLUT專案
```
## 親手打造GLUT程式(Color)
```
1.建立一個新的GULT專案
2.撰寫以下程式碼
```
```c++
#include <GL/glut.h> ///使用GLUT外掛,簡化程式

void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///先清除圖像

    glColor3f(1,1,0);///設定色彩****重要****
    glutSolidTeapot(-0.3);///實心的茶壺

    glutSwapBuffers();///畫好後，交換出來
}

int main(int argc, char** argv)///Main主函式
{
    glutInit( &argc, argv);///把參數送給glutInit 初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH); ///建立 兩個Buffer + 3D深度功能
    glutCreateWindow("第2週程式!");///開GLUT視窗，後面為名稱設定

    glutDisplayFunc(display);///用來顯示的函式

    glutMainLoop();///主要程式迴圈運作
}
```
## 打造產生彩色三角形:
```c++
#include <GL/glut.h> ///使用GLUT外掛,簡化程式
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///先清除圖像
    glBegin(GL_POLYGON);///多邊形
        glColor3f(1,0,0); //紅色
        glVertex2f(-1,-1); ///頂點位置

        glColor3f(0,1,0); //綠色
        glVertex2f(+1,-1);

        glColor3f(0,0,1); //藍色
        glVertex2f(0,+1);
    glEnd();

    glutSwapBuffers();///畫好後，交換出來
}

int main(int argc, char** argv)///Main主函式
{
    glutInit( &argc, argv);///把參數送給glutInit 初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH); ///建立 兩個Buffer + 3D深度功能
    glutCreateWindow("第2週的彩色三角形!");///開GLUT視窗，後面為名稱設定

    glutDisplayFunc(display);///用來顯示的函式

    glutMainLoop();///主要程式迴圈運作
}
```
## week03
# ★小技巧:
```
    1.利用#include <math.h>可以用sin()、cos()

    2. 以下程式碼可以形成圓形:(x,y可以更改圖形的位置)

        void mycirle( flaot x , flaot y , float r){

               glBegin(GL_POLYGON);

               for( float a=0 ; a<3.1415926*2 ; a+=0.01){  ///乘2拿掉會有半圓 a讓圓的點變多

                   glVertex2f( x+r*cos(a), y+r*sin(a) );

               }

                glEnd();

        } 
```
# 練習範例:
```
    1.去jsyeh.org/3dcg10/下載 data 跟win32

    2.windows 解壓縮到windows\

        data解壓縮後放進剛剛解壓縮的windows

    3.執行今天要用的windows/Tranformation.exe:

        右上角Screen-space view視窗 按右鍵:可以選擇其他形狀。

        中下 Command manipulation window視窗按右鍵:可以調整旋轉、位置等的數值。
```
# 建立GLUT專案-Translate(移動):
另加函式簡化程式碼:
  更改x和y的值就能一次創造多的茶壺。
```c++
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

```
  
# 能利用滑鼠控制的專案:
```c++
#include <GL/glut.h>
float mousex=0,mousey=0;
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

    tea( (mousex-150)/150.0 , -(mousey-150)/150.0 );

    glutSwapBuffers();
}
void mouse( int button,int state ,int x , int y)
{
    mousex=x; mousey=y;
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("第三周Translate");
    glutMouseFunc(mouse);

    glutDisplayFunc(display);

    glutMainLoop();
}

```
# 利用滑鼠控制印出座標:
```
#include <GL/glut.h>
#include <stdio.h>
float mousex=0,mousey=0;
void tea(float x, float y)
{
    glPushMatrix();///備份舊的位置的矩陣
        glTranslatef( x , y , 0);///改變位置，不過這個移動會累積，所以要用push 跟pop 來固定位置。Translatef(f前面沒有數字)
        glColor3f(1,1,0);
        glutSolidTeapot(0.1);
    glPopMatrix();///還原矩陣
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

    tea( (mousex-150)/150.0 , -(mousey-150)/150.0 );

    glutSwapBuffers();
}
void mouse( int button,int state ,int x , int y)
{
    printf("%d %d %d %d\n",button,state,x,y);
    mousex=x; mousey=y;
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("第三周Translate");
    glutMouseFunc(mouse);

    glutDisplayFunc(display);

    glutMainLoop();
}
```
## 第四周
# 範例理解glRotatef運作方式:
```
    1.上jsyeh.org/3dcg10/ 下載data和win32 解壓縮，點開Tranformation.exe。
    2.可以調整glRotatef的值
        (可按照x,y,z旋轉，利用安培右手定則，拇指指向x或y或z，則四指為旋轉方向)。
        glRotatef( 旋轉角度 , X軸 ,Y軸 ,Z軸) 
    Ex:
        如果旋轉X軸glRotatef(0 , 1.00 ,0 ,0)，則人物會向前旋轉 (像敬禮的動作)。
        如果旋轉Z軸glRotatef(0 , 0 ,0 ,1.00)，則人物會整個往左轉，像側翻 
        (此時的拇指是指向人物面向的方向)。
        如果是glRotatef(0 , 1.00 ,1.00 ,0)，拇指方向會朝右上。
```

# 練習glRotatef專案:
```c++
#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

     glPushMatrix();///備份舊的矩陣
          glRotatef( 90 ,0 ,0,1);///旋轉Z軸90度
          glColor3f(1,1,0);
          glutSolidTeapot(0.3);
     glPopMatrix();///還原矩陣

    glutSwapBuffers();
}
int main(int argc,char**argv)
{
     glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
     glutCreateWindow("第三周 Rotate");

     glutDisplayFunc(display);

     glutMainLoop();
}
```

# 練習滑鼠mouse motion轉動:
★ x是滑鼠左右移動，y是滑鼠上下移動 ★
```
#include <GL/glut.h>
float angle;///角度
void display()
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

     glPushMatrix();///備份舊的矩陣
          glRotatef( angle ,0 ,0,1);///旋轉Z軸
          glColor3f(1,1,0);
          glutSolidTeapot(0.3);
     glPopMatrix();///還原矩陣

    glutSwapBuffers();
}
void motion(int x,int y)
{
    angle = x;
    display();///每滑動滑鼠，就重畫茶壺
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("第三周 Rotate");

    glutMotionFunc(motion); 
    glutDisplayFunc(display);

    glutMainLoop();
}
```
★ 因為轉動會每次重新點位置轉動，以下是解決方式★ 
# 利用mouse 點擊紀錄位置修正:
★ 利用原先的位置和後來移動的位置做修正★
```c++
#include <GL/glut.h>
float angle,oldx=0;///角度
void display()
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

     glPushMatrix();///備份舊的矩陣
          glRotatef( angle ,0 ,0,1);///旋轉Z軸
          glColor3f(1,1,0);
          glutSolidTeapot(0.3);
     glPopMatrix();///還原矩陣

    glutSwapBuffers();
}
void motion(int x,int y)
{
    angle += (x-oldx); ///angle = 將移動到最後的位置 - 滑鼠按下去的第一個位置 = 移動量。
    oldx=x;///將最後的位置紀錄，就不會有問題。
    display();///每滑動滑鼠，就重畫茶壺
}
void mouse(int buttom, int state,int x,int y)
{
    oldx = x; ///紀錄滑鼠按下去的位置(定錨)
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("第三周 Rotate");

    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}
```
## 第五周
# 範例:老師的範例Tranformation.exe
```
下面視窗(Command manipulation window)右鍵可以交換位置(translate)跟旋轉(rotate)的程式執行順序。分別會顯示自轉跟公轉效果!
```

# 利用glutKeyboardFunc()函式使用鍵盤:
```
1.先建立一個glutKeyboardFunc(keyboard)在Main裡。

2.在建立函式void keyboard( unsigned char key , int x , int y) 
   key會去偵測你鍵盤的英文輸入和數字，x和y會去顯示你滑鼠指的位置。
```
```c
#include <GL/glut.h>
#include <stdio.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
void keyboard( unsigned char key,int x,int y)
{
    printf("你按下了%c 在 %d %d 的座標\n",key ,x ,y);
}
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week05 keyboard");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
}
```
# 結合之前mouse (滑鼠)、motion(轉動)函式
```
1.把glutMotionFunc(motion)/glutMouseFunc(mouse);加入
2.設好x,y,z ,oldx,oldy 。
3.在display裡 多加 glPushMatrix(); (備份矩陣)和 glPopMatrix();(還原矩陣)和 glTranslatef( (x-150)/150.0 ,-(y-150)/150.0 ,z); (移動)! 記得y座標要加負號!
4.將motion裡的寫好。 mouse裡寫的是為了解決圖會瞬間移動的問題。
☆更改背景顏色 glClearColor( 0 , 0 , 0 , 1)  R G B A (A為半透明功能，目前沒有開)☆

```
```c
#include <GL/glut.h>
#include <stdio.h>
float x=0,y=0,z=0;
int oldX=0,oldY=0;
void display()
{
    glClearColor( 0.8 , 0.8 , 0.8 , 1);///R G B A (A為半透明功能，目前沒有開)
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glTranslatef( (x-150)/150.0 ,-(y-150)/150.0 ,z);
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
    x+=(mouseX-oldX);
    oldX=x;
    y+=(mouseY-oldY);
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

```

# ◇將scale(縮放)加入
```
1.將先前的x,y設成150，讓他在畫面中間。
2.增加scale=1.0。 並把glScalef(scale ,scale,scale);加入
3.將上一個motion裡的函式，改成:
      if(mouseX-oldX>0) scale*=1.01;(如果滑鼠往右，則放大)
      if(mouseX-oldX<0) scale*=0.99;(如果滑鼠往左，則縮小)
```
```c
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

```

## 第六周
# 老師的程式範例:Light Material.exe
```
1.左上Screen-space view 視窗，按右鍵可變換Model模型。(圓圈、海豚、玫瑰...等)
2.左下World-space view 視窗，按右鍵可以變換Material材質。(銅質、銀質、紅寶石...等)
3.右邊Command manipulation window 視窗可以改想弄的程式。(材質、燈光、聚光..等)
4.Glfloat light_pos[]={ x , y , z , 1}; 是調整光的照射位置。
5.glLightfv(GL_LIGHT0, GL_POSITION ,light_pos) ; 前面的fv是指 float vector 
            GL_LIGHT0 為第幾個燈、GL_POSITION為設定它的位置
6.剩下的ka kd ks都是調光的性質。
```
☆Amblet 無所不在的光、 Diffuse 角度光、 Specular特別的點光、vector陣列☆

# 建立Glut專案!
1.複製下面這兩段程式:
```c++
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
///----///
    glEnable(GL_DEPTH_TEST);
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

```
2.建立好程式:
記得第二段程式碼必須放在glutCreateWindow和glutMainLoop之間程式才會執行!
        glEnable(GL_LIGHT0);  為打開/建立燈光 、
        glEnable(GL_DEPTH_TEST);為開啟深度功能。
```c++
#include <GL/glut.h>
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
        glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}
int main( int argc ,char **argv){
    glutInit(&argc , argv);
    glutInitDisplayMode( GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glutCreateWindow("week06 Light");
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
```
3.將上周的滑鼠(mouse)和轉動(rotate)加入(滑鼠左右就能放大縮小圖形)
```c++
#include <GL/glut.h>
#include <stdio.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };///z的加負號

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

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
}
```


# 4.改成可用滑鼠轉動(rotate):
    先設定一個angle數為0，把glRotatef(angle,0,1,0); 放進矩陣
    glRotatef(angle,0,1,0); 指對y軸旋轉。
    最後在motion設定好用滑鼠控制角度  angle += (mouseX-oldX);
```c++
#include <GL/glut.h>
#include <stdio.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };///z的加負號

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

float x=150,y=150,z=0,scale=1.0,angle=0;
int oldX=0,oldY=0;
void display()
{
    glClearColor( 0.8 , 0.8 , 0.8 , 1);///R G B A (A為半透明功能，目前沒有開)
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glTranslatef( (x-150)/150.0 ,-(y-150)/150.0 ,z);
        glRotatef(angle,0,1,0);///對y軸旋轉
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
    angle += (mouseX-oldX);
    ///if(mouseX-oldX>0) scale*=1.01;///當滑鼠往右，則放大
    ///if(mouseX-oldX<0) scale*=0.99;///當滑鼠往左，則縮小
    ///x+=(mouseX-oldX);
    oldX=mouseX;
   /// y+=(mouseY-oldY);
    oldY=mouseY;
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
}

```
# 5. 利用keybroad 改變移動、轉動、縮放用法:
(1)先設一個now (1.移動 2.轉動 3.縮放)，
(2)在keybroad 寫好按下哪個鍵會是哪種方法:
    if( key=='1'||key=='w'||key=='W') now=1;
    if( key=='2'||key=='e'||key=='E') now=2;
    if( key=='3'||key=='r'||key=='R') now=3;
(3)再去motion將now對應的方法寫入 :
    if(now==1){///移動
        x+=(mouseX-oldX);
        y+=(mouseY-oldY);
    }
    else if(now==2){///轉動
        angle += (mouseX-oldX);
    }
    else if(now==3){///縮放
        if(mouseX-oldX>0) scale*=1.01;///當滑鼠往右，則放大
        if(mouseX-oldX<0) scale*=0.99;///當滑鼠往左，則縮小
    }
```c++
#include <GL/glut.h>
#include <stdio.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };///z的加負號

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

float x=150,y=150,z=0,scale=1.0,angle=0;
int oldX=0,oldY=0 ,now=1;///1.移動 2.轉動 3.縮放
void display()
{
    glClearColor( 0.8 , 0.8 , 0.8 , 1);///R G B A (A為半透明功能，目前沒有開)
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glTranslatef( (x-150)/150.0 ,-(y-150)/150.0 ,z);
        glRotatef(angle,0,1,0);///對y軸旋轉
        glScalef(scale ,scale,scale);
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void keyboard( unsigned char key,int mouseX,int mouseY)
{
    if( key=='1'||key=='w'||key=='W') now=1;
    if( key=='2'||key=='e'||key=='E') now=2;
    if( key=='3'||key=='r'||key=='R') now=3;
}
void mouse(int botton,int state,int mouseX,int mouseY)
{///為了解決圖會瞬間移動的問題
    oldX=mouseX; oldY=mouseY;
}
void motion(int mouseX,int mouseY)
{
    if(now==1){///移動
        x+=(mouseX-oldX);
        y+=(mouseY-oldY);
    }
    else if(now==2){///轉動
        angle += (mouseX-oldX);
    }
    else if(now==3){///縮放
        if(mouseX-oldX>0) scale*=1.01;///當滑鼠往右，則放大
        if(mouseX-oldX<0) scale*=0.99;///當滑鼠往左，則縮小
    }
    oldX=mouseX;
    oldY=mouseY;
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
}

```
## 第8週
## ◇複習上課範例程式:Light & Material 打光/模型
 1.GLfloat light_ka 調光的範圍。
 2.GLfloat light_kd 可調光的顏色。
 3.GLfloat light_ks 影響高光的部分。

## ◇實作(利用GLUT範例、和放在source的):
```
 1.GLUT程式碼理解: 
    callback會呼叫display()  keyboard()  mouse() motion() 函式、前面有些是前幾次上課教的          (ex:glTranslatef()和glRotatef()等等)
 2.打光的程式碼:打光的陣列 、打光的函式在159~172的程式碼
 3. 複製第6週的light程式碼(會看到打光的黃色茶壺)
```
## ◇將3D模型檔加入，需要source 裡的 glm.h glm.c，用lightmaterial.cpp來學習:
```
 1.加入include "glm.h"在程式碼 。
    並將void display()裡的glutSolidTeapot( 0.3 ); 改成呼叫 drawmodel();///呼叫畫模型
    ☆#include < >引用系統裡的檔
    #include " " 引用同目錄裡的檔☆
 2.加進GLMmodel* pmodel = NULL;     是指向GLMmode模型的指標，NULL代表還沒好。
 3.複製畫3D模型的程式碼 ( pmodel = glmReadOBJ("data/soccerball.obj"); 會去找模型檔案並加     入)
 4.將要用的模型資料夾放進working dir 目錄(在freeglut資料夾的bin裡)，將data資料夾放進去。
 5.將glm.h和glm.c 放進專案的資料夾裡 (glm.c需要改檔名成glm.cpp 才能使用)。

  glm.cpp是讀和畫等等3D模型程式碼(第三步畫圖的程式都在裡面)、glm.h是為了可以用那些方法。
 6.最後專案(weel088 model)按右鍵 add files... ->將glm.cpp加進
 ☆3D模型檔案會有兩個!  .mtl檔是material的縮寫，.obj檔放3D模型的資料(裡面有存v 頂點、vn法向量、f 面)☆
```
```c++
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
```
## 第9週
##  ◇上課範例程式:Texture.exe 貼圖
```
  glTexCoord2f( 0.0 , 0.0); (貼圖左下角是(0 , 0)逆時鐘算頂點，跟頂點的座標位置不一樣)
```
##  ◇實作1:設定好OpenCV
moodle下載opencv 2.1.0 win32 vs2008 (選第二個 add Path，也不要改目錄)
    ☆安裝完Path會多opencv 所以codeblocks要重開 。bin(執行檔)
1.開個空的檔案 
2.寫進程式碼:
```c++
#include <opencv/highgui.h>
int main()
{///Ipl: Intel Perfromance Library
    IplImage * img = cvLoadImage("9.png");///讀圖
    cvShowImage("week09",img);///開個視窗，秀圖
    cvWaitKey( 0 ); ///等待按任意鍵
}
```
3.要設定才能使用 include 目錄 / Lib 目錄 / 方法:

    在右上settings/compiler -> Search directories/Compiler裡add C:\OpenCV2.1\include

        settings/compiler -> Search directories/Linker 裡 add  C:\OpenCV2.1\lib

        settings/compiler -> Linker settings    add cv210、cxcore210、highgui210

        圖檔跟.cpp檔放在一起就能執行
##  ◇實作2:結合OpenCV和OpenGL
1.開一個新的GLUT檔案
2.將之前 茶壺程式碼(openGL) 和 剛剛的openCV程式碼 修改後 結合在一起
```c++
#include <GL/glut.h>
#include <opencv/highgui.h>
void myTexture()///改成void，因為程式碼不能有兩個main
{
    IplImage * img = cvLoadImage("9.png");///讀圖
    cvShowImage("opencv",img);///開個視窗，秀圖
    ///cvWaitKey( 0 ); ///可以不用寫，因為有glutMainLoop();卡住
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glutSolidTeapot( 0.3 );
    glutSwapBuffers();

}
int main(int argc,char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week09");

    glutDisplayFunc(display);
    myTexture();

    glutMainLoop();
}
```
3.此時圖檔要放在freeglut\bin資料夾裡!!!!!
☆此時貼圖並沒有貼在茶壺上!!!☆
4.去老師的網站複製貼圖的程式碼(改掉原本的void mytexture()，在下面的mytexture("圖片檔")):
   https://gist.github.com/jsyeh/5ed01210559721ec71b659b3ffed2dd7
```c++
#include <GL/glut.h>
#include <opencv/highgui.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
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
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glutSolidTeapot( 0.3 );
    glutSwapBuffers();

}
int main(int argc,char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week09");

    glutDisplayFunc(display);
    myTexture("9.png");///圖檔從這讀入

    glutMainLoop();
}

```
## 第10週
## ◇實作背景貼圖:
```
  1.將freeglut資料夾、OpenCV-2.1.0裝好 (需重開codeblocek)。並開一個新的Glut專案。
  2.將OpenCV三個(目錄 / Lib 目錄 / 方法)設定完成。
  3.複製上周最後的程式碼 (texture)、下載一張earth.jpg放到freeglut\bin資料夾。
  4.利用
    glBegin(GL_POLYGON);
       glTexCoord2f( 0 , 1); glVertex2f( -1, -1);  左下，記得貼圖是逆時針座標和頂點不一樣
    glEnd();
    將圖片定位。
```
```c++
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glBegin(GL_POLYGON);
            glTexCoord2f(0,1); glVertex2f(-1,-1);///左下
            glTexCoord2f(1,1); glVertex2f(+1,-1);///右下
            glTexCoord2f(1,0); glVertex2f(+1,+1);///右上
            glTexCoord2f(0,0); glVertex2f(-1,+1);///左上
        glEnd();
    glutSwapBuffers();
}
```
## ◇ 將貼圖貼到圓球:
    1.建立一個新專案。
    2.新增程式碼:
        先設好指標: GLUquadric * sphere = NULL; ///指標，指到二次曲面
        在display函式:
        設貼圖: gluQuadricTexture(sphere,1);///指標,是否開啟
        畫圓: gluSphere(sphere,  1   ,30    ,30);
               分別為指標, 半徑, 直切(似經度),堆疊(似緯度)
        在main裡:
          準備好2次曲面: sphere = gluNewQuadric();
    3.使地球可以旋轉:
        在glPushMartrix();和glPopMartrix(); 之間加入glRotatef(angle, 0 , 0 , 1);
        並設好angle。
        在main函式裡放好:
            glutIdleFunc(display);///有空idle呼叫display
    4.新增: glRotatef(90, 1 , 0 , 0);///把地球轉正，使他能按照赤道旋轉。
       在main裡:glEnable(GL_DEPTH_TEST);///開啟深度功能
```c++
#include <GL/glut.h>
#include <opencv/highgui.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
GLUquadric * sphere = NULL; ///指標，指到二次曲面
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
        glPushMatrix();
            glRotatef(90, 1 , 0 , 0);///把地球轉正，使他能按照赤道旋轉。
            glRotatef(angle, 0 , 0 , 1);
            gluQuadricTexture(sphere,1);///設好貼圖(指標,是否開啟)
            gluSphere(sphere,1,30,30);///畫圓形，gluSphere(指標, 半徑, 直切(似經度),堆疊(似緯度))
        glPopMatrix();
    glutSwapBuffers();
    angle+=1;
}
int main(int argc,char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week10_texture_earth");

    glEnable(GL_DEPTH_TEST);///開啟深度功能
    glutIdleFunc(display);///有空idle呼叫display
    glutDisplayFunc(display);
    myTexture("earth.jpg");///圖檔從這讀入
    sphere = gluNewQuadric();///準備好2次曲面
    glutMainLoop();
}
```
## 第11週
## 上周glm 模型實作
```
1. 將freeglut 弄好、OpenCV2.1 裝好並設定(三個)好、重開codeblock。
2.開GLUT專案。
3.下載好的模型 .zip檔解壓縮後，模型裡data資料夾的檔案放到 freeglut\bin\data裡!
4.寫程式:
```
```c++
#include <opencv/highgui.h>
int main()
{///Ipl: Intel Perfromance Library
    IplImage * img = cvLoadImage("data/Diffuse.jpg");///讀圖
    cvShowImage("week11",img);///開個視窗，秀圖
    cvWaitKey( 0 ); ///等待按任意鍵
}
```
# 把圖貼到茶壺上:
(上半)複製老師的myTexture.cpp程式，(下半)複製上周week10_texture_backgound的display和main，並把圖檔改為 data/Diffuse.jpg
```c++
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
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
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glutSolidTeapot( 0.3 );
    glutSwapBuffers();

}
int main(int argc,char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week11_Gundam");

    glutDisplayFunc(display);
    myTexture("data/Diffuse.jpg");///圖檔從這讀入

    glutMainLoop();
}
```
# 將gundam模型讀進去:
```
 1.去 jsyeh.org/3dcg10 下載source.zip 用glm.h、glm.c、transformation.c 
       將glm.c改檔名為glm.cpp，將glm.cpp 、transformation.c 和glm.h放到 專案資料夾(main旁)。
 2.到codeblock→點專案右鍵 Add File 加入 glm.cpp(為了include)
 3.加入#include "glm.h" 、GLMmodel * pmodel =NULL; (設定目前模型是沒有的)。和改display裡的程式
★" "指在專案目錄。< >在系統找★
 4.將貼圖位置貼好! 直接點Diffuse圖檔 進小畫家 進行上下反轉。
```
```c++
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        if(pmodel == NULL){
            pmodel = glmReadOBJ("data/Gundam.obj");///讀進模型
            glmUnitize( pmodel );///換算成unit單位大小(-1~+1)
            glmFacetNormals( pmodel );///重新計算模型每個面的法向量
            glmVertexNormals( pmodel, 90);///重新計算模型Vertex的法向量
        }
        glmDraw(pmodel,GLM_TEXTURE);///模型上畫貼圖
    glutSwapBuffers();
}
```
# 將3D模型的深度功能打開:
```
1. 在main函式 glutMainLoop() 之前，加上glEnable(GL_DEPTH_TEST); 開啟3D深度。
2.讓他轉起來:設定angle變數，在display加上glPushMatrix、glRotatef、glmDraw、glPopMatrix並angle要+1。重要的是要在main加glutIdleFunc(display);//使他一定時間呼叫display。
```
```c++
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
```
# 運用MAYA切割模型:
```
1.進入MAYA，設定好輸出(影片有教學)，讀進模型，選取你要的部位，save as →點obj檔模式儲存。
   搜尋maya obj 檔案影片→https://www.youtube.com/watch?v=D4a7cNFF9kQ
2.切割完後，放進一樣放進freeglut\bin\data，再分別讀進身體部分，Push/Pop移動轉動之後就能動了。
```
# 對特定軸旋轉:
```
1.建好 身體 跟 手 的部分。(目前用teapot做示範)
2.在display 把body跟hand 顯示，並設好 glTranslatef、glRotatef、angle。
3.在main裡加上glutIdleFunc(display);
```
```c++
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
```
## 第12周
# ◇Transformation.exe範例:
```
 1. 在下方Command manipulation window視窗右鍵可以swap 移動(translate)跟轉動(rotate)。
 2.自轉:(由下往上讀程式碼)
  glTranslatef先時，是模型整個被移動; 
  glRotatef，會是車子中心軸轉。
  glScalef和glbegin建好一台車子。
 3.公轉:(由下往上讀程式碼)
   glRotatef先時，是車子繞中心軸旋轉。
   glTranslatef，是模型整個被移動(想像他被移到大盤子右邊);
   glScalef和glbegin建好一台車子。
```
```c++

```
# ◇其他範例:
```
1. 到120.125.80.50/GL/ 網站看T-R-T對特定軸轉動練習
2.左邊畫面畫完，右邊myDrawObject會增加 並且 它可以換位置(似圖層意思)
  可以重新整理網頁清除剛剛的操作。
3.angle點一下再按空白鍵，就能改變值。
  將 物件(myDrawObject) 和 移動(Translate) 放在 旋轉glRotate下方就能轉。
  上方程式會影響下方的程式碼，所以才要放在下方。
4.點Translatef變紅色後，再到左邊的視窗就能拖移位置。(可讓中心軸移動)
  glPushMatrix(x,y,z);
     glRotatef(angle,0,0,1); //會使下面整個的東西選轉。       
     glTranslatef(-x,-y,0) //往左下角移動後，會是中心點。(其中一個)
     myDrawObject(1); //物件
  glPopMatrix();
5.把另外一個glTranslatef()擺到 第4點 glRotatef()上面。  
```
```c++
   glPushMatrix();
      glTranslatef(x,y,z);//會讓物體移到這個位置
      glRotatef(angle,0,0,1); //會使下面整個的東西選轉。       
      glTranslatef(x,y,z); //使它成為物體的旋轉中心點!
      myDrawObject(1); //物件
   glPopMatrix();  
```
# ◇實作:
```
1.先開一個GLUT專案
2.貼完三段程式碼!
3.新增一個身體跟手茶壺，並修改 手的 旋轉中心點 跟 位置。(可一步一步來比較好理解)
   glTranslatef(0.4,0.15,0); /// (3).把它往右放(圖的綠色線條)
   glRotatef(angle,0,0,1); /// (2).旋轉
   glTranslatef(0.2,0,0); /// (1).旋轉中心放到世界中心，希望 手茶壺的中心旋轉軸 在把手位置，因大小是0.2，才往右0.2。(原本在橘色點，要移到粉紅色點)
```
```c++
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

```
# ◇可運用到作業的程式:
```c++
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

```
# ◇:
```

```
# ◇:
```

```
# ◇:
```

```
