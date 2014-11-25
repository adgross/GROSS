#include "scheduler.h"
#include <algorithm>
#include <stdexcept>

decltype(Scheduler::schedulers) Scheduler::schedulers{};

Scheduler::Scheduler(const std::string&& name) : Scheduler(name) {}
Scheduler::Scheduler(const std::string& name) : sched_name(name) {
    if(schedulers.count(name) != 0){
        throw std::logic_error("The scheduler '" + name + "' already have an instance");
    }
    if( std::any_of(name.begin(), name.end(), [](char i){return std::isspace(i);}) ){
        throw std::logic_error("The scheduler name '" + name + "' is invalid: Should not contain spaces");
    }

    schedulers.insert({name, *this});
}
Scheduler::~Scheduler(){
    schedulers.erase(sched_name);
}

Scheduler& Scheduler::getInstance(const std::string&& sched_name){
    return Scheduler::getInstance(sched_name);
}
Scheduler& Scheduler::getInstance(const std::string& sched_name){
    auto sched = schedulers.find(sched_name);
    if(sched != schedulers.end()) {
        return sched->second;
    }
    else {
        throw std::invalid_argument {"The scheduler '" + sched_name + "' does not exist or does not have an instance"};
    }
}

void Scheduler::setManager(std::shared_ptr<Manager> m){
    manager = m;
}
