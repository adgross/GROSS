#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <string>

struct Instruction
{
    Instruction(std::string const& str);

    enum opcode : char {PROCESS, IO} command{};
    unsigned short time{0};
};

#endif // INSTRUCTION_H
