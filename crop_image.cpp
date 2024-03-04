#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
using namespace cv;
int main(int argc,char *argv[]){
if(argc!=4){
cout<<"usage : crop_image filename.jpg/png width height"<<endl;
return 0;
}
int width = atoi(argv[2]);
int height = atoi(argv[3]);

Mat m;
m=imread(argv[1]);
int centerX=m.cols/2;
int centerY=m.rows/2;
int topx=centerX-(width/2);
int topy=centerY-(height/2);
if(topx<0)topx=0;
if(topy<0)topy=0;
if(topx+width>=m.cols){
cout<<"invalid height"<<endl;
return 0;
}
Rect r;
r.x=topx;
r.y=topy;
r.width=width;
r.height=height;
Mat cropedImage = m(r);
imshow("image proc. st. 1.0",cropedImage);
waitKey(0);
return 0;
}