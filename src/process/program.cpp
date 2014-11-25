#include "program.h"
#include "functions.h"
#include <fstream>
#include <algorithm>
#include <stdexcept>

Program::Program(std::string const&& fileName) : Program(fileName) {}
Program::Program(std::string const& fileName) : prog_name(fileName) {
    std::string file = "programs/" + fileName + ".prog";

    std::ifstream in(file);
    if(!in.is_open()){
        throw std::invalid_argument ("File " + file + " not found");
    }

    std::string temp;
    int temp_line{0};
    while( std::getline(in, temp) ){
        temp_line++;
        if(is_all_space(temp))
            continue;

        try{
            instructions.emplace_back(temp);
        } catch(std::invalid_argument const& ex) {
            throw std::runtime_error("Error loading " + file + ": " +
                                      ex.what() + " on line " + std::to_string(temp_line));
        }
    }
    instructions.shrink_to_fit();

}

size_t Program::size() const {
    return instructions.size();
}

std::string Program::getName() const {
    return prog_name;
}

Instruction const& Program::getInstruction(int index) const {
    return instructions.at(index);
}
Instruction& Program::getInstruction(int index) {
    return instructions.at(index);
}
