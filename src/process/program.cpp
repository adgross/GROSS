#include "program.h"
#include <fstream>
#include <algorithm>
#include <cctype>
#include <stdexcept>

Program::Program(std::string const&& fileName) : Program(fileName) {}
Program::Program(std::string const& fileName) : prog_name(fileName) {
    std::string file = path + fileName + ".prog";

    std::ifstream in(file);
    if(!in.is_open()){
        throw std::invalid_argument ("Arquivo " + file + " nao foi encontrado");
    }

    std::string temp;
    while( std::getline(in, temp) ){
        if(std::all_of( temp.begin(), temp.end(), [](char& i){return std::isspace(i);} ))
            continue;
        instructions.emplace_back(temp);
    }
    instructions.shrink_to_fit();
}

int Program::get_size() const {
    return instructions.size();
}

std::string Program::get_name() const {
    return prog_name;
}

Instruction const& Program::get_instruction(int index) const {
    return instructions.at(index);
}
