#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "depletionLogic.h"
#include "showDisplays.h"
#include "slowWriting.h"
#include "crossFunctions.h"


//Global variables
double vis, taint;
int mix;
int potionVis, potionTaint, money;
double marketVis, marketTaint;
FILE *savefile;
bool save = true;

void displayUpdate(){
    for (int i = 0; i <= 5; i++) {
    cauldronAnim(i);
    printf("\n");
    printf("Vis: %lf units    Taint: %lf units",vis,taint);
    cross_sleep(500000);
    clearTerm();
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
    marketTaint = ((double)rand() / RAND_MAX) * 5.0;
    marketVis = ((double)rand() / RAND_MAX) * 25.0;
    if (marketTaint > marketVis){
        double temp = marketTaint;
        marketTaint = marketVis;
        marketVis = temp;
    }
    clearTerm();
    
    clearTerm();
    const char *filename = "dragonMix.savedisk";
    if (access(filename, F_OK) != 0) {
        printf("It looks like your save file is gone or you started the game for the first time.\n");
        printf("Would you like to create a new save file? [Y/N]");
        char opt;
        while (1){
            scanf("%s",&opt);
            if (opt == 'Y' || opt =='y' || opt == 'n' || opt == 'N') break;
        }
        if (opt == 'y' || opt == 'Y')
        {
            save = true;
        } else if (opt == 'n' || opt == 'N') {
            printSlow("\nWarning you will play the game without a save file\nYour progress won't be saved.");
            save = false;
        }    
    }
    if (save){
    savefile = fopen("dragonMix.savedisk","r");
    fscanf(savefile, "%d", &potionVis);
    fscanf(savefile, "%d", &potionTaint);
    fscanf(savefile, "%d", &money);
    fclose(savefile);
    }
    
    menu1:
    printf("\n");
    printSlow("What do you want to do?\n");
    printSlow("1. Make Potions\n");
    printSlow("2. Check Your Inventory\n");
    printSlow("3. Display Description of the game\n");
    printSlow("4. Sell Your Potions\n");
    printSlow("5. Exit the game\n");
    printSlow("So?: ");
    int option;
    scanf("%d",&option);
    switch (option)
    {
    case 1:
        clearTerm();
        printSlow("Enter the amout of mixings: ");
        scanf("%d",&mix);
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
        clearTerm();
        displayPotions(potionVis, potionTaint, money);
        break;
    case 3:
        clearTerm();
        printSlow("\nThe game princible is very simple.\nYou brew potions with vis and taint amount which are the ingridients. \nYou also chose how many times you will mix the brew. \nDepending on your luck (or rather some stupid math) you will brew a Good (Vis) or Bad (Tainted) potion.\n\n");
        break;
    case 4:
        clearTerm();
        printSlow("Current market values: \n");
        printSlow("Vis potion: ");
        printf("%lf\n",marketVis);
        printSlow("Taint potion: ");
        printf("%lf\n",marketTaint);
        printSlow("Do you want to sell?: [Y/N]");
        char opt2;
        scanf("%s",&opt2);
            if (opt2 == 'Y' || opt2 =='y'){
                money = money + round((marketVis * potionVis) + (marketTaint * potionTaint));
                potionVis = 0;
                potionTaint = 0;
            }
        break;
    case 5:
        if (save){savefile = fopen("dragonMix.savedisk","w");
        printf("Saving...\n");
        fprintf(savefile,"%d\n",potionVis);
        fprintf(savefile,"%d\n",potionTaint);
        fprintf(savefile,"%d",money);
        }
        printf("Exiting...");
        fclose(savefile);
        return 0;
    default:
        clearTerm();
        printSlow("Wrong Choice. Please Select Again.");
        break;
    }
    goto menu1;
    return 0;
}