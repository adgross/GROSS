#ifndef CONSOLE_H
#define CONSOLE_H

    #include<string>

	#ifdef _WIN32
        #include<windows.h>
    #else
		#include<map>
    #endif

namespace color{
    enum colors_t {black, darkBlue, darkGreen, darkCyan, darkRed, darkPink, darkYellow, gray,
                darkGray,     blue,     green,     cyan,     red,     pink,     yellow, white };
    enum colors_unset { unset }; // enum para resetar quando utilizado com algum ostream - utilizando sobrecarga de método ao invés de verificações extras

    void print(const std::string& msg, colors_t color);
    void print(const std::string&& msg, colors_t color);
    void setColor(colors_t color);
    void unsetColor();

    std::ostream& operator<<(std::ostream& os, colors_t c);
    std::ostream& operator<<(std::ostream& os, colors_unset c);
}

void print_warning(const std::string& error_msg);
void print_warning(const std::string&& error_msg);
void print_error(const std::string& error_msg);
void print_error(const std::string&& error_msg);

#endif // CONSOLE_H
