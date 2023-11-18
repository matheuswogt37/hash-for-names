#include <stdio.h>
#include <stdlib.h>
#include "utils/quickSortListChar.c"

int main()
{
    char data[20] = "SHARLITON";
    int hash = 11;
    int size = strlen(data);
    for (int i = 0; i < size; i++) {
        hash = hash*31 + data[i];
        printf("\n%c -> hash: %i", data[i], hash);
    }
    printf("\n%s : %i\n", data, hash);
    if (hash < 0) {
        hash *= -1;
    }
    hash = hash % 53;

    printf("%i\n", hash);

    printf("\n");
    return 0;
}