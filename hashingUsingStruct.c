#include <stdio.h>
#include <string.h>

#define SIZE 10

// Define a structure for each hash table entry
typedef struct Student
{
    int roll;
    char name[100];
} Student;

Student table[SIZE];

// Hash Function
int hash(int key)
{
    return key % SIZE;
}

// Insert Function
void insert(int roll, char name[])
{
    int index = hash(roll);

    table[index].roll = roll;
    strcpy(table[index].name, name);
}

// Display Function
void display()
{
    for (int i = 0; i < SIZE; i++)
    {
        if (table[i].roll != 0)
        {
            printf("Index %d → Roll: %d, Name: %s\n", i, table[i].roll, table[i].name);
        }
        else
        {
            printf("Index %d → Empty\n", i);
        }
    }
}

int main()
{
    // Initialize with 0 roll = empty
    for (int i = 0; i < SIZE; i++)
    {
        table[i].roll = 0;
    }

    insert(101, "Arun");
    insert(112, "Vijay");
    insert(124, "Meena");

    display();
    return 0;
}