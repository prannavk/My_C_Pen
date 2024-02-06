#include <stdio.h>
#include <stdlib.h>
#define LASTLEVELMISSRATE 0.0

unsigned short int memoryLevels = 0;

float calcMissPenalty(int trav, float ***data);
unsigned short int initDataArray(float ***dataArray);
void displayInputData(float ***dataArray);
void deInitData(float ***dataArray);

// Average Access Time in Memory Recursive Program
int main()
{

    printf("\nEnter Memory levels:\n");
    scanf("%u", &memoryLevels);

    float **dataArray = (float **)calloc(memoryLevels, sizeof(float *));
    if (dataArray == NULL)
    {
        printf("Program failed try again");
        return 1;
    }

    if(initDataArray(&dataArray) == 1)
        return 1;

    displayInputData(&dataArray);

    printf("\nCalculated Average Access Time is:\n0.3%f\n", calcMissPenalty(0, &dataArray));

    deInitData(&dataArray);

    return 0;
}

// Calculating Miss Penalty at each stage to calculate average access time(Ta)
// Ta = Access time of L1 + Miss rate of L1 * (Miss Penalty of L1)
// Miss Penalty of Li = Access Time of Li+1 + Miss Rate of Level Li+1 * Miss Penalty of Level Li+1
// Miss rate of the last level is 0
// Miss Penalty of 2nd last level = Access Time of Last Level
float calcMissPenalty(int trav, float ***data) {
    if(trav == (memoryLevels - 1))
        return *(*(*data + trav) + 1);
    else 
        return *(*(*data + trav) + 1) + *(*(*data + trav) + 0) * calcMissPenalty(trav + 1, data);    
}

unsigned short int initDataArray(float ***dataArray) {
    printf("\nNow Enter hit-ratio and access time for all the %u levels as \n hx : ax\n(Hit Ratio of Last level is taken as 1)\n", memoryLevels);

    for (int i = 0; i < memoryLevels; i++)
    {
        printf("\nEnter set %d:\n", i);
        float *inpValuesSet = (float*) calloc(2, sizeof(float));
        if(inpValuesSet == NULL) {
            printf("Program failed try again");
            return 1;
        }
        scanf("%f : %f", inpValuesSet, inpValuesSet + 1);
        if(*inpValuesSet >= 1.0)
            *inpValuesSet = 0.5;
        if (i == memoryLevels - 1)
            inpValuesSet[0] = LASTLEVELMISSRATE;
        else
            inpValuesSet[0] = 1 - inpValuesSet[0];    
        **(dataArray + i) = inpValuesSet;    
    }
    return 0;    
}

void displayInputData(float ***dataArray) {
    printf("\nEntered Data as calculated miss ratio and access time:\n");
    for (int i = 0; i < memoryLevels; i++)
    {
        printf("\n%0.3f miss-ratio : %0.3f access-time\n", **(*dataArray + i), *(*(*dataArray + i) + 1));
    }
}

void deInitData(float ***dataArray) {
    for (int i = 0; i < memoryLevels; i++)
    {
        free(*dataArray + i);
    }
    free(*dataArray);
}