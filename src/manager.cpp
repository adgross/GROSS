#include "manager.h"
#include <iostream>

Manager::Manager(Scheduler* sched) : scheduler(sched){

}

void Manager::createProcess(Program const& prog, int priority){
    std::cout << "|" << prog.get_name() << "|" << priority << "|" << std::endl;
    Instruction const a = prog.get_instruction(0);
    std::cout << "  |" << prog.get_size() << " " << a.device  << "|" << a.time << "|" << std::endl;

}
