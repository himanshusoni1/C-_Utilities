#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Global variables
int kernelSize = 1;
Mat originalImage;

// Function to update the blur image
void updateBlurImage(int, void*) {
    Mat blurImage;
    // Apply blur filter
    blur(originalImage, blurImage, Size(kernelSize, kernelSize));
    imshow("Blur Image", blurImage);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "usage : blur_image filename.jpg/png kernel_size(1-50)" << endl;
        return 1;
    }

    kernelSize = atoi(argv[2]);
    if (kernelSize < 1 || kernelSize > 50) {
        cout << "Kernel size must be in the range 1-50" << endl;
        return 1;
    }

    // Load the original image
    originalImage = imread(argv[1], IMREAD_COLOR);

    // Check if the image is loaded successfully
    if (originalImage.empty()) {
        cout << "Could not open or find the image" << endl;
        return 1;
    }

    // Create a window
    namedWindow("Blur Image");

    // Create a trackbar
    createTrackbar("Bluriness", "Blur Image", &kernelSize, 50, updateBlurImage);
    
    // Set custom trackbar color
    Scalar trackbarColor(0, 255, 0); // Green color

    // Set custom initial position for the trackbar
    setTrackbarPos("Bluriness", "Blur Image", kernelSize);

    // Show the blur image initially
    updateBlurImage(0, 0);

    // Wait for a key press
    waitKey(0);

    return 0;
}
