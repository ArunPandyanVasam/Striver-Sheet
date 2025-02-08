
#include <stdio.h>

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {

            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
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

    insertion_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    puts("\n");
    return 0;
}