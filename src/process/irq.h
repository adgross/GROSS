#ifndef IRQ_H
#define IRQ_H

#include <proc.h>


class IRQ : public Process
{
    public:
        IRQ(ProcPtr p);
        bool isIRQ();
        ProcPtr get_process();
    private:
        ProcPtr process;
};

#endif // IRQ_H
