#include "manager.h"
#include "scheduler.h"

Manager::Manager(std::string const& sched_name){
    scheduler = Scheduler::getInstance(sched_name);
}

void Manager::addProcess(ProcPtr p){
    process_list.push_back(p);

    if(running){
        scheduler->start_to_queue(p);
    }
}

void Manager::start(){
    if(process_list.size() == 0){
        throw std::runtime_error("Nenhum processo para executar");
    }

    running = true;
    scheduler->start(process_list);
}


void Manager::sendToCPU(ProcPtr p){

}
void Manager::contextSwitch(ProcPtr p){

}
void Manager::killProcess(ProcPtr p){
    // mata processo
    // verifica fim da simulação
}

