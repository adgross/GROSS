#ifndef SCHED_FIFO_H
#define SCHED_FIFO_H

#include <queue>
#include "proc.h"
#include "scheduler.h"


class Sched_FIFO : public Scheduler
{
    public:
        Sched_FIFO();
        void start(ProcList p) override;
        void start_to_queue(ProcPtr p) override;
        void cpu_to_queue() override;
        void cpu_to_io() override;
        void cpu_to_end() override;
        void io_to_queue() override;
    private:
        std::queue<ProcPtr> q{};
};

#endif // SCHED_FIFO_H
