#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<stdlib.h>
using namespace std;
using namespace cv;
int main(int argc,char *argv[]){
if(argc!=5){
cout<<"usage : overlay_image image.jpg/png overlay_image.jpg/png topx topy"<<endl;
return 0;
}
int topx=atoi(argv[3]);
int topy=atoi(argv[4]);
Mat m = imread(argv[1],IMREAD_COLOR);
if(!m.data){
cout<<"unable to load "<<argv[1]<<endl;
return 0;
} 
Mat overlay = imread(argv[2],IMREAD_COLOR);
if(!overlay.data){
cout<<"unable to load "<<argv[2]<<endl;
}
if(topx<0 || topx>=m.cols){
cout<<"invalid x"<<endl;
return 0;
}
if(topy<0 || topy>=m.rows){
cout<<"invalid y"<<endl;
return 0;
}
if(topx+overlay.cols>=m.cols){
cout<<"invalid topx,overflows"<<endl;
return 0;
}
if(topy+overlay.rows>=m.rows){
cout<<"invalid topy,overflows"<<endl;
return 0;
}
Mat portion=m(Rect(topx,topy,overlay.cols,overlay.rows));
overlay.copyTo(portion);
imshow("Image proc. st. 1.0",m);
waitKey(0);
return 0;
}