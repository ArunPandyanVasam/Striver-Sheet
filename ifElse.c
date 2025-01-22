
#include <stdio.h>

int main()
{
    puts("\n");
    int age;
    printf("Enter Age: ");
    scanf("%d", &age);

    if (age >= 18)
    {
        printf("You are an adult: \n");
    }
    else
    {
        printf("You are not an adult: \n");
    }

    puts(" ");

    int marks;
    printf("Enter the marks: ");
    scanf("%d", &marks);

    if (marks < 25)
    {
        printf("F\n");
    }
    else if (marks <= 44)
    {
        printf("E\n");
    }
    else if (marks <= 49)
    {
        printf("D\n");
    }
    else if (marks <= 59)
    {
        printf("C\n");
    }
    else if (marks <= 79)
    {
        printf("B\n");
    }
    else if (marks <= 100)
    {
        printf("A\n");
    }

    puts(" ");

    int retirementAge;
    printf("Enter the Retirement Age: ");
    scanf("%d", &retirementAge);

    if (retirementAge < 18)
    {
        printf("not eligible for job\n");
    }
    else if (retirementAge <= 57)
    {
        printf("eligible for job\n");
        if (retirementAge >= 55)
        {
            printf(", but retirement soon\n");
        }
    }
    else
    {
        printf("retirement time\n");
    }

    puts("\n");
    return 0;
}