#include "sched_fifo.h"

#include <iostream>

Sched_FIFO sched_fifo_obj;

Sched_FIFO::Sched_FIFO() : Scheduler("sched_fifo") {}

void Sched_FIFO::start(ProcList p){
    std::cout << __func__ << std::endl;

    for(auto& i : p){
        q.push(i);
    }

    manager->sendToCPU(q.front());
}

void Sched_FIFO::start_to_queue(ProcPtr p){
    std::cout << __func__ << std::endl;

    q.push(p);
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

