#include "instruction.h"
#include <string>
#include <sstream>

Instruction::Instruction(std::string const& str){
    std::stringstream ss{str};
    ss >> device >> time;

    if(time == 0){
        // throw
    }
}
