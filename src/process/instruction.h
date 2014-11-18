#ifndef INSTRUCTION_H
#define INSTRUCTION_H

    #include <string>

struct Instruction
{
    Instruction(std::string const& str);

    std::string device{};
    int time{0};
};

#endif // INSTRUCTION_H
