#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include <memory>
#include <list>
#include "proc.h"
#include "cpu.h"

class Scheduler;

class Manager
{
    public:
        Manager(std::string const& sched_name);
        void addProcess(ProcPtr p);
        void start();

        void sendToCPU(ProcPtr p);
        void contextSwitch(ProcPtr p);
        void killProcess(ProcPtr p);
    private:
        Manager (const Manager&) = delete;
        Manager& operator=(Manager const&) = delete;

        bool running = false;
        int time_elapsed = 0;
        Scheduler* scheduler = nullptr;
        CPU cpu{};
        ProcList process_list{};
};

#endif // MANAGER_H
