#include "manager.h"
#include <stdexcept>
#include <map>
#include <limits>
#include <sstream>

Manager::Manager(Scheduler& sched) : scheduler(sched) {}

void Manager::fail(std::string what){
    throw std::runtime_error(what);
}

void Manager::addProcess(ProcPtr p){
    if(running){
        fail("Is not allowed to add new processes after starting the simulation");
    }

    process_list.push_back(p);
}

void Manager::start(){
    if(running){
        return;
    }

    if(process_list.size() == 0){
        fail("No process to execute");
    }

    running = true;
    scheduler.setup(process_list);

    while(running){
        nextClock();
    }
}

void Manager::nextClock(){
    scheduler.update();
    updateTimers();
    doIO();
    cpu.execute();
    running = checkRunning();
    didContextSwitch = false;
}

std::string Manager::generateReport(){
    if(running){
        fail("Should not generate reports while the simulation is running");
    }

    std::stringstream ss;
    std::map<process_state, std::string> state_to_string{ {READY, "READY"},
                                                          {RUNNING, "RUNNING"},
                                                          {BLOCKED, "BLOCKED"},
                                                          {DESTROYED, "DESTROYED"} };

    ss << "Total Simulation Time: " << time_elapsed << std::endl;
    ss << "CPU Idle Time: " << cpu.time_idle << std::endl;
    ss << "CPU Not Idle Time: " << cpu.time_not_idle << std::endl;
    ss << "Context Switches: " << contextSwitches << std::endl;
    ss << std::endl;

    for(auto& p : process_list){
        ss << "Process " << p->PID << " [" << p->program.getName() << "]" << std::endl;
        ss << "  Time Waiting = " << p->time_total_queue << std::endl;
        ss << "  Time Running = " << p->time_total_exec << std::endl;
        ss << "  Time Blocked = " << p->time_total_io << std::endl;
        ss << "  Life Span = " << p->time_total << std::endl;
        ss << "  State = " << state_to_string[p->state] << std::endl;
    }

    return ss.str();
}

void Manager::doIO(){
    for(auto& p : process_list){
        if(p->state == BLOCKED){
            cpu.ioExecute(p);
        }
    }
}

void Manager::updateTimers(){
    time_elapsed++;
    for(auto& p : process_list){
        if(p->state == READY){
            p->time_queue++;
            p->time_total_queue++;
        }

        if(p->state != DESTROYED){
            p->time_total++;
        }
    }
}

bool Manager::checkRunning(){
    if(running == false) // callFinish
        return false;

    if(time_elapsed == std::numeric_limits<size_t>::max()){
        return false;
    }

    for(auto& p : process_list){
        if(p->state != DESTROYED)
            return true;
    }
    return false;
}

void Manager::callFinish(){
    running = false;
}


void Manager::sendToCPU(ProcPtr p){
    if(p==nullptr || p->PID >= process_list.size()){
        fail("sendToCPU called with invalid process");
    }

    if(!isCPUEmpty()){
        fail("Context switch is needed before sending another process to CPU");
    }

    if(p->state == READY){
        cpu.set(p);
    }else{
        fail("Process state must be READY to get in CPU");
    }
}
ProcPtr Manager::contextSwitch(){
    if(isCPUEmpty()){
        fail("Context switch performed without any process running on the CPU");
    }

    if(didContextSwitch){
        fail("An attempt to perform context switch twice in the same clock");
    }

    didContextSwitch = true;
    contextSwitches++;
    ProcPtr p = cpu.get();
    return p;
}

bool Manager::isCPUEmpty(){
    return cpu.isEmpty();
}

size_t Manager::get_time_elapsed(){
    return time_elapsed;
}
