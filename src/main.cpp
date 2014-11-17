#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <stdexcept>
#include <unordered_map>
#include "util/console.h"
#include "process/program.h"

void print_help();

int main(int argc, char** argv){
    if(argc <= 1){
        print_help();
        return 0;
    }

    std::ifstream in(argv[1]);
    std::unordered_map<std::string, Program> loaded_programs;
//    std::list<Process> tempProcessList;

    if(in.is_open()){
        std::string str_program;
        std::string str_priority;

        try{
            while(in >> str_program >> str_priority){
                    // carregar sheduler

                if(!loaded_programs.count(str_program)){
                    loaded_programs.emplace(str_program, str_program); // nome, Program
                }

                try{
                    int priority = std::stoi(str_priority);
                    if(priority <= 0)
                        throw std::domain_error("A prioridade '" + str_priority + "' deve ser positiva");
                    std::cout << "|" << str_program << "|" << priority << "|" << std::endl;

                } catch (const std::invalid_argument& ex){
                    std::string what = "A prioridade '" + str_priority + "' nao e valida";
                    throw std::invalid_argument {what};
                }
            }
        } catch (const std::exception& ex){
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
