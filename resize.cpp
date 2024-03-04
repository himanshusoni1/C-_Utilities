#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Global variables
Mat originalImage;

// Function to update the resized image (for increasing size)
void updateIncreaseSize(int trackbarIncrease, void*) {
    double scaleFactor = 1 + (double)trackbarIncrease / 100.0;
    Mat resizeImage;
    resize(originalImage, resizeImage, Size(), scaleFactor, scaleFactor, INTER_LINEAR);
    imshow("Resized Image", resizeImage);
}

// Function to update the resized image (for decreasing size)
void updateDecreaseSize(int trackbarDecrease, void*) {
    double scaleFactor = 1 - (double)trackbarDecrease / 100.0;
    Mat resizeImage;
    resize(originalImage, resizeImage, Size(), scaleFactor, scaleFactor, INTER_LINEAR);
    imshow("Resized Image", resizeImage);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <image_path>" << endl;
        return 1;
    }

    // Load the original image
    originalImage = imread(argv[1]);
    if (originalImage.empty()) {
        cout << "Could not open or find the image" << endl;
        return 1;
    }

    // Create a window
    namedWindow("Resized Image");

    // Create trackbars for increasing and decreasing size
    int trackbarIncrease = 0; // Initial value for increasing size
    int trackbarDecrease = 0; // Initial value for decreasing size
    int maxTrackbarSize = 100; // Maximum value for trackbar
    createTrackbar("Increase", "Resized Image", &trackbarIncrease, maxTrackbarSize, updateIncreaseSize);
    createTrackbar("Decrease", "Resized Image", &trackbarDecrease, maxTrackbarSize, updateDecreaseSize);

    // Show the resized image initially
    updateIncreaseSize(trackbarIncrease, nullptr);

    // Wait for a key press
    waitKey(0);

    return 0;
}
