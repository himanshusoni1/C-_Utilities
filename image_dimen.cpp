#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;
int main(int argc,char *argv[]){
if(argc!=2){
cout<<"usage  ::  image_dimen filename.jpg/png"<<endl;
return 0;
}
Mat m;
m = imread(argv[1],IMREAD_COLOR);
int width=m.cols;
int height=m.rows;
cout<<"Dimensions of "<<argv[1]<<" are as folows"<<endl;
cout<<"width : "<<width<<" pixels"<<endl;
cout<<"height : "<<height<<" pixels"<<endl;
return 0;
}