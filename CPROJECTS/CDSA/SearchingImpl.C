#include <stdio.h>

static int lstarget = -1;

/**
 * Time Complexity:
 * Best Case: O(1)
 * Avg Case: O(n)
 * Worst Case: O(n)
 *
 * Hence, O(n)
 */
int linearSearchIterative(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int linearSearchResursiveImpl(int arr[], int start, int end)
{
    if (start > end)
        return -1;
    if (arr[start] == lstarget)
        return start;
    else if (arr[end] == lstarget)
        return end;
    else
        return linearSearchResursiveImpl(arr, start + 1, end - 1);
}

int linearSearchResursive(int arr[], int size, int target)
{
    lstarget = target;
    int res = linearSearchResursiveImpl(arr, 0, size - 1);
    lstarget = -1;
    return res;
}


/**
 * Time Complexity:
 * Best Case: O(1)
 * Avg Case: O(n)
 * Worst Case: O(n)
 *
 * Hence, O(n)
 */
int binarySearchIterative(int arr[], int size, int target)
{
    int l = 0;
    int r = size - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            l = mid + 1;
        else if (arr[mid] > target)
            r = mid - 1;
    }
    return -1;
}

int binarySearchResursiveImpl(int arr[], int start, int end)
{
    int mid = (start + end) / 2;
    if (start <= end)
    {
        if (arr[mid] == lstarget)
            return mid;
        if (arr[mid] < lstarget)
            return binarySearchResursiveImpl(arr, mid + 1, end);
        else // if(arr[mid] > lstarget)
            return binarySearchResursiveImpl(arr, start, mid - 1);
    } else
        return -1;
}

int binarySearchResursive(int arr[], int size, int target)
{
    lstarget = target;
    int res = binarySearchResursiveImpl(arr, 0, size - 1);
    lstarget = -1;
    return res;
}
