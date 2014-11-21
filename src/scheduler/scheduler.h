#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <string>
#include <vector>
#include <map>
#include "proc.h"

class Manager;

class Scheduler
{
    public:
        Scheduler(const std::string& name);
        Scheduler(const std::string&& name);
        virtual ~Scheduler();
        static Scheduler& getInstance(const std::string& sched_name);
        static Scheduler& getInstance(const std::string&& sched_name);
        void setManager(std::shared_ptr<Manager> m);

        virtual void setup(std::vector<ProcPtr> const& p) = 0; // scheduler setup, before update() first run
        virtual void update() = 0; // update will run each simulation frame/moment/clock

    protected:
        std::shared_ptr<Manager> manager{nullptr};
    private:
        std::string const sched_name;
        static std::map<std::string, std::reference_wrapper<Scheduler>> schedulers;
};

#endif // SCHEDULER_H
