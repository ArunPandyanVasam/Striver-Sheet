
#include <stdio.h>

void bubble_sort(int arr[], int n)
{
    for (int i = n-1; i >= 1; i--)
    {
        int swapped = 0;
        for (int j = 0; j < i ; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }

    }
}

int main()
{
    puts("\n");

    int n;
    printf("Input the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("value at arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    bubble_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    puts("\n");
    return 0;
}