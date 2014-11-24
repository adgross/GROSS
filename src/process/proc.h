#ifndef PROC_H
#define PROC_H

#include <memory>
#include "program.h"

class Process;

typedef std::shared_ptr<Process> ProcPtr;

enum process_state { READY, RUNNING, BLOCKED, DESTROYED };

class Process
{
    public:
        Process(Program& prog, int prio);
        size_t getPID();
        size_t getPC();
        size_t getProgramSize();
        void setPriority(int p);
        int getPriority();
        size_t get_time_queue();
        size_t get_time_exec();
        size_t get_time_io();
        size_t get_time_total_queue();
        size_t get_time_total_exec();
        size_t get_time_total_io();
        size_t get_time_total();
        process_state getState();
    private:
        void setState(process_state ps);
        static size_t PID_counter;
        size_t PID{0};
        size_t PC{0};
        int priority;
        size_t time_queue{0};
        size_t time_exec{0};
        size_t time_io{0};
        size_t time_total_queue{0};
        size_t time_total_exec{0};
        size_t time_total_io{0};
        size_t time_total{0};
        process_state state{READY};
        Program program;

        friend class Manager;
        friend class CPU;
};

#endif // PROCESS_H
