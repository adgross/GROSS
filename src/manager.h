#ifndef MANAGER_H
#define MANAGER_H

#include "process.h"
#include "scheduler.h"

class Manager
{
    public:
        Manager(Scheduler* sched);
        void sendToCPU(Process& p);
        void contextSwitch(Process& p);
    protected:
    private:
        int time_elapsed = 0;
        Scheduler* scheduler;
};

#endif // MANAGER_H
