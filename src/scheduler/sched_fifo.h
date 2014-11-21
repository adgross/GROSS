#ifndef SCHED_FIFO_H
#define SCHED_FIFO_H

#include "scheduler.h"
#include "manager.h"
#include "proc.h"
#include <queue>


class Sched_FIFO : public Scheduler
{
    public:
        Sched_FIFO();
        void setup(std::vector<ProcPtr> const& p) override;
        void update() override;
    private:
        ProcPtr next();
        std::queue<ProcPtr> q{};
};

#endif // SCHED_FIFO_H
