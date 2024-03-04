#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

// Global variables
int fontSize = 20;
Scalar color = Scalar(255, 0, 0); // Default color
int fontweight = 3;
Mat image;

// Mouse callback function
void mouseCallback(int event, int x, int y, int flags, void* userdata) {
    if (event == EVENT_MOUSEWHEEL) {
        if (flags > 0) {
            // Scroll up, increase font size
            fontSize += 5;
        } else {
            // Scroll down, decrease font size
            fontSize = max(5, fontSize - 5); // Ensure fontSize does not become negative
        }

        // Update font size display
        Mat fontDisplay = Mat::zeros(50, 200, CV_8UC3); // Create a black image to display font size
        putText(fontDisplay, "Font Size: " + to_string(fontSize), Point(10, 30), FONT_HERSHEY_SIMPLEX, 0.8, Scalar(255, 255, 255), 2);
        imshow("Font Size Display", fontDisplay);

        // Add text with updated font size
        Mat tempImage = image.clone();
        putText(tempImage, "Sample Text", Point(20, 50), FONT_HERSHEY_SIMPLEX, fontSize, color, fontweight);
        imshow("image proc. st. 1.0", tempImage);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "usage: [add_text image.jpg/png]" << endl;
        return 0;
    }

    image = imread(argv[1], IMREAD_COLOR);
    if (image.empty()) {
        cout << "unable to load " << argv[1] << endl;
        return 0;
    }

    // Create a window to display font size
    namedWindow("Font Size Display");
    moveWindow("Font Size Display", 20, 20);

    // Update font size display
    Mat fontDisplay = Mat::zeros(50, 200, CV_8UC3); // Create a black image to display font size
    putText(fontDisplay, "Font Size: " + to_string(fontSize), Point(10, 30), FONT_HERSHEY_SIMPLEX, 0.8, Scalar(255, 255, 255), 2);
    imshow("Font Size Display", fontDisplay);

    // Create window for the image
    namedWindow("image proc. st. 1.0");
    moveWindow("image proc. st. 1.0", 20, 100);

    setMouseCallback("image proc. st. 1.0", mouseCallback);

    putText(image, "Sample Text", Point(20, 50), FONT_HERSHEY_SIMPLEX, fontSize, color, fontweight);
    imshow("image proc. st. 1.0", image);
    waitKey(0);

    return 0;
}
