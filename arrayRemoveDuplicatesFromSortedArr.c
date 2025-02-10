#include <stdio.h>
#include <stdbool.h>

int arrayRemoveDuplicates(int arr[], int n)
{

    int j = 0;
    for (int i = j+1; i < n; i++)
    {
       if (arr[j] != arr[i]) {
            arr[j+1] = arr[i];
            j++;
       }
    }
    
    return (j+1);

}

void sortInsertion(int arr[], int n)
{

    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j-1] > arr[j])
        {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}

int main(void)
{
    printf("\n");

    int n = 0;
    printf("\nInput the size of the Array: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid array size. The array must contain at least one element.\n");
        return 1;
    }

    int arr[n];

    printf("\nInput the elements into the Array");
    for (int i = 0; i < n; i++)
    {
        printf("\nElement at index arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    sortInsertion(arr, n);

    printf("%d", arrayRemoveDuplicates(arr, n));

    printf("\n");
    return 0;
}
