
#include <stdio.h>

void doSomething(int num) {
    printf("%d\n", num);
    num += 5;
    printf("%d\n", num);
    num += 5;
    printf("%d\n", num);
}

int main() {
    puts("\n");
    
    int num = 10;
    doSomething(num);
    printf("%d\n", num);

    puts("\n");
    return 0;
}