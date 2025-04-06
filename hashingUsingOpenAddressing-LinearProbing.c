#include <stdio.h>
#include <string.h>

#define SIZE 10

typedef struct Student
{
    int roll;
    char name[100];
    int isOccupied; // 0 = empty, 1 = filled, -1 = deleted (tombstone)
} Student;

Student table[SIZE];

int hash(int roll)
{
    return roll % SIZE;
}

// Insert with linear probing
void insert(int roll, char name[])
{
    int index = hash(roll);
    int originalIndex = index;

    while (table[index].isOccupied == 1)
    {
        index = (index + 1) % SIZE;
        if (index == originalIndex)
        {
            printf("Hash table is full!\n");
            return;
        }
    }

    table[index].roll = roll;
    strcpy(table[index].name, name);
    table[index].isOccupied = 1;
}

// Search by roll number
int search(int roll)
{
    int index = hash(roll);
    int startIndex = index;

    while (table[index].isOccupied != 0)
    {
        if (table[index].isOccupied == 1 && table[index].roll == roll)
        {
            return index; // Found
        }
        index = (index + 1) % SIZE;
        if (index == startIndex)
            break; // full loop
    }

    return -1; // Not found
}

// Delete by roll number
void delete(int roll)
{
    int index = search(roll);
    if (index != -1)
    {
        table[index].isOccupied = -1; // Mark as deleted (tombstone)
        printf("Roll %d deleted from index %d\n", roll, index);
    }
    else
    {
        printf("Roll %d not found. Cannot delete.\n", roll);
    }
}

// Display table
void display()
{
    for (int i = 0; i < SIZE; i++)
    {
        if (table[i].isOccupied == 1)
        {
            printf("Index %d → Roll: %d, Name: %s\n", i, table[i].roll, table[i].name);
        }
        else if (table[i].isOccupied == -1)
        {
            printf("Index %d → Deleted\n", i);
        }
        else
        {
            printf("Index %d → Empty\n", i);
        }
    }
}

int main(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        table[i].isOccupied = 0;
    }

    insert(101, "Arun");
    insert(111, "Vijay");
    insert(121, "Meena");

    display();

    printf("\nSearching for Roll 111...\n");
    int pos = search(111);
    if (pos != -1)
        printf("Found at index %d\n", pos);
    else
        printf("Not found\n");

    printf("\nDeleting Roll 111...\n");
    delete (111);

    printf("\nAfter deletion:\n");
    display();

    return 0;
}
