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
        size_t size() const;
        std::string getName() const;
        Instruction const& getInstruction(int index) const;
        Instruction& getInstruction(int index);
    private:
        std::vector<Instruction> instructions{};
        std::string const prog_name;
};

#endif // PROGRAM_H
