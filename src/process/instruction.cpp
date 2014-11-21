#include "instruction.h"
#include "functions.h"
#include <algorithm>
#include <stdexcept>
#include <sstream>

Instruction::Instruction(std::string const& str){
    std::stringstream ss{str};
    ss >> command >> time;

    string_to_lower(command);
    if(command != "process" && command != "io"){
        throw std::invalid_argument("Comando '" + command + "' invalido");
    }

    if(time <= 0){
        throw std::invalid_argument("Tempo invalido");
    }
}
