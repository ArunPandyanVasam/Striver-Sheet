#include <stdio.h>
#include <string.h>

#define SIZE 10

// Define a structure for each student in the hash table
typedef struct Student
{
    int roll;
    char name[100];
    int isOccupied; // 0 = empty, 1 = filled
} Student;

Student table[SIZE];

// Hash Function
int hash(int roll)
{
    return roll % SIZE;
}

// Insert Function with Linear Probing
void insert(int roll, char name[])
{
    int index = hash(roll);

    while (table[index].isOccupied)
    {
        index = (index + 1) % SIZE;
    }

    table[index].roll = roll;
    strcpy(table[index].name, name);
    table[index].isOccupied = 1; // Mark the slot as occupied
}

// Display Function
void display()
{
    for (int i = 0; i < SIZE; i++)
    {
        if (table[i].isOccupied)
        {
            printf("Index %d → Roll: %d, Name: %s\n", i, table[i].roll, table[i].name);
        }
        else
        {
            printf("Index %d → Empty\n", i);
        }
    }
}

int main(void)
{
    // Initialize table entries as empty
    for (int i = 0; i < SIZE; i++)
    {
        table[i].isOccupied = 0;
    }

    // Test insertions
    insert(101, "Arun");
    insert(111, "Vijay"); // Collision → goes to next
    insert(121, "Meena"); // Collision again → next

    // Show the hash table
    display();

    return 0;
}
