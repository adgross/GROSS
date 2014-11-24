#include "sched_roundrobin.h"

Sched_RoundRobin sched_roundrobin_obj;

Sched_RoundRobin::Sched_RoundRobin() : Scheduler("sched_roundrobin") {}

void Sched_RoundRobin::setup(std::vector<ProcPtr> const&  p){
    for(auto& i : p){
        q.push(i);
    }
}

void Sched_RoundRobin::update(){
    if(manager->isCPUEmpty()){
        ProcPtr p = next();
        if(p != nullptr){
            manager->sendToCPU(p);
            return;
        } else{
            return;
        }
    }

    if(q.front()->get_time_exec() == 5){
        manager->contextSwitch();
        frontToBack();
        ProcPtr p = next();
        manager->sendToCPU(p);
    }
}

ProcPtr Sched_RoundRobin::next(){
    unsigned long i=0;
    while(i<q.size()){
        if(q.front()->getState() == READY){
            return q.front();
        } else if(q.front()->getState() == DESTROYED){
            q.pop();
            continue;
        } else {
            frontToBack();
            i++;
        }
    }
    return nullptr;
}

void Sched_RoundRobin::frontToBack(){
    q.push(q.front());
    q.pop();
}
