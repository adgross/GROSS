#include "program.h"
#include <string>
#include <fstream>

#include <iostream>

Program::Program(std::string&& fileName) : Program(fileName) {}
Program::Program(std::string& fileName){
    std::string file = path + fileName + ".prog";
    std::cout << file << std::endl;

    std::ifstream in(file);
    if(!in.is_open()){
        //
    }

    std::string temp;
    while( std::getline(in, temp) ){
        std::cout << temp << std::endl;
    }

    // verifica linhas são validas

}

