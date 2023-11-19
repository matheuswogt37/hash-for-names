#include <stdio.h>
#include <stdlib.h>
#include "hash.c"

int main()
{
    HashTable *hashTable;
    hashTable = iniciateHash();

    hashInsert("jonas ", hashTable);
    hashInsert("cabra ", hashTable);
    hashInsert("leo ", hashTable);
    hashInsert("barrack ", hashTable);

    getAllElements(hashTable);

    hashRemove("jonas ", hashTable);

    getAllElements(hashTable);

    printf("\nfoi");

    printf("\n");
    return 0;
}