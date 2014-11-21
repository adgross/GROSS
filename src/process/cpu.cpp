#include "cpu.h"
#include "program.h"
#include "instruction.h"

CPU::CPU() : proc{nullptr} {}

bool CPU::isEmpty(){
    return proc.get() == nullptr;
}

void CPU::execute(){
    if(isEmpty()  || (proc->state != RUNNING)){
        time_idle++;
        return; // no operation
    }

    time_not_idle++;
    proc->time_exec++;
    proc->time_total_exec++;

    Instruction& inst = proc->program.getInstruction(proc->PC);

    if(inst.command == "io"){
        proc->setState(BLOCKED);
        proc.reset();
        return;
    }

    inst.time--;

    if(inst.time == 0){
        proc->PC++;
    }


    if(proc->program.size() == proc->PC){
        proc->setState(DESTROYED);
        proc.reset();
    }
}

void CPU::ioExecute(ProcPtr p){
    if(p->state != BLOCKED){
        return;
    }

    Instruction& inst = p->program.getInstruction(p->PC);

    inst.time--;
    p->time_io++;
    p->time_total_io++;

    if(inst.time == 0){
        p->setState(READY);
        p->PC++;
    }

    if(p->program.size() == p->PC){
        p->setState(DESTROYED);
    }
}

void CPU::set(ProcPtr p){
    proc = p;
    proc->setState(RUNNING);
}

ProcPtr CPU::get(){
    ProcPtr temp = proc;
    proc.reset();

    temp->setState(READY);
    return temp;
}
