
#include <stdio.h>


void printName() {
    printf("Hey!, Arun\n");
}

void personAge(int age) {
    printf("Age - %d\n", age);
}

int sum (int num1, int num2) {
    int num3 = num1+ num2;
    return num3;
}

int main() {
    puts("\n");
    
    printName();

    int age = 5;
    personAge(age);

    int num1 = 6, num2 = 9;
    int res = sum(num1, num2);

    printf("Result - %d", res);

    puts("\n");
    return 0;
}