#include "initiator.h"
#include <opencv2/opencv.hpp>

void Initiator::send_image() {
    Mat img = imread("road.jpg");
    if (img.empty()) {
        std::cerr << "Failed to load input.jpg" << std::endl;
        sc_core::sc_stop();
        return;
    }
    wait(5, sc_core::SC_NS);
    mem_port->write(img);
}
