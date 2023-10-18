#include <stdio.h>
#include <stdlib.h>
#define additionBefore -1
#define additionAfter 1
#define deletion 0

typedef struct Node_s {
struct Node_s * prev , * next ;
void * value ;
} Node ;

//List –- вспомогательный узел, являющийся головой списка
typedef Node List ;

//инициализирует поля структуры *list значениями для пустого списка
void initList ( List * list )
{
    list = malloc(sizeof(Node));
    list->next = list;
    list->prev = list;
}

//создаёт новый узел со значением ptr и вставляет его после узла node
//возвращает указатель на созданный узел
Node * addAfter ( Node * node , void * ptr )
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    node->next->prev = newNode;
    newNode->next = node->next;
    node->next = newNode;
    newNode->prev = node;
    newNode->value = ptr;
    return newNode;
}

//создаёт новый узел со значением ptr и вставляет его перед узлом node
//возвращает указатель на созданный узел
Node * addBefore ( Node * node , void * ptr )
{
    Node *newNode = (Node*)malloc(sizeof(Node)); 

    newNode->next = node;
    printf("====\n");
    node->prev->next = newNode;
    printf("====\n");
    node->prev = newNode;
    newNode->value = ptr;
    printf("====\n");
    newNode->prev = node->prev;
    return newNode;
}

//удаляет заданный узел, возвращая значение, которое в нём лежало
void * erase ( Node * node )
{
    node->next->prev = node->prev;
    node->prev->next = node->next;
    void* value = node->value;
    free(node);
    return value;
}
Node* array0[100001];
Node** array = array0 + 1;
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int Tests, amountOfOperations;
    scanf("%d", &Tests);
    for (int test = 1; test <= Tests; test++)
    {
        List *linkedList;
        initList(linkedList);
        array[-1] = linkedList;
        int amountOfNodesInArray = 0;
        scanf("%d", &amountOfOperations);
        
        for (int operation = 1; operation <= amountOfOperations; ++operation)
        {
            int typeOfOperation, operationalIndex;
            scanf("%d %d", &typeOfOperation, &operationalIndex);
            Node *currentNode = array[operationalIndex];
            //scanf("%d", &value);
            if (typeOfOperation == additionAfter)
            {
                int value;
                void *valueP = malloc(sizeof(int));
                
                scanf("%d", &value);
                *((int*)valueP) = value;
                array[amountOfNodesInArray++] = addAfter(currentNode, valueP);
                 
            }
            else if (typeOfOperation == additionBefore)
            {
                int value;
                void *valueP = malloc(sizeof(int));
                scanf("%d", &value);
                *((int*)valueP) = value;
                array[amountOfNodesInArray++] = addBefore(currentNode, valueP);
                
            }
            else
            {
                free(erase(currentNode));
            }
        }
        printf("===\n");
        for (Node* step = linkedList->next; step->next != linkedList; step = step->next)
        {
            printf("%d\n", *((int*)step->value));
        }
        printf("===\n");
        Node* step = linkedList->next;
        while(step != linkedList)
        {
            Node *temporaryNode = step->next;
            free(step);
            step = temporaryNode;
        }
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}