#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils/doublyLinkedListChar.c"
#define HASH_SIZE 53
#define MAX_STRING_SIZE 20

typedef struct
{
    List *col[HASH_SIZE];
} HashTable;

// -----------------------------------------------------------------------

HashTable *iniciateHash()
{
    HashTable *table;
    table = (HashTable *) malloc(sizeof(HashTable));
    for (int i = 0; i < HASH_SIZE; i++)
    {
        table->col[i] = allocList();
    }
    return table;
}

int stringToAscii(char data[MAX_STRING_SIZE])
{
    int size = strlen(data);
    int ascii = 0;
    for (int i = 0; i < size; i++)
    {
        ascii += data[i];
    }
    return ascii;
}

int hashFunction(char data[MAX_STRING_SIZE])
{
    int hash = 7;
    int size = strlen(data) - 1;
    for (int i = 0; i < size; i++) {
        hash = hash*31 + data[i];
    }
    if (hash < 0) {
        hash *= -1;
    }
    hash = hash % HASH_SIZE;
    return hash;
}

//  inserção

void hashInsert(char data[MAX_STRING_SIZE], HashTable *hashTable)
{
    int hashNumber = hashFunction(data);
    List *list = hashTable->col[hashNumber];
    errorTreatment(insertNodo(list, list->tail, data));
}

//  consulta

void hashSearch(char data[MAX_STRING_SIZE], HashTable *hashTable)
{
    int hashNumber = hashFunction(data);
    List *list = hashTable->col[hashNumber];
    int pos = getSeachInfoPos(list, data);
    if (pos == -1)
    {
        printf("Nome nao encontrado!\n");
    }
    else
    {
        printf("Nome %s encontrado na coluna %i e posicao %i\n", data, hashNumber, pos);
    }
}

//  quantidade de elementos por chave
void getAllElements(HashTable *hashTable)
{
    List *list;
    int qtd;
    printf("Quantidade de elementos da tabela\n");
    for (int i = 0; i < HASH_SIZE; i++)
    {
        list = hashTable->col[i];
        printf("%i - %i\n", (i + 1), list->size);
    }
    printf("\n");
}

// quantidade de elementos na chave
void getElementsInCol(HashTable *hashTable, int col)
{
    List *list;
    int qtd;
    if ((col - 1) < HASH_SIZE)
    {
        printf("Quantidade de elementos na coluna %i - %i\n", col, hashTable->col[col - 1]->size);
    }
    else
    {
        printf("Nao existe %i coluna\n", col);
    }
    printf("\n");
}

//  remoção
void hashRemove(char data[MAX_STRING_SIZE], HashTable *hashTable)
{
    int hashNumber = hashFunction(data);
    List *list = hashTable->col[hashNumber];
    errorTreatment(removeNode(list, searchInfo(list, data)));
}

void freeHash(HashTable *hTable)
{
    for (int i = 0; i < HASH_SIZE; i++)
    {
        if (hTable->col[i] != NULL)
        {
            freeList(hTable->col[i]);
        }
    }
    free(hTable);
}