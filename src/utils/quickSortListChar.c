#include <stdio.h>
#include "doublyLinkedListChar.c"

Node *getPivo(List *list, Node *init, Node *final)
{
    Node *i, *j;
    i = init;
    j = final;

    while (i != j || i != j->next)
    {
        i = i->next;
        j = j->prev;
    }
    return i;
}

int isSmaller(Node *small, Node *big)
{
    int res1 = strcmp(small->info, big->info);

    if (res1 < 0)
    {
        return 1;
    }
    if (res1 > 0)
    {
        return 2;
    }
    return 0;
}

Node *getPivoByPos(Node *init, Node *final)
{
    if ((init != final) && (init->next != final))
    {
        init = init->next;
        final = final->prev;
    }
    return init;
}

List *quickSort(List *list, Node *initNodo, Node *finalNodo)
{
    Node *i, *j, *pivo;
    int iCont, jCont;

    i = initNodo;
    j = finalNodo;
    pivo = getPivoByPos(i, j);
    printf("\n%s\n", pivo->info);
    while ((i != j) && (i->next != j))
    {
        while (isSmaller(i, pivo) == 1)
        {
            i = i->next;
        }
        while (isSmaller(j, pivo) == 2)
        {
            j = j->prev;
        }
        swapNodes(list, i, j);
        i = i->next;
        j = j->prev;
        // if (isSmaller(i, j) != 2)
        // {
        //     swapNodes(list, i, j);
        //     i = i->next;
        //     j = j->prev;
        // }
    }
    if (isSmaller(initNodo, j) == 1)
    {
        quickSort(list, initNodo, j);
    }
    if (isSmaller(i, finalNodo) == 1)
    {
        quickSort(list, i, finalNodo);
    }
}