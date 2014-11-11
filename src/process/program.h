#ifndef PROGRAM_H
#define PROGRAM_H

    #include <string>
    #include <vector>
    #include "instruction.h"

class Program
{
    public:
        Program(const std::string& fileName);
        Program(const std::string&& fileName);
    private:
        std::vector<Instruction> instructions{};
        std::string path{"programs/"};
};

#endif // PROGRAM_H
