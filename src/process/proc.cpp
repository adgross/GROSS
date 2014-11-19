#include "proc.h"

int Process::PID_counter{0};

Process::Process(std::shared_ptr<Program> prog, int prio) : priority(prio), program(prog){
    PID = PID_counter++;
}
Process::Process() : priority(15), program(nullptr) {
    PID = PID_counter++;
}
Process::~Process(){}

bool Process::isIRQ(){
    return false;
}
