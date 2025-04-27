# Road Line Detection Using SystemC and OpenCV

## Overview 
This project implements a line detection application focused on identifying road lane markers in images using OpenCV and SystemC integration.
A dual-processor system model is created where image acquisition and processing are partitioned between an initiator and a target module at the transaction level.

The goal is to detect road lines while minimizing false positives outside the road boundary, leveraging OpenCV’s probabilistic Hough transform and edge detection techniques.



## Features
- Integration of OpenCV with SystemC for hardware-accelerated image processing
- Two-processor system modeling with transaction-level communication
- Temporary memory buffer implementation for efficient data transfer
- Accurate road lane detection and visualization
- Minimal false-positive detection outside of the road

## Project Architecture
- **Processor 1 (Initiator)**
  - Reads input image using OpenCV.
  - Transfers image data to memory buffer.

- **Memory Module**
  - Acts as an intermediary temporary storage using SystemC TLM protocols.

- **Processor 2 (Target)**
  - Fetches image data from memory.
  - Applies OpenCV processing (grayscale conversion, edge detection, line detection).
  - Outputs final image with detected road lines overlaid.

## Development Tools
- SystemC for processor and memory system modeling
- OpenCV for image processing (edge and line detection)
- C++ for system development and integration
- G++ and CMake (Linux) for compilation

Input Image
![road](https://github.com/user-attachments/assets/0eb2da5c-673d-4fe0-9665-8a025c7683c3)


Output: Detected Road Lines
![output](https://github.com/user-attachments/assets/eff1291f-d865-499f-b53e-9fe4633d9594)
