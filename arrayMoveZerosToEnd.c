#include <stdio.h>

void moveNonZerosToEndBruteForce(int arr[], int n)
{

    int ctr = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            ctr = ctr + 1;
        }
    }

    if (n == ctr)
    {
        for (int i = 0; i < n; i++)
        {
            arr[i] = 0;
        }
        return;
    }

    int temp[n - ctr];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            temp[j] = arr[i];
            j++;
        }
    }

    for (int i = 0; i < n - ctr; i++)
    {
        arr[i] = temp[i];
    }

    for (int i = n - ctr; i < n; i++)
    {
        arr[i] = 0;
    }
}

void moveNonZerosToEndBetter(int arr[], int n)
{

    int j = 0;

    for (int i = 0; i < n; i++)
    {

        if (arr[i] != 0)
        {
            if (i != j)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            j++;
        }
    }
}

void moveNonZerosToEndOptimal(int arr[], int n)
{

    int j = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
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

    int arr[n], originalArray[n];

    printf("\nInput the elements into the Array");
    for (int i = 0; i < n; i++)
    {
        printf("\nElement at index arr[%d]: ", i);
        scanf("%d", &arr[i]);
        originalArray[i] = arr[i];
    }

    moveNonZerosToEndBruteForce(arr, n);
    printf("\nPrint the array moveNonZerosToEndBruteForce: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = originalArray[i];
    }
    moveNonZerosToEndBetter(arr, n);
    printf("\nPrint the array moveNonZerosToEndBetter: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = originalArray[i];
    }
    moveNonZerosToEndOptimal(arr, n);
    printf("\nPrint the array moveNonZerosToEndOptimal: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
