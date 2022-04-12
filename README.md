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
 1.GLUT程式碼理解: 

    callback會呼叫display()  keyboard()  mouse() motion() 函式、前面有些是前幾次上課教的          (ex:glTranslatef()和glRotatef()等等)
 2.打光的程式碼:打光的陣列 、打光的函式在159~172的程式碼
 3. 複製第6週的light程式碼(會看到打光的黃色茶壺)
## ◇將3D模型檔加入，需要source 裡的 glm.h glm.c，用lightmaterial.cpp來學習:
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
## 

```c++

```
