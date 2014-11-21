#include "proc.h"

int Process::PID_counter{0};

Process::Process(Program& p, int prio) : priority(prio), program(p){
    PID = PID_counter++;
}

void Process::setPriority(int p){
    if(p <= 0)
        throw std::domain_error("Erro em setPriority no processo de PID " + std::to_string(PID) +
                                 ". A prioridade '" + std::to_string(p) + "' deve ser positiva");
    priority = p;
}


int Process::getPID(){
    return PID;
}
int Process::getPC(){
    return PC;
}
int Process::getPriority(){
    return priority;
}
int Process::get_time_queue(){
    return time_queue;
}
int Process::get_time_exec(){
    return time_exec;
}
int Process::get_time_io(){
    return time_io;
}
int Process::get_time_total_queue(){
    return time_total_queue;
}
int Process::get_time_total_exec(){
    return time_total_exec;
}
int Process::get_time_total_io(){
    return time_total_io;
}
int Process::get_time_total(){
    return time_total;
}
void Process::setState(process_state ps){
    state = ps;
    time_queue = 0;
    time_exec = 0;
    time_io = 0;
}
process_state Process::getState(){
    return state;
}
