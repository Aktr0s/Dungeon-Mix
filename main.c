#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "depletionLogic.h"
#include "helperDisplayFunc.h"
#include "crossFunctions.h"

#define MAX_TAINT 5.0
#define MAX_VIS 25.0


//Global variables
double vis, taint;
int mix;
int potionVis, potionTaint, money;
double marketVis, marketTaint;
FILE *savefile;
bool save = true;
bool loadSave = true;



void displayUpdate(){
    for (int i = 0; i <= 5; i++) {
    cauldronAnim(i);
    printf("\n");
    printf("Vis: %lf units    Taint: %lf units",vis,taint);
    cross_sleep(500000);
    printf("\033[H\033[J"); //ASCI Escape Code
    }
}

void calculations(){
    vis = hashRandom(vis, taint);
    taint = hashRandom(taint, vis);
    vis *= 2;
    taint *= 2;
}

void mixUpdate(){
    calculations();
    displayUpdate();
}



int main(){
    srand(time(NULL));
    marketTaint = ((double)rand() / RAND_MAX) * MAX_TAINT;
    marketVis = ((double)rand() / RAND_MAX) * MAX_VIS;
    if (marketTaint > marketVis){
        double temp = marketTaint;
        marketTaint = marketVis;
        marketVis = temp;
    }

    printf("\033[H\033[J");
    splashScreen();

    const char *filename = "dungeonMix.savedisk";
    if (access(filename, F_OK) != 0) {
        loadSave = false;
        printf("It looks like your save file is gone or you started the game for the first time.\n");
        printf("Would you like to create a new save file? [Y/N]");
        char opt;
        while (1){
            scanf("%1s",&opt);
            if (opt == 'y' || opt == 'Y'){
                save = true;
                break;
            } else if (opt == 'n' || opt == 'N') {
                printf("\n-----------------Warning------------------\n");
                printf("You will play the game without a save file\nYour progress won't be saved.\n");
                save = false;
                break;
            } else {
                printf("Invalid input. Please enter 'Y' or 'N': ");
                continue;
            }
        }
        
    }
    if (loadSave){
    savefile = fopen("dungeonMix.savedisk","r");
    if (!savefile) {
        perror("Failed to open save file");
        exit(EXIT_FAILURE);
    }
    fscanf(savefile, "%d", &potionVis);
    fscanf(savefile, "%d", &potionTaint);
    fscanf(savefile, "%d", &money);
    fclose(savefile);
    }
    
    while(1){
        printf("\n");
        printSlow("What do you want to do?\n");
        printSlow("1. Make Potions\n");
        printSlow("2. Check Your Inventory\n");
        printSlow("3. Display Description of the game\n");
        printSlow("4. Sell Your Potions\n");
        printSlow("5. Exit the game\n");
        printSlow("6. Show splash screen\n");
        printSlow("So?: ");
        int option;
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            printf("\033[H\033[J");
            printSlow("Enter the amout of mixings: ");
            scanf("%d",&mix);
            if (mix > 20){
                printSlow("You can't mix more than 20 times.\n");
                printSlow("Setting to 20.\n");
                mix = 15;
            } else if (mix < 1) {
                printSlow("You can't mix less than 1 time.\n");
                printSlow("Setting to 1.\n");
                mix = 1;
            }
            printSlow("Enter designated Vis and Taint amounts\nVis: ");
            scanf("%lf",&vis);
            printSlow("Taint: ");
            scanf("%lf",&taint);
            for (int i = 0; i <= mix; i++) {
                mixUpdate();
            }
            if (vis > taint) {
                vis = vis + taint;
                taint = 0;
                potionVis++;
            } else if (taint > vis) {
                taint = taint + vis;
                vis = 0;
                potionTaint++;
            }
        //This code just makes the sentence "cauldron full of" real
        endGame(vis,taint,mix);
            break;
        case 2:
            printf("\033[H\033[J");
            displayPotions(potionVis, potionTaint, money);
            break;
        case 3:
            printf("\033[H\033[J");
            printSlow("\nThe game princible is very simple.\nYou brew potions with vis and taint amount which are the ingridients. \nYou also chose how many times you will mix the brew. \nDepending on your luck (or rather some stupid math) you will brew a Good (Vis) or Bad (Tainted) potion.\n\n");
            break;
        case 4:
            printf("\033[H\033[J");
            displayPotions(potionVis, potionTaint, money);
            printSlow("Current market values: \n");
            printSlow("Vis potion: ");
            printf("%lf\n",marketVis);
            printSlow("Taint potion: ");
            printf("%lf\n",marketTaint);
            printSlow("Do you want to sell?: [Y/N]");
            char opt2;
            scanf("%1s",&opt2);
            if (opt2 == 'Y' || opt2 =='y'){
                money = money + round((marketVis * potionVis) + (marketTaint * potionTaint));
                potionVis = 0;
                potionTaint = 0;
            }
            break;
        case 5:
            if (save){savefile = fopen("dungeonMix.savedisk","w");
            printf("Saving...\n");
            fprintf(savefile,"%d\n",potionVis);
            fprintf(savefile,"%d\n",potionTaint);
            fprintf(savefile,"%d",money);
            }
            printf("Exiting...");
            fclose(savefile);
            return 0;
        case 6:
            printf("\033[H\033[J");
            clearInputBuffer();
            splashScreen();
            break;
        default:
            printf("\033[H\033[J");
            printSlow("Wrong Choice. Please Select Again.");
            break;
        }
    }
    return 0;
}