
#include <stdio.h>

void doSomething(int num) {

}

int main() {
    puts("\n");
    
    int n;
    printf("Input the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Input value at arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    int hash[13] = {0};
    for (int  i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }

    int q;
    printf("Input the number of queries: ");
    scanf("%d", &q);

    while (q--)
    {
        int searchNum;
        printf("\nInput the query value: ");
        scanf("%d", &searchNum);
        printf("The query value appeared: %d", hash[searchNum]);
    }
    
    


    

    puts("\n");
    return 0;
}