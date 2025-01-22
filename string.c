
#include <stdio.h>
#include <string.h>

int main() {
    puts("\n");
    //   we can perform operations on strings
    char str[] = "Hello!";
    printf("%c", str[2]);
    puts("\n");
    int len = strlen(str);
    str[len-1] = 'Z';
    printf("%c", str[len-1]);
    puts("\n");
    return 0;
}