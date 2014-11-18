#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <algorithm>
#include <stdexcept>
#include <unordered_map>
#include "manager.h"
#include "util/console.h"
#include "scheduler/scheduler.h"
#include "process/program.h"

void print_help();

int main(int argc, char** argv){
    if(argc <= 1){
        print_help();
        return 0;
    }

    std::ifstream in(argv[1]);
    std::unordered_map<std::string, Program> loaded_programs;

    if(in.is_open()){
        std::string str_temp;
        std::string str_scheduler;
        std::string str_program;
        std::string str_priority;

        try{
            in >> str_temp >> str_scheduler;
            for_each(str_temp.begin(), str_temp.end(), tolower);

            if(str_temp != "scheduler" && str_temp != "escalonador")
                throw std::runtime_error("Primeiro parametro deve ser 'escalonador nome' ou 'scheduler nome'");

            Manager mgr {Scheduler::getInstance(str_scheduler)};

            while(in >> str_program >> str_priority){
                if(!loaded_programs.count(str_program)){
                    loaded_programs.emplace(str_program, str_program); // nome, Program
                }

                try{
                    int priority = std::stoi(str_priority);
                    if(priority <= 0)
                        throw std::domain_error("A prioridade '" + str_priority + "' deve ser positiva");

                    mgr.createProcess(loaded_programs.find(str_program)->second, priority);

                } catch (std::invalid_argument const& ex){
                    throw std::invalid_argument {"A prioridade '" + str_priority + "' nao e valida"};
                }
            }
        } catch (std::exception const& ex){
            print_error(ex.what());
            return 0;
        }

    } else {
        print_error("Arquivo nao pode ser aberto.");
    }

//    manager.run();
    return 0;
}

void print_help(){
    std::cout << color::yellow << "Utilizacao:" << std::endl
              << "  GROSS <arquivo de simulacao>" << std::endl
              << "    exemplo: GROSS simTest.txt" << color::unset;
}
