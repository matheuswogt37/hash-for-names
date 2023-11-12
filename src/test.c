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

    printList(list);
    printf("\n");

    // int res1 = isSmaller(list->tail, list->head);
    // printf("\n%i\n", res1);

    // quickSort(list, list->head, list->tail);
    swapNodes(list, list->head, list->tail);

    printList(list);



    printf("\nfoi");

    printf("\n");
    return 0;
}