#include <opencv2/highgui.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main( int argc, char** argv )
{
    Mat image;
    image = imread("Lena.png",IMREAD_COLOR);
  
    namedWindow("n1", WINDOW_AUTOSIZE);
    imshow("n1", image);
    cv::waitKey(0);
    return 0;
}
