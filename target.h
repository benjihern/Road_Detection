#ifndef TARGET_H
#define TARGET_H

#include <systemc>
#include "memory.h"

SC_MODULE(Target) {
    sc_core::sc_port<memory> mem_port;

    void process_image();

    SC_CTOR(Target) {
        SC_THREAD(process_image);
    }
};

#endif
