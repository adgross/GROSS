#include "instruction.h"
#include <sstream>

Instruction::Instruction(std::string const& str){
    std::stringstream ss{str};
    ss >> command >> time;

    if(time == 0){
        // throw
    }

    // if command != "process" ou "io"
        // throw
}
