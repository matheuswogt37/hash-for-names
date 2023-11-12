#include <stdio.h>
#include <stdlib.h>
#include "utils/quickSortListChar.c"

int main()
{
    List *list;
    list = allocList();
    insertNodo(list, list->head, "capacete");
    insertNodo(list, list->head, "abacate");
    insertNodo(list, list->head, "trilha");
    insertNodo(list, list->head, "debug");
    // insertNodo(list, list->head, "cabra");
    // insertNodo(list, list->head, "tez");

    printList(list);
    printf("\n");

    // int res1 = isSmaller(list->tail, list->head);
    // printf("\n%i\n", res1);

    quickSort(list, 0, (list->size - 1));
    // swapNodes(list, list->head, list->head);

    printList(list);

    printf("\nfoi");

    printf("\n");
    return 0;
}