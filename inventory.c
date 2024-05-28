#include "inventory.h"

void runInventory() {
	int nInput = -1;

	do {
		displayInventory();
		scanf("%d", &nInput);
		processInventory(nInput);
	} while(nInput != 0);
}

void displayInventory() {
    printf("\n");
    printf("\t╔════════════════════╗ \n");
    printf("\t│      INVENTORY     │ \n");
    printf("\t╚════════════════════╝ \n");
    printf("\t   [0] Exit");
    printf("\n");
    printf("\t[INPUT] : ");
}

void displayAreaBoard(int* pTiles, int nSize){

    printf("\t ");
    for(int i = 0; i < nSize; i++) {
           switch(pTiles[i]) {
                case 0:
                    printf("┌───┐");
                    if(i = 3);
                    printf("\n");
                    break;
           }
    }
    printf("\n");

    printf("\t ");
    for(int i = 0; i < nSize; i++) {
           switch(pTiles[i]) {
                case 0:
                    printf("│   │");
                    break;
           }
    }
    printf("\n");

    printf("\t ");
    for(int i = 0; i < nSize; i++) {
           switch(pTiles[i]) {
                case 0:
                    printf("└───┘");
                    break;
           }
    }
    printf("\n");
}

void processInventory(int nInput) {
	switch(nInput) {}
}