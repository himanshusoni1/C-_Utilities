#include<opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<stdlib.h>
using namespace cv;
using namespace std;

int main(int argc,char *argv[]){
if(argc!=3){
cout<<"usage : resize_image2 filename.jpg/png percentage%"<<endl;
return 0;
}
int percentage=atoi(argv[2]);
Mat m=imread(argv[1]);
int width=(m.cols*percentage)/100;
int height=(m.rows*percentage)/100;
Mat resizedimage;
resize(m,resizedimage,Size(width,height),INTER_LINEAR);
imshow("image proc. stu. 1.0", resizedimage);
waitKey(0);
return 0;
}