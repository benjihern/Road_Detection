#ifndef MEMORY_H
#define MEMORY_H

#include <systemc>
#include <opencv2/opencv.hpp>

using namespace cv;

class memory : public sc_core::sc_interface {
public:
	virtual void write(const Mat& data) = 0;
	virtual Mat read() const = 0;
	virtual bool is_updated() const = 0;
};

class memory_channel : public memory {
private:
	Mat m_buffer;
	bool m_updated;

public:
	memory_channel() : m_updated(false) {}

	void write(const Mat& data) override {
		m_buffer = data.clone();
		m_updated = true;
	}

	Mat read() const override {
		return m_buffer.clone();
	}

	bool is_updated() const override {
		return m_updated;
	}

	void reset_updated() {
		m_updated = false;
	}
};

#endif
