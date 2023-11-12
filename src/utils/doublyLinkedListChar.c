#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_MAX 20

typedef struct sNode
{
    char info[NAME_MAX];
    struct sNode *next;
    struct sNode *prev;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
    int size;
} List;

// ----------------------------------------------------------------------------------------

Node *createNode(char data[])
{
    Node *nodo;
    int size;
    nodo = (Node *)malloc(sizeof(Node));
    if (nodo != NULL)
    {
        size = strlen(data);
        for (int i = 0; i < size; i++)
        {
            nodo->info[i] = data[i];
        }
        nodo->next = NULL;
        nodo->prev = NULL;
    }
    return nodo;
}

List *allocList()
{
    List *queue;
    queue = (List *)malloc(sizeof(List));
    if (queue != NULL)
    {
        queue->head = NULL;
        queue->tail = NULL;
    }
    queue->size = 0;
    return queue;
}

void freeNode(Node *nodo)
{
    free(nodo);
}

void freeList(List *queue)
{
    Node *delNodo, *auxNodo;
    int i;
    delNodo = queue->head;
    for (i = 0; i < queue->size; i++)
    {
        auxNodo = delNodo->next;
        free(delNodo);
        delNodo = auxNodo;
    }
    free(queue);
}

int emptyList(List *list)
{
    if (list->size == 0)
    {
        return 1;
    }
    return 0;
}

int insertNodo(List *list, Node *pivo, char data[])
{
    Node *newNodo;
    newNodo = createNode(data);
    if ((pivo == NULL) && (emptyList(list) == 0))
    {
        return -1;
    }
    if (emptyList(list))
    {
        list->head = newNodo;
        list->tail = newNodo;
    }
    else
    {
        newNodo->next = pivo->next;
        newNodo->prev = pivo;

        if (pivo->next == NULL)
        {
            list->tail = newNodo;
        }
        else
        {
            pivo->next->prev = newNodo;
        }
        pivo->next = newNodo;
    }
    list->size++;
    return 1;
}

int removeNode(List *list, Node *pivo)
{
    if (emptyList(list))
    {
        return -2;
    }
    if ((pivo != NULL))
    {
        if (list->head == pivo)
        {
            list->head = pivo->next;
            if (list->head == NULL)
            {
                list->tail = NULL;
            }
            else
            {
                list->head->prev = NULL;
            }
        }
        else
        {
            pivo->prev->next = pivo->next;
            if (pivo->next == NULL)
            {
                list->tail = pivo->prev;
            }
            else
            {
                pivo->next->prev = pivo->prev;
            }
        }
        freeNode(pivo);
        list->size--;
        return 1;
    }
    return -3;
}

Node *searchInfo(List *list, char data[])
{
    int i;
    Node *nodo;
    nodo = list->head;
    for (i = 0; i < list->size; i++)
    {
        if (strcmp(nodo->info, data) == 0)
        {
            return nodo;
        }
        nodo = nodo->next;
    }
    return NULL;
}

int getSeachInfoPos(List *list, char data[])
{
    int i;
    Node *nodo;
    nodo = list->head;
    for (i = 0; i < list->size; i++)
    {
        if (strcmp(nodo->info, data) == 0)
        {
            return (i + 1);
        }
        nodo = nodo->next;
    }
    printf("Palavra %s nao encontrada!\n", data);
    return -1;
}

void printList(List *list)
{
    Node *nodo;
    if (emptyList(list))
    {
        printf("\nLista esta vazia!\n");
    }
    else
    {
        nodo = list->head;
        printf("\n<-- Lista -->\n");

        // for (int i = 0; i < list->size; i++)
        // {
        //     printf("%s\n", nodo->info);
        //     nodo = nodo->next;
        // }

        while (nodo != NULL)
        {
            printf("%s\n", nodo->info);
            nodo = nodo->next;
        }
    }
}

void errorTreatment(int error)
{
    if (error == -1)
    {
        printf("Pivo null so aceito na primeira insercao!\n");
    }
    else if (error == -2)
    {
        printf("\nA lista estah vazia por isso nao podera ser retirado nenhum valor!\n");
    }
    else if (error == -3)
    {
        printf("\nO elemento informado nao foi encontrado! nenhum outro elemento foi removido\n");
    }
}

void clearDoublyList(List *list)
{
    Node *nodo, *auxNodo;
    nodo = list->head;
    while (nodo != NULL)
    {
        auxNodo = nodo->next;
        free(nodo);
        nodo = auxNodo;
    }
    list->head == NULL;
    list->tail == NULL;
    list->size = 0;
}

void swapNodes(List *list, Node *nodo1, Node *nodo2)
{
    Node *auxPrev, *auxNext;
    //  atribuição nos campos das listas
    if (nodo1 == list->head)
    {
        list->head = nodo2;
    }
    else if (nodo2 == list->head)
    {
        list->head = nodo1;
    }
    if (nodo1 == list->tail)
    {
        list->tail = nodo2;
    }
    else if (nodo2 == list->tail)
    {
        list->tail = nodo1;
    }

    //  troca dos elementos
    auxNext = nodo1->next;
    auxPrev = nodo1->prev;
    //  verificação do nodo2
    if (nodo2->next == nodo1)
    {
        nodo1->next = nodo2;
    }
    else
    {
        nodo1->next = nodo2->next;
        if (nodo2->next != NULL)
        {
            nodo2->next->prev = nodo1;
        }
    }
    if (nodo2->prev == nodo1)
    {
        nodo1->prev = nodo2;
    }
    else
    {
        nodo1->prev = nodo2->prev;
        if (nodo2->prev != NULL)
        {
            nodo2->prev->next = nodo1;
        }
    }

    //  verificação do nodo1
    if (auxNext == nodo2)
    {
        nodo2->next = nodo1;
    }
    else
    {
        nodo2->next = auxNext;
        if (auxNext != NULL)
        {
            auxNext->prev = nodo2;
        }
    }
    if (auxPrev == nodo2)
    {
        nodo2->prev = nodo1;
    }
    else
    {
        nodo2->prev = auxPrev;
        if (auxPrev != NULL)
        {
            auxPrev->next = nodo2;
        }
    }
}

int getPos(List *list, Node *nodo) {
    Node *auxNodo;
    int pos;
    auxNodo = list->head;
    pos = 0;
    if (nodo == NULL) {
        return -1;
    }
    while (auxNodo != nodo) {
        pos++;
        auxNodo = auxNodo->next;
    }
    return pos;
}

Node *getNodeByPos(List *list, int pos) {
    Node *nodo;
    int count;
    nodo = list->head;
    count = 0;
    while (count < pos) {
        count++;
        nodo = nodo->next;
    }
    return nodo;
}