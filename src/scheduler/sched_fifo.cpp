#include "sched_fifo.h"

Sched_FIFO sched_fifo_obj;

Sched_FIFO::Sched_FIFO() : Scheduler("sched_fifo") {}

void Sched_FIFO::setup(std::vector<ProcPtr> const&  p){
    for(auto& i : p){
        q.push(i);
    }
}

void Sched_FIFO::update(){
    ProcPtr p = next();

    if(p->getState() == READY && manager->isCPUEmpty()){
        manager->sendToCPU(p);
    }
}

ProcPtr Sched_FIFO::next(){
    if(!q.empty()){
        if(q.front()->getState() == DESTROYED){
            q.pop();
            return next();
        } else {
            return q.front();
        }
    } else {             // simulation should finish before reach here,
        return nullptr;  // because update() is never called if all processes are DESTROYED,
    }                    // so 'q' is never empty, because only DESTROYED processes are removed from 'q'
}
