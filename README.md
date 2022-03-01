# 2020graphics1
# week01


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
