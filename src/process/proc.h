#ifndef PROC_H
#define PROC_H

#include <memory>
#include "program.h"

class Process;

typedef std::shared_ptr<Process> ProcPtr;

enum process_state{ READY, RUNNING, BLOCKED, DESTROYED };

class Process
{
    public:
        Process(Program& prog, int prio);
        void setPriority(int p);
        int getPID();
        int getPC();
        int getPriority();
        int get_time_queue();
        int get_time_exec();
        int get_time_io();
        int get_time_total_queue();
        int get_time_total_exec();
        int get_time_total_io();
        int get_time_total();
        process_state getState();
    private:
        void setState(process_state ps);
        static int PID_counter;
        int PID{0};
        int PC{0};
        int priority;
        process_state state{READY};
        unsigned int time_queue{0};
        unsigned int time_exec{0};
        unsigned int time_io{0};
        unsigned int time_total_queue{0};
        unsigned int time_total_exec{0};
        unsigned int time_total_io{0};
        unsigned int time_total{0};
        Program program;

        friend class Manager;
        friend class CPU;
};

#endif // PROCESS_H
