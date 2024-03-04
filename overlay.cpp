#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char *argv[]) {
    if (argc != 5) {
        cout << "usage : overlay_image background_image.jpg/png overlay_image.jpg/png topx topy" << endl;
        return 0;
    }

    // Read background image
    Mat background = imread(argv[1], IMREAD_COLOR);
    if (background.empty()) {
        cout << "Unable to load background image: " << argv[1] << endl;
        return 0;
    }

    // Read overlay image
    Mat overlay = imread(argv[2], IMREAD_COLOR);
    if (overlay.empty()) {
        cout << "Unable to load overlay image: " << argv[2] << endl;
        return 0;
    }

    // Convert overlay image to the same depth as the background
    overlay.convertTo(overlay, background.type());

    // Get position from command line arguments
    int topx = atoi(argv[3]);
    int topy = atoi(argv[4]);

    // Resize overlay image to fit the background region
    resize(overlay, overlay, Size(background.cols - topx, background.rows - topy));

    // Create a region of interest (ROI) for placing overlay on background
    Rect roi(topx, topy, overlay.cols, overlay.rows);

    // Check if the ROI is within the background image
    if (roi.x < 0 || roi.y < 0 || roi.x + roi.width > background.cols || roi.y + roi.height > background.rows) {
        cout << "Overlay image exceeds background bounds." << endl;
        return 0;
    }

    // Place the overlay on the background
    Mat overlayRegion = background(roi);
    overlay.copyTo(overlayRegion);

    // Display the result
    imshow("Overlayed Image", background);
    waitKey(0);

    return 0;
}
