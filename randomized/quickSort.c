#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;
    while (1)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
        {
            return j;
        }
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int r_partition(int *arr, int low, int high)
{
    srand(time(0));
    int random = low + rand() % (high - low);
    int temp = arr[random];
    arr[random] = arr[low];
    arr[low] = temp;
    return partition(arr, low, high);
}

void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pi = r_partition(arr, low, high);
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[] = {2, 4, 1, 3, 5};
    quickSort(arr, 0, (sizeof(arr) / sizeof(arr[0])) - 1);
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        printf("%d ", arr[i]);
    }
}