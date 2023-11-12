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
    printf("\nsmall -> %s\nbig -> %s\n", small->info, big->info);
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

Node *getPivoByPos(Node *i, Node *f)
{
    Node *init, *final;
    init = i;
    final = f;
    while ((init != final) && (init != final->next))
    {
        init = init->next;
        final = final->prev;
    }
    return init;
}

List *quickSort(List *list, int initNodo, int finalNodo)
{
    Node *i, *j, *pivo, *aux;
    int iCont, jCont;

    i = getNodeByPos(list, initNodo);
    j = getNodeByPos(list, finalNodo);
    pivo = getPivoByPos(i, j);
    printf("\npivo -> %s", pivo->info);
    printf("\ninicial -> %i\nfinal -> %i\n", initNodo, finalNodo);
    while (getPos(list, i) <= getPos(list, j))
    {
        while (isSmaller(i, pivo) == 1)
        {
            i = i->next;
        }
        while (isSmaller(j, pivo) == 2)
        {
            j = j->prev;
        }
        if (getPos(list, i) <= getPos(list, j))
        {
            printf("\nantes\ni -> %s\nj -> %s\n", i->info, j->info);
            swapNodes(list, i, j);
            aux = i;
            i = j;
            j = aux;
            i = i->next;
            j = j->prev;
            printf("\ndepois\ni -> %s\nj -> %s\n", i->info, j->info);
        }
        printf("-----------------------------------------------------------------------------------------");
    printList(list);
    }
    if (getPos(list, getNodeByPos(list, initNodo)) < getPos(list, j))
    {
        quickSort(list, initNodo, getPos(list, j));
    }
    if (getPos(list, i) < getPos(list, getNodeByPos(list, finalNodo)))
    {
        quickSort(list, getPos(list, i), finalNodo);
    }

    // Node *i, *j, *pivo, *aux;
    // int iCont, jCont;

    // i = initNodo;
    // j = finalNodo;
    // pivo = getPivoByPos(initNodo, finalNodo);
    // printf("\npivo -> %s", pivo->info);
    // printf("\ninicial -> %s\nfinal -> %s\n", initNodo, finalNodo);
    // while (getPos(list, i) <= getPos(list, j))
    // {
    //     while (isSmaller(i, pivo) == 1)
    //     {
    //         i = i->next;
    //     }
    //     while (isSmaller(j, pivo) == 2)
    //     {
    //         j = j->prev;
    //     }
    //     if (getPos(list, i) <= getPos(list, j))
    //     {
    //         printf("\nantes\ni -> %s\nj -> %s\n", i->info, j->info);
    //         swapNodes(list, i, j);
    //         aux = i;
    //         i = j;
    //         j = aux;
    //         i = i->next;
    //         j = j->prev;
    //         printf("\ndepois\ni -> %s\nj -> %s\n", i->info, j->info);
    //     }
    //     printf("-----------------------------------------------------------------------------------------");
    // printList(list);
    // }
    // if (getPos(list, initNodo) < getPos(list, j))
    // {
    //     quickSort(list, initNodo, j);
    // }
    // if (getPos(list, i) < getPos(list, finalNodo))
    // {
    //     quickSort(list, i, finalNodo);
    // }
}