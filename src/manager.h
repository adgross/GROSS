#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include <vector>
#include <memory>
#include "scheduler.h"
#include "proc.h"
#include "cpu.h"

class Manager
{
    public:
        Manager(Scheduler& sched);
        void addProcess(ProcPtr p);
        void start();
        std::string generateReport();

        void sendToCPU(ProcPtr p);
        ProcPtr contextSwitch();
        bool isCPUEmpty();
        void callFinish();
        size_t get_time_elapsed();

    private:
        void nextClock();
        void doIO();
        bool checkRunning();
        void updateTimers();
        void fail(std::string what);

        bool running{false};
        size_t time_elapsed{0};

        bool didContextSwitch{false};
        size_t contextSwitches{0};


        std::vector<ProcPtr> process_list{};
        Scheduler& scheduler;
        CPU cpu{};
};

#endif // MANAGER_H
