#ifndef ENDSTARTGAME_H
#define ENDSTARTGAME_H
#include <stdio.h>
#include <unistd.h>
#include "slowWriting.h"
//This function displays ending game screen
void splashScreen(){
    printSlow("                    :. .-. :=:  :\n");
    printSlow("                    ----.:-: :-:-.\n");
    printSlow("     :-:::-:.       .:.:-:::::-::\n");
    printSlow("   :-.      .-.   .-:.       ::.:-::\n");
    printSlow("  :: :-::     -..-..:       .:.    ::\n");
    printSlow("  - -  .-.  -..-:.-::-:.    ..   ..-:\n");
    printSlow("  - -  ..  -. .:.: -:-:.   -:-===--.   -\n");
    printSlow("  - -.    :::-:..::::::=-: :-:::--::::==--:::=-.\n");
    printSlow("  -: =   :==-.:.:-: -:-::-.:..... .:::.:-  .=:.\n");
    printSlow("   -. -.  ---::.-.: --:::-.-:.         -    .--\n");
    printSlow("    -..-. .. .-.- -.:--.-:--::-:      -:    :::.\n");
    printSlow("  ..-:  -.  .-:- ::.-.--.---::.=     -:  :::-:::\n");
    printSlow("  .--:   -:.-:- :: -:-::.: -.---:::.-.   -:\n");
    printSlow("   -=--   :--- .: -::. :-::=-:--   .    .::.\n");
    printSlow("   .---:   --:.-. --:.::. :.  :.       .--.:-:.\n");
    printSlow("    -=::   - ----::.-:         -.   .:-.   ..:-:\n");
    printSlow("    :=-.  .:  .:.:.             -.:-..    ..:-.\n");
    printSlow("    :-:.  :.   :      -          .      ..:----\n");
    printSlow("   :--.  ::   .:      .-:             -:::--...\n");
    printSlow("    -.  :-     :.       .-:.       ..::    .\n");
    printSlow("   .-  -.      .:          .:-. ...-:-\n");
    printSlow("  :: .-        .:            :-:--:\n");
    printSlow(" :. .-         .:           ::.=.\n");
    printSlow(".- .-          .:          .-\n");
    printSlow("-. :.          ::          -.\n");
    printSlow("=  :           :.       .  -.::::::.\n");
    printSlow("=  ::          :.       .- -.      .::-. \n");
    printSlow("::  -.        .:         .:-           :-\n");
    printSlow(" ::  --      :-.-         :-           .\n");
    printSlow("  ::   :-::-:.  :          ::         -:\n");
    printSlow("    :-:.      .:-           :.       -:    ::--==:\n");
    printSlow("       .::::::..-.          .-:-    :-    -: ::.\n");
    printSlow("                 -:         .:::   :-    -.  .-=: \n");
    printSlow("                   :-       ---    :::::::   ::.\n");
    printSlow("               .:-::     :-: :.          ..::-:\n");
    printSlow("           :-=-:.      :-.  .-::-  ::: .-:.\n");
    printSlow("             .----    --   .--:.-:-..:-:\n");
    printSlow("             :--:.     .-:.:.  .-.  .:\n");
    printSlow("               .:===.    .-:.:::\n");
    printSlow("                .:--..     ..  .-:\n");
    printSlow("                    .::-.  .  : .:\n");
    printSlow("                        :.-: -:--:\n");
    printSlow("     ___                            __  ____     \n");
    printSlow("    / _ \\_______ ____ ____  ___    /  |/  (_)_ __\n");
    printSlow("   / // / __/ _ `/ _ `/ _ \\/ _ \\  / /|_/ / /\\ \\ /\n");
    printSlow("  /____/_/  \\_,_/\\_, /\\___/_//_/ /_/  /_/_//_\\_\\ \n");
    printSlow("                /___/                            \n");
    printSlow("               *Press enter to play*             \n");
    while (getchar() != '\n');
}

