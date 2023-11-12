#include<stdio.h>
#include "quickSortListChar.c"

int main()
{
    List *queue;
    queue = allocList();
    insertNodo(queue, queue->head, "abacate");
    insertNodo(queue, queue->head, "BATATA");
    insertNodo(queue, queue->head, "pinhao");

    // quickSort(queue, queue->head, queue->tail);

    printList(queue);

    swapNodes(queue, queue->head, queue->head->next);

    printList(queue);

    freeList(queue);
    return 0;
}