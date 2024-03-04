#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Usage: [imageviewer file_name.jpg/png]" << endl;
        return 1; // Return 1 to indicate an error
    }

    // Load the image
    Mat img = imread(argv[1], IMREAD_COLOR);

    // Check if the image was loaded successfully
    if (img.empty()) {
        cout << "Could not open or find the image" << endl;
        return 1; // Return 1 to indicate an error
    }

    // Check if the image has a valid size
    if (img.cols <= 0 || img.rows <= 0) {
        cout << "Invalid image size" << endl;
        return 1; // Return 1 to indicate an error
    }

    // Display the image
    imshow("ImageViewer - 1.0", img);
    waitKey(0);

    return 0;
}
