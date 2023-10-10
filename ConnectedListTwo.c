#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char value[7];  
    int next;
}Node;

int main()
{
    int amountOfTests;
    scanf("%d", &amountOfTests);
    for (int test = 0; test < amountOfTests; ++test)
    {
        int amountOfElements, firstIndex, amountOfOperations;
        scanf("%d %d %d", &amountOfElements, &firstIndex, &amountOfOperations);
        Node array[amountOfElements];
        for(int step = 0; step < amountOfElements; ++step)
        {
            scanf("%s %d", array[step].value, &array[step].next);
        }
        for (int step = 0; step < amountOfOperations; ++step)
        {
            int typeOfOperation, workingIndex;
            char newValue[7];
            scanf("%d", &typeOfOperation);
            if( typeOfOperation == 0)
            {
                scanf("%d %s", &workingIndex, newValue);
                if(workingIndex < 0)
                {
                    int newIndex;
                    newIndex = amountOfElements++;
                    strcpy(array[newIndex].value, newValue);
                    array[newIndex].next = firstIndex;
                    firstIndex = newIndex;
                    printf("%d\n", amountOfElements);
                }
                else
                {
                    int newIndex = amountOfElements++;
                    array[newIndex].next = array[workingIndex].next;
                    array[workingIndex].next = newIndex;
                    strcpy(array[newIndex].value,newValue);
                    printf("%d\n", newIndex);
                }
            }
            else
            {
                scanf("%d", &workingIndex);
                array[workingIndex].next = array[array[workingIndex].next].next;
            }
            if (step == amountOfOperations - 1)
            {
                printf("===\n");
            }
        }
        int lastIndex;
        for (int step = firstIndex; step >= 0; step = array[step].next)
        {
            printf("%s\n", array[step].value);
            lastIndex = step;
        }
        printf("%s\n", array[lastIndex].value);
        printf("===\n");
    }
    return 0;
}