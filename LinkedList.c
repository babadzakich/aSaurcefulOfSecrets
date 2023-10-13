#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    double value;
    struct Node* next;
}Node;

int main()
{
    Node *first, *currentNode;
    int amountOfNodes = 2;
    for (int step = 0; step < amountOfNodes; ++step)
    {
        double currentValue;
        scanf("%lf", &currentValue);
        if (step == 0)
        {
            first = malloc(sizeof(Node));
            first->value = currentValue;
            currentNode = first;
            continue;
        }
        currentNode->next = malloc(sizeof(Node));
        currentNode->next->value = currentValue;
        currentNode = currentNode->next;
    }
    for (Node *step = first; step; step = step->next)
    {
        printf("%lf\n", step->value);
    }
    free(first);
    free(currentNode);
    return 0;
}