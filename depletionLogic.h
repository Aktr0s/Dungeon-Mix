#ifndef DEPLETION_H
#define DEPLETION_H
#include <stdio.h>
#include <math.h>

double hashRandom(double a, double b){
    double originalNumber = (a * b);
    
    // Count the number of digits in the original number
    int numDigits = floor(log10(originalNumber)) + 1;

    // Calculate the divisor (power of 10)
    double divisor = pow(10, numDigits - 1);

    // Convert and return the result
    double convertedNumber = originalNumber / divisor;
    return sqrt(convertedNumber);

    //printf("%.8lf\n", convertedNumber);
}


#endif