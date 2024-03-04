#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<stdlib.h>
using namespace cv;
using namespace std;
int main(int argc,char *argv[]){
if(argc!=4){
cout<<"usage :: resize_image imagefile.jpg/png width height]"<<endl;
return 0;
}
Mat m= imread(argv[1]);
int width= atoi(argv[2]);
int height= atoi(argv[3]);
Mat resizeImage;
resize(m,resizeImage,Size(width,height),INTER_LINEAR);
imshow("image proc. st. 1.0", resizeImage);
waitKey(0);
return 0;
}