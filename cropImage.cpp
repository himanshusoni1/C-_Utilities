#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

// Global variables
bool selecting = false;
Rect selection;
Mat image;

// Mouse callback function
void mouseCallback(int event, int x, int y, int flags, void* userdata) {
    switch (event) {
        case EVENT_LBUTTONDOWN:
            selecting = true;
            selection.x = x;
            selection.y = y;
            break;
        case EVENT_MOUSEMOVE:
            if (selecting) {
                selection.width = x - selection.x;
                selection.height = y - selection.y;
                Mat tempImage = image.clone();
                rectangle(tempImage, selection, Scalar(0, 255, 0), 2);
                imshow("Select Region", tempImage);
            }
            break;
        case EVENT_LBUTTONUP:
            selecting = false;
            selection.width = x - selection.x;
            selection.height = y - selection.y;
            if (selection.width > 0 && selection.height > 0) {
                Mat croppedImage = image(selection);
                imshow("Cropped Image", croppedImage);
                waitKey(0);
            }
            break;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        cout << "usage: crop_image filename.jpg/png" << endl;
        return 0;
    }

    // Load the image
    image = imread(argv[1]);
    if (image.empty()) {
        cout << "Could not open or find the image" << endl;
        return 0;
    }

    // Create a window and set the mouse callback function
    namedWindow("Select Region");
    setMouseCallback("Select Region", mouseCallback);

    // Display the image
    imshow("Select Region", image);
    waitKey(0);

    return 0;
}
