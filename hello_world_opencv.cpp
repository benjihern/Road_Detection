#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/types_c.h"

using namespace cv;

int main(int argc, char** argv) {
	Mat output = imread("cat.jpeg");
	putText(output,
		"Hello",
		cvPoint(15, 70),
		FONT_HERSHEY_PLAIN,
		3,
		cvScalar(0, 255, 0),
		4);

	//std::cout << output << std::endl;

	imwrite("hello_world.jpg", output);

	return 0;
}
