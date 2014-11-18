#include "sched_fifo.h"

#include <iostream>

Sched_FIFO sched_fifo_obj;

Sched_FIFO::Sched_FIFO() : Scheduler("sched_fifo") {}

void Sched_FIFO::start_to_queue(){
    std::cout << __func__ << std::endl;
}

void Sched_FIFO::cpu_to_queue(){
    std::cout << __func__ << std::endl;
}

void Sched_FIFO::cpu_to_io(){
    std::cout << __func__ << std::endl;
}

void Sched_FIFO::cpu_to_end(){
    std::cout << __func__ << std::endl;
}

void Sched_FIFO::io_to_queue(){
    std::cout << __func__ << std::endl;
}

