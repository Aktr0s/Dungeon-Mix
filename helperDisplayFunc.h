#ifndef HDF_H
#define HDF_H
#include <stdio.h>
#include "crossFunctions.h"
#include "graphics.h"
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

void printGraphics(const char *graphics[]) {
    for (int i = 0; graphics[i] != NULL; i++) {
        printf(graphics[i]);
    }
}

void printGraphicsSlow(const char *graphics[]){
    for (int i = 0; graphics[i] != NULL; i++) {
        printSlow(graphics[i]);
    }
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Discard characters until the end of the line
    }
}

//This function displays ending game screen
void splashScreen(){
    printGraphics(splashScreenGraphics);
    printGraphicsSlow(titleScreenGraphics);
    while (getchar() != '\n');
    printf("\033[H\033[J");
}

void endGame(double vis, double taint, int mix){
    if(vis < taint){
        printGraphicsSlow(taintScreenGraphics);
        printf("Vis: %lf units    Taint: %lf units",vis,taint);
        printf("\nMixings: %d times",mix);
        printSlow("\nLuck did not stand on your side.\nAll Vis energy vanished and turned into Taint\nOne Taint potion has been added to your inventory");

    } else if (vis > taint){
        printGraphicsSlow(visScreenGraphics);
        printf("Vis: %lf units    Taint: %lf units",vis,taint);
        printf("\nMixings: %d times",mix);
        printSlow("\nLuck is on your side.\nAll Taint energy vanished and turned into Vis\nOne Vis potion has been added to your inventory");
    }
    printf("\n\n\n");
    cross_sleep(2);
}

void cauldronAnim(int state){
    if (state > 6 || state < 0) {
        printf("Err: wrong argument");
    } else {
        switch (state)
        {
        case 0:
            printf("\033[H\033[J");
            printGraphics(cauldron1ScreenGraphics);
            break;
        case 1:
            printf("\033[H\033[J");
            printGraphics(cauldron2ScreenGraphics);
            break;
        case 2:
            printf("\033[H\033[J");
            printGraphics(cauldron3ScreenGraphics);
            break;
        case 3:
            printf("\033[H\033[J");
            printGraphics(cauldron4ScreenGraphics);
            break;
        case 4:
            printf("\033[H\033[J");
            printGraphics(cauldron5ScreenGraphics);
            break;
        case 5:
            printf("\033[H\033[J");
            printGraphics(cauldron6ScreenGraphics);
        default:
            break;
        }
    }
}

void displayPotions(int a, int b,int c){
    printGraphics(potionScreenGraphics);
    printSlow("Vis Potions: ");
    printf("%d",a);
    printSlow("  Taint Potions: ");    
    printf("%d\n",b);
    printSlow("And T$");
    printf("%d",c);
    printSlow(" (Tokens)\n");
}

#endif