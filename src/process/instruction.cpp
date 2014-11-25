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
        throw std::invalid_argument("Invalid command '" + str_command + "'");
    }

    if(temp_time <= 0){
        throw std::invalid_argument("Invalid clock");
    }

    if(temp_time > std::numeric_limits<unsigned short>::max()){
        throw std::invalid_argument("Clock must be less than or equal to " + std::to_string(std::numeric_limits<unsigned short>::max()));
    }
    time = temp_time;

}
