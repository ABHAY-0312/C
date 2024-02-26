// PROGRAM OF BINARY SEARCH USING RECURSION

#include <stdio.h>

int binarySearch(int arr[], int low, int high, int element)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == element)
            return mid;
        if (arr[mid] > element)
            return binarySearch(arr, low, mid - 1, element);
        else
            return binarySearch(arr, mid + 1, high, element);
    }

    return -1; // Element not found
}

int main()
{
    int n, element, result;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements in sorted order:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &element);

    result = binarySearch(arr, 0, n - 1, element);

    if (result == -1)
        printf("Element not found\n");
    else
        printf("Element found at index %d\n", result);

    return 0;
}
