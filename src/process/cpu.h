#ifndef CPU_H
#define CPU_H

#include "proc.h"

class CPU
{
    public:
        CPU();
        bool isEmpty();
        void execute();
        void ioExecute(ProcPtr p);

        void set(ProcPtr p);
        ProcPtr get();
    private:
        ProcPtr proc;
        size_t time_idle{0};
        size_t time_not_idle{0};

        friend class Manager;
};

#endif // CPU_H
