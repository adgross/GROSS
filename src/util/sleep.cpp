#include "sleep.h"
#include <thread>
#include <chrono>

void dorme(int msecs){
    std::this_thread::sleep_for( std::chrono::milliseconds(msecs) );
}
