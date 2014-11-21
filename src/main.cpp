#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <stdexcept>
#include <unordered_map>
#include "functions.h"
#include "scheduler.h"
#include "manager.h"
#include "console.h"
#include "program.h"
#include "proc.h"

void print_help();

int main(int argc, char** argv){
    if(argc <= 1){
        print_help();
        return -1;
    }

    std::string file{argv[1]};
    std::ifstream in(file);
    std::shared_ptr<Manager> mgr;

    if(in.is_open()){
        try{
            std::string str_temp;
            std::string str_scheduler;
            std::string str_program;
            std::string str_priority;

            in >> str_temp >> str_scheduler;

            string_to_lower(str_temp);
            if(str_temp != "scheduler" && str_temp != "escalonador")
                throw std::runtime_error("Primeiro parametro deve ser 'escalonador nome' ou 'scheduler nome'");

            std::unordered_map<std::string, Program> loaded_programs;

            Scheduler& s = Scheduler::getInstance(str_scheduler);
            mgr = std::make_shared<Manager>(s);
            s.setManager(mgr);

            while(in >> str_program >> str_priority){
                if(!loaded_programs.count(str_program)){
                    loaded_programs.emplace(str_program, str_program); // nome, program
                }

                try{
                    int priority = std::stoi(str_priority);
                    if(priority <= 0)
                        throw std::domain_error("A prioridade '" + str_priority + "' deve ser positiva");

                    auto p = std::make_shared<Process>(loaded_programs.find(str_program)->second, priority);
                    mgr->addProcess(p);

                } catch (std::invalid_argument const& ex){
                    throw std::invalid_argument {"A prioridade '" + str_priority + "' nao e valida"};
                }
            }
        } catch (std::exception const& ex){
            print_error(ex.what());
            return -3;
        }

    } else {
        print_error("Arquivo '" + file + "' nao pode ser aberto.");
        return -2;
    }

    try{
        mgr->start();
    } catch (std::exception const& ex){
        print_warning(ex.what());
        return -4;
    }

    std::cout << mgr->generateReport();

    return 0;
}

void print_help(){
    std::cout << color::yellow << "Utilizacao:" << std::endl
              << "  GROSS <arquivo de simulacao>" << std::endl
              << "    exemplo: GROSS simTest.txt" << color::unset;
}
