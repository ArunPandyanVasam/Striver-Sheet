#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

#define SIZE 10

int hash(int key)
{
    return key % SIZE;
}

void insert(int table[], int key)
{
    int index = hash(key);
    table[index] = key;
}

void display(int table[])
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("Index %d: %d\n", i, table[i]);
    }
}

int main()
{
    int table[SIZE];

    // Initialize with -1 (means empty)
    for (int i = 0; i < SIZE; i++)
    {
        table[i] = -1;
    }

    insert(table, 42);
    insert(table, 23);
    insert(table, 34);

    display(table);
    return 0;
}
