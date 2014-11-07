#ifndef PROGRAM_H
#define PROGRAM_H

    #include <string>
    #include <vector>

class Program
{
    public:
        Program(std::string& fileName);
        Program(std::string&& fileName);
    protected:
    private:
        std::vector<std::string> lines;
        std::string path{"programs/"};
};

#endif // PROGRAM_H
