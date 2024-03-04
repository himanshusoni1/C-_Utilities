#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<stdlib.h>
using namespace cv;
using namespace std;
int main(int argc,char *argv[]){
if(argc!=4){
cout<<"usage : blur_image filename.jpg/png kernel_size(1-50) target_folder.jpg/png"<<endl;
}
int kernelSize=atoi(argv[2]);
Mat m;
m=imread(argv[1],IMREAD_COLOR);
imwrite(argv[3],m);
Mat blurImage;
//apply blur filter
blur(m,blurImage,Size(kernelSize,kernelSize));
imshow("ImageViewer 1.0",blurImage);
waitKey(0);
return 0;
}