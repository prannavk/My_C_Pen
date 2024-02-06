#include <stdio.h>
#include <stdlib.h>
#define LASTLEVELMISSRATE 0.0

unsigned short int memoryLevels = 0;

float calcMissPenalty(int trav, float ***data);

int main()
{

    printf("\nEnter levels:\n");
    scanf("%u", &memoryLevels);
    printf("\nNow Enter hit-ratio and access time for all the %u levels as \n hx : ax\n(Hit Ratio of Last level is taken as 1)\n", memoryLevels);

    float **dataArray = (float **)calloc(memoryLevels, sizeof(float *));

    if (dataArray == NULL)
    {
        printf("Program failed try again");
        return 1;
    }

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
        *(dataArray + i) = inpValuesSet;    
    }

    printf("\nFor What you have entered:\n");
    
    for (int i = 0; i < memoryLevels; i++)
    {
        printf("\n%0.3f miss-ratio : %0.3f access-time\n", **(dataArray + i), *(*(dataArray + i) + 1));
    }

    printf("\nAverage Access Time is:\n%f\n", calcMissPenalty(0, &dataArray));

    for (int i = 0; i < memoryLevels; i++)
    {
        free(dataArray + i);
    }
    free(dataArray);

    return 0;
}

// Average Access Time in Memory Recursive Program
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