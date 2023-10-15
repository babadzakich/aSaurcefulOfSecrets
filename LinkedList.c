#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
}Node;

int main()
{
    Node *first, *currentNode, *temporaryNode;
    int amountOfNodes;
    scanf("%d", &amountOfNodes);
    for (int step = 0; step < amountOfNodes; ++step)
    {
    int currentValue;
        scanf("%d", &currentValue);
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
        if(step->value <10)
        {
            continue;
        }
        printf("%d\n", step->value);
    }
    Node* step = first;
    while (step)
    {
        temporaryNode = step->next;
        free(step);
        step = temporaryNode;
    }
    free(first);
    free(currentNode);
    return 0;
}