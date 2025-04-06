#include "target.h"
#include <opencv2/opencv.hpp>

using namespace cv;

void Target::process_image() {
    wait(10, sc_core::SC_NS);

    Mat img = mem_port->read();

    Mat gray, blurred, edges, mask, maskedEdges;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    GaussianBlur(gray, blurred, cv::Size(5, 5), 0);
    Canny(blurred, edges, 50, 150);

    mask = Mat::zeros(edges.size(), edges.type());

    int height = edges.rows;
    int width = edges.cols;

    Point pts[1][4] = {
        {Point(width*0.05, height),
         Point(width*0.95, height),
         Point(width*0.65, height*0.5),
         Point(width*0.35, height*0.5)}
    };

    const Point* ppt[1] = {pts[0]};
    int npt[] = {4};
    fillPoly(mask, ppt, npt, 1, cv::Scalar(255));
    bitwise_and(edges, mask, maskedEdges);

    //maskedEdges = edges.clone();

    imwrite("mask.jpg", mask);
    imwrite("edges.jpg", edges);
    imwrite("masked.jpg", maskedEdges);

    std::vector<Vec4i> lines;
    HoughLinesP(maskedEdges, lines, 1, CV_PI / 180, 50, 5, 10);

    Mat output = img.clone();
    for (const auto& l : lines) {
       line(output, Point(l[0], l[1]), Point(l[2], l[3]),
                 Scalar(0, 0, 255), 2);
    }

    imwrite("output.jpg", output);
}
