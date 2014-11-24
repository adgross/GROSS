#include "proc.h"

size_t Process::PID_counter{0};

Process::Process(Program& p, int prio) : priority(prio), program(p){
    PID = PID_counter++;
}

void Process::setPriority(int p){
    if(p <= 0)
        throw std::domain_error("Erro em setPriority no processo de PID " + std::to_string(PID) +
                                 ". A prioridade '" + std::to_string(p) + "' deve ser positiva");
    priority = p;
}


size_t Process::getPID(){
    return PID;
}
size_t Process::getPC(){
    return PC;
}
size_t Process::getProgramSize(){
    return program.size();
}
int Process::getPriority(){
    return priority;
}
size_t Process::get_time_queue(){
    return time_queue;
}
size_t Process::get_time_exec(){
    return time_exec;
}
size_t Process::get_time_io(){
    return time_io;
}
size_t Process::get_time_total_queue(){
    return time_total_queue;
}
size_t Process::get_time_total_exec(){
    return time_total_exec;
}
size_t Process::get_time_total_io(){
    return time_total_io;
}
size_t Process::get_time_total(){
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
