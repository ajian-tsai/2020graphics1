#include <opencv/highgui.h>
int main()
{///Ipl: Intel Perfromance Library
    IplImage * img = cvLoadImage("9.png");///讀圖
    cvShowImage("week09",img);///開個視窗，秀圖
    cvWaitKey( 0 ); ///等待按任意鍵
}
