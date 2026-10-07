#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include <opencv2/core.hpp>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
using namespace cv;
using namespace std;

#ifdef _DEBUG
#pragma comment(lib,"opencv_world490d.lib")
#else
#pragma comment(lib,"opencv_world490.lib")
#endif

int main() {
    vector<string> imagePaths = { "C:/Users/choij/Desktop/allcoins/coins0.jpg", "C:/Users/choij/Desktop/allcoins/coins1.jpg",
                                  "C:/Users/choij/Desktop/allcoins/coins2.jpg", "C:/Users/choij/Desktop/allcoins/coins3.jpg",
                                  "C:/Users/choij/Desktop/allcoins/coins4.jpg", "C:/Users/choij/Desktop/allcoins/coins5.jpg" };    

    for (int i = 0; i < imagePaths.size(); i++) {       
        Mat img = imread(imagePaths[i], IMREAD_COLOR);
        if (img.empty()) {
            cout << "Could not open or find the image: " << imagePaths[i] << endl;
            continue; 
        }

        Mat gray;
        cvtColor(img, gray, COLOR_BGR2GRAY);
        
        GaussianBlur(gray, gray, Size(9, 9), 2, 2);
        
        vector<Vec3f> circles;
        HoughCircles(gray, circles, HOUGH_GRADIENT, 1.3, 70, 130, 60, 25, 80);
       
        cout << "Image " << (i + 1) << " - Detected coins: " << circles.size() << endl;

        for (size_t j = 0; j < circles.size(); j++) {
            Point center(cvRound(circles[j][0]), cvRound(circles[j][1]));
            int radius = cvRound(circles[j][2]);
          
            circle(img, center, 3, Scalar(0, 255, 0), -1, 8, 0);          
            circle(img, center, radius, Scalar(0, 0, 255), 3, 8, 0);
        }
      
        string windowName = "Detected Coins - Image " + to_string(i + 1);
        namedWindow(windowName, WINDOW_AUTOSIZE);
        imshow(windowName, img);
    }

    waitKey(0); 
    return 0;
}
