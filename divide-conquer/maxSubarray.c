#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int *maxCrossSubarray(int arr[], int low, int mid, int high)
{
    int *result = malloc(3 * 4);
    int left_sum = INT_MIN;
    int sum = 0;
    int max_left, max_right;
    for (int i = mid; i >= 0; i--)
    {
        sum += arr[i];
        if (left_sum < sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }
    int right_sum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; i++)
    {
        sum += arr[i];
        if (right_sum < sum)
        {
            right_sum = sum;
            max_right = i;
        }
    }
    result[0] = max_left;
    result[1] = max_right;
    result[2] = left_sum + right_sum;
    return result;
}

int *maxSubarray(int arr[], int low, int high)
{
    int *result = malloc(12);
    if (low == high)
    {
        result[0] = low;
        result[1] = high;
        result[2] = arr[low];
        return result;
    }
    else
    {
        int mid = floor((low + high) / 2);
        int left_low, left_high, left_sum, right_low, right_high, right_sum, cross_low, cross_high, cross_sum;
        int *temp = maxSubarray(arr, low, mid);
        left_low = temp[0];
        left_high = temp[1];
        left_sum = temp[2];
        temp = maxSubarray(arr, mid + 1, high);
        right_low = temp[0];
        right_high = temp[1];
        right_sum = temp[2];
        temp = maxCrossSubarray(arr, low, mid, high);
        cross_low = temp[0];
        cross_high = temp[1];
        cross_sum = temp[2];
        if (left_sum >= right_sum && left_sum >= cross_sum)
        {
            result[0] = left_low;
            result[1] = left_high;
            result[2] = left_sum;
            return result;
        }
        else if (right_sum >= left_sum && right_sum >= cross_sum)
        {
            result[0] = right_low;
            result[1] = right_high;
            result[2] = right_sum;
            return result;
        }
        else
        {
            result[0] = cross_low;
            result[1] = cross_high;
            result[2] = cross_sum;
            return result;
        }
    }
}

int main()
{
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    printf("%d ", sizeof(arr) / sizeof(arr[0]));
    int *result = maxSubarray(arr, 0, (sizeof(arr) / sizeof(arr[0])) - 1);
    printf("%d", result[2]);
}