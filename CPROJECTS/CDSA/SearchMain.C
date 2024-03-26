#include<stdio.h>
#include "SearchingAlgo.H"

int main() {
    int arr1[] = {45, 63, 84, 78, 92, 121, 34, 80};
    int arr2[10] = {45, 63, 84, 78, 92, 3};

    printf("121 in arr1? - index %d\n", linearSearchIterative(arr1, 8, 121));
    printf("63 in arr2? - index %d\n", linearSearchIterative(arr2, 10, 63));
    printf("1000 in arr1? - index %d\n", linearSearchIterative(arr1, 8, 1000));
    printf("163 in arr2? - index %d\n", linearSearchIterative(arr2, 10, 163));
    printf("121 in arr1? - index %d\n", linearSearchResursive(arr1, 8, 121));
    printf("63 in arr2? - index %d\n", linearSearchResursive(arr2, 10, 63));
    printf("1000 in arr1? - index %d\n", linearSearchResursive(arr1, 8, 1000));
    printf("163 in arr2? - index %d\n", linearSearchResursive(arr2, 10, 163));
    // Special Case
    printf("0 in arr2? - index %d\n", linearSearchResursive(arr2, 10, 0));

    int arr3[] = {1, 2, 55, 78, 94, 136, 139, 151, 157, 161, 163, 173, 179, 189, 191, 193};

    int arr3size = (int) sizeof(arr3) / sizeof(arr3[0]);
    printf("55 in arr3? - index %d\n", binarySearchIterative(arr3, arr3size, 55));
    printf("59 in arr3? - index %d\n", binarySearchIterative(arr3, arr3size, 59));
    printf("173 in arr3? - index %d\n", binarySearchResursive(arr3, arr3size, 173));
    printf("172 in arr3? - index %d\n", binarySearchResursive(arr3, arr3size, 172));

    return 0;
}