void endGame(double vis, double taint, int mix){
    if(vis < taint){
      printSlow("___________        .__          __               .___\n");
      printSlow("\\__    ___/_____   |__|  ____ _/  |_   ____    __| _/\n");
      printSlow("  |    |   \\__  \\  |  | /    \\   __\\_/ __ \\  / __ | \n");
      printSlow("  |    |    / __ \\_|  ||   |  \\|  |  \\  ___/ / /_/ | \n");
      printSlow("  |____|   (____  /|__||___|  /|__|   \\___  >\\____ | \n");
      printSlow("                \\/          \\/            \\/      \\/ \n\n");
      printf("Vis: %lf units    Taint: %lf units",vis,taint);
      printf("\nMixings: %d times",mix);
      printSlow("\nLuck did not stand on your side.\nAll Vis energy vanished and turned into Taint\nOne Taint potion has been added to your inventory");

    } else if (vis > taint){
        printSlow("  _____                    __      __ _         ______                                 \n");
        printSlow(" |  __ \\                   \\ \\    / /(_)       |  ____|                                \n");
        printSlow(" | |__) |_   _  _ __  ___   \\ \\  / /  _  ___   | |__    _ __    ___  _ __  __ _  _   _ \n");
        printSlow(" |  ___/| | | || '__|/ _ \\   \\ \\/ /  | |/ __|  |  __|  | '_ \\  / _ \\| '__|/ _` || | | |\n");
        printSlow(" | |    | |_| || |  |  __/    \\  /   | |\\__ \\  | |____ | | | ||  __/| |  | (_| || |_| |\n");
        printSlow(" |_|     \\__,_||_|   \\___|     \\/    |_||___/  |______||_| |_| \\___||_|   \\__, | \\__, |\n");
        printSlow("                                                                           __/ |  __/ |\n");
        printSlow("                                                                          |___/  |___/ \n");
        printf("Vis: %lf units    Taint: %lf units",vis,taint);
        printf("\nMixings: %d times",mix);
        printSlow("\nLuck is on your side.\nAll Taint energy vanished and turned into Vis\nOne Vis potion has been added to your inventory");
    }
    printf("\n\n\n");
    sleep(2);


}

void cauldronAnim(int state){
    if (state > 6 || state < 0) {
        printf("Err: wrong argument");
    } else {
        switch (state)
        {
        case 0:
            printf("                      \n");
            printf("                      \n");
            printf("           ___________\n");
            printf("          (___________)\n");
            printf("           /         \\\n");
            printf("          /           \\\n");
            printf("         |             |\n");
            printf("     ____\\             /____\n");
            printf("    ()____'.__     __.'____()\n");
            printf("         .'` .'```'. `-. \n");
            printf("        ().'`       `'.()\n");
            break;
        case 1:
            printf("                      \n");
            printf("                      \n");
            printf("           _______)___\n");
            printf("          (___________)\n");
            printf("           /         \\\n");
            printf("          /           \\\n");
            printf("         |             |\n");
            printf("     ____\\             /____\n");
            printf("    ()____'.__     __.'____()\n");
            printf("         .'` .'```'. `-. \n");
            printf("        ().'`       `'.()\n");
            break;
        case 2:
            printf("                      \n");
            printf("                  )   \n");
            printf("           __)___(____\n");
            printf("          (___________)\n");
            printf("           /         \\\n");
            printf("          /           \\\n");
            printf("         |             |\n");
            printf("     ____\\             /____\n");
            printf("    ()____'.__     __.'____()\n");
            printf("         .'` .'```'. `-. \n");
            printf("        ().'`       `'.()\n");
            break;
        case 3:
            printf("                  (    \n");
            printf("              )   )   \n");
            printf("           __(________\n");
            printf("          (___________)\n");
            printf("           /         \\\n");
            printf("          /           \\\n");
            printf("         |             |\n");
            printf("     ____\\             /____\n");
            printf("    ()____'.__     __.'____()\n");
            printf("         .'` .'```'. `-. \n");
            printf("        ().'`       `'.()\n");
            break;
        case 4:
            printf("               )  (    \n");
            printf("              (      \n");
            printf("           ___________\n");
            printf("          (___________)\n");
            printf("           /         \\\n");
            printf("          /           \\\n");
            printf("         |             |\n");
            printf("     ____\\             /____\n");
            printf("    ()____'.__     __.'____()\n");
            printf("         .'` .'```'. `-. \n");
            printf("        ().'`       `'.()\n");
            break;
        case 5:
            printf("               (      \n");
            printf("                      \n");
            printf("           ___________\n");
            printf("          (___________)\n");
            printf("           /         \\\n");
            printf("          /           \\\n");
            printf("         |             |\n");
            printf("     ____\\             /____\n");
            printf("    ()____'.__     __.'____()\n");
            printf("         .'` .'```'. `-. \n");
            printf("        ().'`       `'.()\n");
        default:
            break;
        }
    }
}

void displayPotions(int a, int b,int c){
    printf("       .-.             :~:   \n");
    printf("     .'  (             | |   \n");
    printf("     |~~~|            .' `.  \n");
    printf("     | V |          .'  T  `.\n");
    printf("     |   |          |       |\n");
    printf("     |___|           `.._..' \n");
    printSlow("Vis Potions: ");
    printf("%d",a);
    printSlow("  Taint Potions: ");    
    printf("%d\n",b);
    printSlow("And T$");
    printf("%d",c);
    printSlow(" (Tokens)\n");
}

#endif