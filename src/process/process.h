#ifndef PROCESS_H
#define PROCESS_H

class Process
{
    public:
        Process(int prio); // programa associado ao processo
    protected:
    private:
        int PID{0};
        int priority;
        unsigned int time_queue{0};
        unsigned int time_exec{0};
        unsigned int time_total_wait{0};
        unsigned int time_total_exec{0};
};

#endif // PROCESS_H
