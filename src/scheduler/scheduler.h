#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <string>
#include <map>

class Scheduler
{
    public:
        Scheduler(const std::string& name);
        Scheduler(const std::string&& name);
        virtual ~Scheduler();
        static Scheduler* getInstance(const std::string& sched_name);

    // eventos
        virtual void start_to_queue() = 0;
      //  virtual void queue_to_cpu() = 0; tarefa do escalonador e não evento
        virtual void cpu_to_queue() = 0;
        virtual void cpu_to_io() = 0;
        virtual void cpu_to_end() = 0;
        virtual void io_to_queue() = 0;
    protected:

    private:
        std::string const sched_name;
        static std::map<std::string, Scheduler*> schedulers;
};

#endif // SCHEDULER_H
