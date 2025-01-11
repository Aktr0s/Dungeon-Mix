#ifndef CROSS_FUNC
#define CROSS_FUNC

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>

void cross_sleep(unsigned int microseconds) {
    Sleep(microseconds / 1000); // Sleep takes milliseconds
}

#else
#include <unistd.h>
// Wrapper function for usleep/Sleep
void cross_sleep(unsigned int microseconds) {
    usleep(microseconds); // usleep takes microseconds directly
}
#endif

#endif