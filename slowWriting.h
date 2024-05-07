#ifndef SLOWWR_H
#define SLOWWR_H
#include <stdio.h>
#include <unistd.h>
#include "crossFunctions.h"
void printSlow(const char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ') {
            printf(" ");
        } else {
        printf("%c", text[i]);
        fflush(stdout);
        cross_sleep(1000); 
        }
    }
}
#endif