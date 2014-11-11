#include "program.h"
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <stdexcept>

Program::Program(const std::string&& fileName) : Program(fileName) {}
Program::Program(const std::string& fileName){
    std::string file = path + fileName + ".prog";

    std::ifstream in(file);
    if(!in.is_open()){
        std::string what = "Arquivo " + file + " nao foi encontrado";
        throw std::invalid_argument (what);
    }

    std::string temp;
    while( std::getline(in, temp) ){
        if(std::all_of( temp.begin(), temp.end(), [](auto& i){return std::isspace(i);} ))
            continue;
        instructions.emplace_back(temp);
    }
    instructions.shrink_to_fit();
}

