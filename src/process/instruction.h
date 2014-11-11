#ifndef INSTRUCTION_H
#define INSTRUCTION_H

    #include <string>

struct Instruction
{
    Instruction(const std::string& str);

    std::string device;
    int time{0};
};

#endif // INSTRUCTION_H
