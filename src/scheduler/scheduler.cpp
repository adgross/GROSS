#include "scheduler.h"

decltype(Scheduler::schedulers) Scheduler::schedulers{};

Scheduler::Scheduler(const std::string&& name) : Scheduler(name) {}
Scheduler::Scheduler(const std::string& name) : sched_name(name) {
    if(schedulers.count(name) != 0){
        throw std::logic_error("O escalonador '" + name + "' ja foi instanciado");
    }
    schedulers.insert({name, this});
}
Scheduler::~Scheduler(){
    schedulers.erase(sched_name);
}

Scheduler* Scheduler::getInstance(const std::string&& sched_name){
    return Scheduler::getInstance(sched_name);
}
Scheduler* Scheduler::getInstance(const std::string& sched_name){
    auto sched = schedulers.find(sched_name);
    if(sched != schedulers.end()) {
        return sched->second;
    }
    else {
        throw std::invalid_argument {"O escalonador '" + sched_name + "' nao existe ou nao foi instanciado"};
    }
}
