#include "instruction.h"
#include <string>
#include <sstream>

Instruction::Instruction(const std::string& str){
    std::stringstream ss{str};
    ss >> device >> time;

    if(time == 0){
        // throw
    }
}
