#ifndef INITIATOR_H
#define INITIATOR_H

#include <systemc>
#include "memory.h"

SC_MODULE(Initiator) {
   sc_core::sc_port<memory> mem_port;

    void send_image();

    SC_CTOR(Initiator) {
        SC_THREAD(send_image);
    }
};

#endif
