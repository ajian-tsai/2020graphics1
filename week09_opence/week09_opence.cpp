#include <opencv/highgui.h>
int main()
{///Ipl: Intel Perfromance Library
    IplImage * img = cvLoadImage("9.png");///Ū��
    cvShowImage("week09",img);///�}�ӵ����A�q��
    cvWaitKey( 0 ); ///���ݫ����N��
}
