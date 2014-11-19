#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include <unordered_map>
#include "manager.h"
#include "util/console.h"
#include "process/program.h"
#include "process/proc.h"

void print_help();

int main(int argc, char** argv){
    if(argc <= 1){
        print_help();
        return -1;
    }

    std::ifstream in(argv[1]);
    std::shared_ptr<Manager> mgr;

    if(in.is_open()){
        try{
            std::string str_temp;
            std::string str_scheduler;
            std::string str_program;
            std::string str_priority;

            in >> str_temp >> str_scheduler;
            for_each(str_temp.begin(), str_temp.end(), tolower);

            if(str_temp != "scheduler" && str_temp != "escalonador")
                throw std::runtime_error("Primeiro parametro deve ser 'escalonador nome' ou 'scheduler nome'");

            std::unordered_map<std::string, std::shared_ptr<Program>> loaded_programs;
            mgr = std::make_shared<Manager>(str_scheduler);

            while(in >> str_program >> str_priority){
                if(!loaded_programs.count(str_program)){
                    loaded_programs.insert({str_program, std::make_shared<Program> (str_program)});
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
        print_error("Arquivo nao pode ser aberto.");
        return -2;
    }

    try{
        std::cout << std::endl << "START" << std::endl;
        mgr->start();
    } catch (std::exception const& ex){
        print_warning(ex.what());
        return -4;
    }

    return 0;
}

void print_help(){
    std::cout << color::yellow << "Utilizacao:" << std::endl
              << "  GROSS <arquivo de simulacao>" << std::endl
              << "    exemplo: GROSS simTest.txt" << color::unset;
}
