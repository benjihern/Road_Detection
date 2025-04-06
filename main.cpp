#include <systemc>
#include "initiator.h"
#include "target.h"
#include "memory.h"

SC_MODULE(Top) {
    Initiator* initiator;
    Target* target;
    memory_channel shared_memory;

    SC_CTOR(Top) {
        initiator = new Initiator("Initiator");
        target = new Target("Target");

        initiator->mem_port(shared_memory);
        target->mem_port(shared_memory);
    }

    ~Top() {
        delete initiator;
        delete target;
    }
};

int sc_main(int argc, char* argv[]) {
    Top top("Top");
    sc_core::sc_start();
    return 0;
}

