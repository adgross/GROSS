#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
#include <fstream>
#include "util/console.h"
#include "process/program.h"

void print_help();

int main(int argc, char** argv){
    if(argc <= 1){
        print_help();
        return 0;
    }

    std::ifstream in(argv[1]);
    if(in.is_open()){
        std::string str_program;
        std::string str_priority;
        std::unordered_map<std::string, Program> loaded_programs;
        std::list<Process> procList;


        while(in >> str_program >> str_priority){
            std::cout << "|" << str_program << "|" << str_priority << "|" << std::endl;
            try{
                if(!loaded_programs.count(str_program)){
                    loaded_programs.emplace(str_program, str_program); // nome, Program
                }


                int priority = std::stoi(str_priority);
                //        Process p();
/*
            } catch(const std::ifstream::failure& ex){
                std::cout << color::red << "Nao foi possivel encontrar o arquivo "
                          << color::yellow << str_program << color::unset << std::endl;
*/
            } catch (const std::exception& ex){
                std::cout << color::red << "A prioridade '"
                          << color::yellow << str_priority
                          << color::red << "' nao e valida" << color::unset;
            }
        }
    } else {
        color::print("Arquivo nao pode ser aberto.", color::red);
    }


    return 0;
}

void print_help(){
    color::setColor(color::yellow);
    std::cout << "Utilizacao:" << std::endl
              << "  GROSS <arquivo de simulacao>" << std::endl
              << "    exemplo: GROSS simTest.txt";
    color::unsetColor();
}
