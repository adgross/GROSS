#include "scheduler.h"

decltype(Scheduler::schedulers) Scheduler::schedulers{};

Scheduler::Scheduler(const std::string&& name) : Scheduler(name) {}
Scheduler::Scheduler(const std::string& name) : sched_name(name) {
    schedulers.insert({name, this});
}
Scheduler::~Scheduler(){
    schedulers.erase(sched_name);
}


Scheduler* Scheduler::getInstance(const std::string& sched_name){
    auto sched = schedulers.find(sched_name);
    if(sched != schedulers.end()) {
        return sched->second;
    }
    else {
        std::string what = "O escalonador '" + sched_name + "' nao existe ou nao foi instanciado";
        throw std::invalid_argument {what};
    }
}
