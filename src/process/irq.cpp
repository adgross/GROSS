#include "irq.h"

IRQ::IRQ(ProcPtr p) : process(p) {}

bool IRQ::isIRQ(){
    return true;
}

ProcPtr IRQ::get_process(){
    return process;
}
