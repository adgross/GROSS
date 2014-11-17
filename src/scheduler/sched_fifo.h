#ifndef SCHED_FIFO_H
#define SCHED_FIFO_H

#include <queue>
#include "scheduler.h"


class sched_fifo : public Scheduler
{
    public:
        sched_fifo();
        void start_to_queue() override;
        void cpu_to_queue() override;
        void cpu_to_io() override;
        void cpu_to_end() override;
        void io_to_queue() override;
    private:
        std::queue<Process> queue{};
} sched_fifo;

#endif // SCHED_FIFO_H
