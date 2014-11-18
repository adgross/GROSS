#include "console.h"
#include <iostream>
#include <string>

namespace color{
    void print(std::string const&& msg, colors_t color){
        print(msg, color);
    }
    void print(std::string const& msg, colors_t color){
        setColor(color);
        std::cout << msg;
        unsetColor();
    }

    void setColor(colors_t color){
        #ifdef _WIN32
            HANDLE cHandle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(cHandle, color);
        #else
            static const map<colors_t, string>  colors_str
                    {
                        {black, "0;30"},	{darkGray,"1;30"},
                        {darkBlue,"0;34"},	{blue,"1;34"},
                        {darkGreen,"0;32"},	{green,"1;32"},
                        {darkCyan,"0;36"},	{cyan,"1;36"},
                        {darkRed,"0;31"},	{red,"1;31"},
                        {darkPink,"0;35"},	{pink,"1;35"},
                        {darkYellow,"0;33"},{yellow,"1;33"},
                        {gray,"0;37"},		{white,"1;37"}
                    };
            printf("\x1b[%sm", colors_str[color].data() );
        #endif
    }


    void unsetColor(){
        #ifdef _WIN32
            HANDLE cHandle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(cHandle, 7);
        #else
            printf("\x1b[0m");
        #endif
    }

    std::ostream& operator<<(std::ostream& os, colors_t c){
        setColor(c);
        return os;
    }

    std::ostream& operator<<(std::ostream& os, colors_unset c){
        (void)c; // variavel c não é usada
        unsetColor();
        return os;
    }

}

void print_warning(std::string const& error_msg){
    color::print(error_msg, color::red);
}
void print_warning(std::string const&& error_msg){
    color::print(error_msg, color::red);
}

void print_error(std::string const& error_msg){
    color::print(error_msg, color::red);
}
void print_error(std::string const&& error_msg){
    color::print(error_msg, color::red);
}
