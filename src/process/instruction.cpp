#include "instruction.h"
#include "functions.h"
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <limits>

Instruction::Instruction(std::string const& str){
    std::stringstream ss{str};
    std::string str_command;
    int temp_time;
    ss >> str_command >> temp_time;

    string_to_lower(str_command);
    if(str_command == "process"){
        command = PROCESS;
    } else if (str_command == "io"){
        command = IO;
    } else {
        throw std::invalid_argument("Comando '" + str_command + "' invalido");
    }

    if(temp_time <= 0){
        throw std::invalid_argument("Tempo invalido");
    }

    if(temp_time > std::numeric_limits<short>::max()){
        throw std::invalid_argument("Tempo deve ser menor ou igual a " + std::to_string(std::numeric_limits<short>::max()));
    }
    time = temp_time;

}
