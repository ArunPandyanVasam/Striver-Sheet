#include <string.h>
#include <stdio.h>
#define SIZE 256

void doSomething(int num) {

}

int main() {
    puts("\n");
    
    char str[SIZE];
    printf("Input the string: ");
    fgets(str, sizeof(str), stdin);

    if (str[strlen(str)-1] == '\n') {
        str[strlen(str)-1] = '\0';
    }

    int n = strlen(str);
    printf ("Size of String: %d", n);

    int hash[SIZE] = {0};
    for (int i = 0; i < n; i++)
    {
       hash[str[i]]++; // hash[str[i] - 'a']++; Lowercase
    }

    int q;
    printf("\nInput number of queries: ");
    scanf("%d", &q);

    while (q--)
    {
        char c;
        printf("\nInput the character: ");
        scanf(" %c", &c);

        printf("%d", hash[c]); // printf("%d", hash[c - 'a']); Lowercase
    }
    
    
    
    


    

    puts("\n");
    return 0;
}