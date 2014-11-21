#include "manager.h"
#include "scheduler.h"
#include <stdexcept>
#include <map>
#include <sstream>

Manager::Manager(Scheduler& sched) : scheduler(sched) {}

void Manager::fail(std::string what){
    throw std::runtime_error(what);
}

void Manager::addProcess(ProcPtr p){
    if(running){
        fail("Nao deve-se adicionar novos processos apos iniciar a simulacao");
    }

    process_list.push_back(p);
}

void Manager::start(){
    if(running){
        return;
    }
    running = true;

    if(process_list.size() == 0){
        fail("Nenhum processo para executar");
    }

    scheduler.setup(process_list);

    while(running){
        scheduler.update();
        updateTimers();
        doIO();
        cpu.execute();
        running = checkRunning();
    }

    generateReport();
}

std::string Manager::generateReport(){
    if(running){
        fail("Nao deve-se gerar relatorio enquanto a simulacao estiver executando");
    }

    std::stringstream ss;
    std::map<process_state, std::string> state_to_string{ {READY, "READY"},
                                                          {RUNNING, "RUNNING"},
                                                          {BLOCKED, "BLOCKED"},
                                                          {DESTROYED, "DESTROYED"} };

    ss << "Total Simulation Time: " << time_elapsed << std::endl;
    ss << "CPU Idle Time: " << cpu.time_idle << std::endl;
    ss << "CPU Not Idle Time: " << cpu.time_not_idle << std::endl;
    ss << std::endl;

    for(auto& p : process_list){
        ss << "Process " << p->PID << std::endl;
        ss << "  Time Waiting = " << p->time_total_queue << std::endl;
        ss << "  Time Running = " << p->time_total_exec << std::endl;
        ss << "  Time Blocked = " << p->time_total_io << std::endl;
        ss << "  Total Time = " << p->time_total << std::endl;
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
    if(!isCPUEmpty()){
        fail("Necessario Troca de Contexto antes de enviar outro processo para CPU");
    }

    if(p->state == READY){
        cpu.set(p);
    }else{
        fail("Estado do Processo deve ser READY para ir para a CPU");
    }
}
ProcPtr Manager::contextSwitch(){
    if(isCPUEmpty()){
        fail("Troca de Contexto realizada sem nenhum processo executando na CPU");
    }
    ProcPtr p = cpu.get();
    return p;
}

bool Manager::isCPUEmpty(){
    return cpu.isEmpty();
}
