
#include <stdio.h>

void merge(int arr[], int low, int mid, int high)
{

    // I need a temporary array to store sorted values
    int temp[high - low + 1];
    int left = low;
    int right = mid + 1;
    int k = 0;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp[k] = arr[left];
            k++;
            left++;
        }
        else
        {
            temp[k] = arr[right];
            k++;
            right++;
        }
    }

    while (left <= mid)
    {
        temp[k] = arr[left];
        k++;
        left++;
    }

    while (right <= high)
    {
        temp[k] = arr[right];
        k++;
        right++;
    }

    for (int i = low; i <= high; i++)    
    {
        arr[i] = temp[i-low];
    }
    
}

void merge_sort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
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

    merge_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    puts("\n");
    return 0;
}