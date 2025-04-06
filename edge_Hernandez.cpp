#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main() {

	Mat src = imread("coins.jpg", IMREAD_COLOR);

	Mat gray;
	cvtColor(src, gray, COLOR_BGR2GRAY);

	Mat blurred;
	GaussianBlur(gray, blurred, Size(5,5), 1.5);

	Mat edges;
	double low = 30;
	double high = 100;
	Canny(blurred, edges, low, high);

	imwrite("outImage_Hernandez.jpg", edges);

}
