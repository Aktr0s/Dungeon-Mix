#ifndef CROSS_SL
#define CROSS_SL

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#else
#include <unistd.h>
#endif

// Wrapper function for usleep/Sleep
void cross_sleep(unsigned int microseconds) {
#if defined(_WIN32) || defined(_WIN64)
    Sleep(microseconds / 1000); // Sleep takes milliseconds
#else
    usleep(microseconds); // usleep takes microseconds directly
#endif
}

#endif