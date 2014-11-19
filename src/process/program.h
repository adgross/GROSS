#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>
#include <vector>
#include "instruction.h"

class Program
{
    public:
        Program(std::string const& fileName);
        Program(std::string const&& fileName);
        int get_size() const;
        std::string get_name() const;
        Instruction const& get_instruction(int index) const;
    private:
        std::vector<Instruction> instructions{};
        std::string path{"programs/"};
        std::string prog_name;
};

#endif // PROGRAM_H
