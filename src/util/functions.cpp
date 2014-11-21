#include "functions.h"
#include <algorithm>

void string_to_lower(std::string& str){
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}

bool is_all_space(std::string& str){
    return std::all_of( str.begin(), str.end(), [](char& i){return std::isspace(i);} );
}
