#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>    //  header file to use windows API for multithreading
#include "radar.h"

#define CLEAR_SCREEN system("cls");         //  works on windows
//  #define CLEAR_SCREEN system("clear")    //  works on mac

int main() {

    int i, sampleLen, permLen, *weightage;
    CLEAR_SCREEN

    printf("Enter number of samples: ");
    scanf("%d", &permLen);
    CLEAR_SCREEN;

    weightage = (int*) malloc(sizeof(int)*sampleLen);

    // taking weightage in interactive way in CLI

    for(i = 0; i < sampleLen; ++i) {

        weightage[i] = -1;
    }

    for(i = 0; i < sampleLen; ++i) {

        printf("Total %d samples, Enter their weightage: ", sampleLen);
        for(j = 0; j < sampleLen; ++j) {

            if(weightage[j] == -1) {

                printf(" x");
            }
            else {

                printf(" %d", weightage[j]);
            }
        }

        printf("\nEnter the weightage of sample #%d:", i+1);
        scanf("%d", &weightage[i]);
        CLEAR_SCREEN;
    }
    printf("Weightage: ");
    for(i = 0; i < sampleLen; ++i) {

        printf("%d ", weightage[i]);
    }
    printf("\n");
    printf("Radar Frequency: %d\n", permLen);
    printf("\nPermutation Array:\n");

    // printing permutaion 
    randomize(sampleLen, permLen, weightage);

    return 0;
}