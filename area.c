#include "area.h"

void runArea(){

    char cInput = '0';
    int nPlayerLife = 3;
    int aTiles[7] = {1, 0, 0, 2, 0, 3, 0};

    printf("\x1b[0m");
    

    do {
        displayArea(aTiles, 7, nPlayerLife);
        scanf(" %c", &cInput);
        processAreaInput(cInput, aTiles, 7);
        }
        while (cInput != '0');



}

void displayArea(int* pTiles, int nSize, int* pPlayerLife){
    printf("\n");
    printf("\t\t╔════════════════════╗ \n");
    printf("\t\t│        AREA        │ \n");
    printf("\t\t╚════════════════════╝ \n");
    displayAreaBoard(pTiles, nSize); // call display area board
    printf("\t[PLAYER] : ");
    for(int i = 0; i < *pPlayerLife; i++){
        print("♥");
    }
    printf("\n");
    printf("\t[INPUT] : ");
}

void displayAreaBoard(int* pTiles, int nSize){

    printf("\t ");
    for(int i = 0; i < nSize; i++) {
            switch(pTiles[i]) {
                case 5:
                    printf("\x1b[38;5;46m╔═══╗"); // turn green (in interactive tile)
                    printf("\x1b[0m");
                    break;                
                case 4:
                    printf("\x1b[38;5;46m╔═══╗"); // turn green (in interactive tile)
                    printf("\x1b[0m");
                    break;
                case 3:
                    printf("\x1b[38;5;242m┌┬┬┬┐");
                    printf("\x1b[0m"); // damage
                    break;
                case 2:
                    printf("\x1b[38;5;242m┌┬┬┬┐");
                    printf("\x1b[0m"); // item
                    break;
                case 1:
                    printf("\x1b[38;5;242m╔═══╗");
                    printf("\x1b[0m");
                    break;

                case 0:
                    printf("┌───┐");
                    break;
            }
    }
    printf("\n");

    printf("\t ");
    for(int i = 0; i < nSize; i++) {
        switch(pTiles[i]) {
            case 5:
                printf("║ ■ ║");
                break;
            case 4:
                printf("║ ■ ║");
                break;
            case 3: // damage
                printf("│││││");
                break;
            case 2: // item
                printf("│││││");
                break;
            case 1:
                printf("║ ■ ║");
                break;

            case 0:
                printf("│   │");
                break;
            }
    }
    printf("\n");

    printf("\t ");
    for(int i = 0; i < nSize; i++) {

            switch(pTiles[i]) {
                case 5:
                    printf("╚═══╝");
                    break;
                case 4:
                    printf("╚═══╝");
                    break;
                case 3:
                    printf("└┴┴┴┘");
                    break;
                case 2:
                    printf("└┴┴┴┘");
                    break;
                case 1:
                    printf("╚═══╝");
                    break;

                case 0:
                    printf("└───┘");
                    break;
            }
    }
    printf("\n");
}


void processAreaInput(char cInput, int* pTiles, int nSize) {

    int nFound = 0;

	switch(cInput) { // -1 if a +1 if d
        case 'a':
        case 'A':
        for(int i = 0; i < nSize && nFound == 0; i++) {
            if (pTiles[0] == 1){
                nFound = 1;
            }
            else if(pTiles[i] == 5){
                pTiles[i] = 3;
                pTiles[i-1] = 1;
                nFound = 1;
            }
            else if(pTiles[i] == 4){
                pTiles[i] = 2;
                pTiles[i-1] = 1;
                nFound = 1;
            }
            else if(pTiles[i] == 3){
                pTiles[i] = 0;
                pTiles[i-1] = 5;
                nFound = 1;
            }
            else if(pTiles[i] == 2){
                pTiles[i] = 0;
                pTiles[i-1] = 4;
                nFound = 1;
            }
            else if(pTiles[i] == 1){
                pTiles[i] = 0;
                pTiles[i-1] = 1;
                nFound = 1;
            }
        }
            break;
        case 'd':
        case 'D':
        for(int i = 0; i < nSize && nFound == 0; i++) {
             if (pTiles[nSize-1] == 1){
                nFound = 1;
            }
            else if(pTiles[i] == 5){
                pTiles[i] = 3;
                pTiles[i+1] = 1;
                nFound = 1;
            
            }
            else if(pTiles[i] == 4){
                pTiles[i] = 2;
                pTiles[i+1] = 1;
                nFound = 1;
            }
            else if(pTiles[i] == 3){
                pTiles[i] = 0;
                pTiles[i + 1] = 5;
                nFound = 1;
            }   
            else if(pTiles[i+1] == 2){
                pTiles[i] = 0;
                pTiles[i + 1] = 4;
                nFound = 1;
            }   
            else if(pTiles[i] == 1){
                pTiles[i] = 0;
                pTiles[i+1] = 1;
                }
                nFound = 1;
        }
        
            break;

        //case 'i':
        //case 'I':
        //runInventory();
       // break;
    }

}
