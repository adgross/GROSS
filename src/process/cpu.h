#ifndef CPU_H
#define CPU_H

#include <string>
#include "irq.h"
#include "proc.h"
#include "instruction.h"

class CPU
{
    public:
        CPU();
        isEmpty();
        execute();
    protected:
    private:
};

#endif // CPU_H
