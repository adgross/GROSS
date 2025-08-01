#ifndef CONSOLE_H
#define CONSOLE_H

#include<string>

namespace color{
    enum colors_t {black, darkBlue, darkGreen, darkCyan, darkRed, darkPink, darkYellow, gray,
                darkGray,     blue,     green,     cyan,     red,     pink,     yellow, white };
    enum colors_unset { unset }; // enum to color reset when used with cout - made to be used as operator overload, so don't need extras checks for color_t

    void print(std::string const& msg, colors_t color);
    void print(std::string const&& msg, colors_t color);
    void setColor(colors_t color);
    void unsetColor();

    std::ostream& operator<<(std::ostream& os, colors_t c);
    std::ostream& operator<<(std::ostream& os, colors_unset c);
}

void print_warning(std::string const& error_msg);
void print_warning(std::string const&& error_msg);
void print_error(std::string const& error_msg);
void print_error(std::string const&& error_msg);

#endif // CONSOLE_H
