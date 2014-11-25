#ifndef SCHED_FIFO_H
#define SCHED_FIFO_H

#include "scheduler.h"
#include "manager.h"
#include <queue>

class Sched_RoundRobin : public Scheduler
{
    public:
        Sched_RoundRobin();
        void setup(std::vector<ProcPtr> const& p) override;
        void update() override;
    private:
        ProcPtr next();
        std::queue<ProcPtr> q{};
        void frontToBack();
};

#endif // SCHED_FIFO_H
