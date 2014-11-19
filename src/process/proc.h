#ifndef PROC_H
#define PROC_H

#include <list>
#include <memory>
#include "program.h"

class Process;

typedef std::shared_ptr<Process> ProcPtr;
typedef std::list<ProcPtr> ProcList;

class Process
{
    public:
        Process(std::shared_ptr<Program> prog, int prio);
        virtual ~Process();

        virtual bool isIRQ();
        int get_PID();
        int get_PC();
        int get_priority();
        int get_time_queue();
        int get_time_exec();
        int get_time_io();
        int get_time_total_queue();
        int get_time_total_exec();
        int get_time_total_io();
    protected:
        Process();
    private:
        static int PID_counter;
        int PID{0};
        int PC{0};
        int priority;
        unsigned int time_queue{0};
        unsigned int time_exec{0};
        unsigned int time_io{0};
        unsigned int time_total_queue{0};
        unsigned int time_total_exec{0};
        unsigned int time_total_io{0};
        std::shared_ptr<Program> program;
};

#endif // PROCESS_H
