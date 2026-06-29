#include <stdio.h>
#include <stdlib.h>

// Function declarations
int findAboveCount(int num, int arr[], int size);
int findKth(int arr[], int size, int k);

int main()
{
    int k = 3, arr[] = {11, 22, 33, 55, 44, 100}, size = sizeof(arr) / sizeof(int);
    
    // Find the k-th largest element
    int kth = findKth(arr, size, k);
    
    // Count how many elements are greater than the k-th largest element and print
    printf("There are %d elements greater than the %d-th largest element.\n", findAboveCount(kth, arr, size), k);
    return 0;
}

// Counts how many elements in the array are greater than 'num'
int findAboveCount(int num, int arr[], int size)
{
    int i, greaterThan = 0;
    for (i = 0; i < size; i++) { 
        if (arr[i] > num) 
            greaterThan++; 
    }
    return greaterThan;
}

// Finds the k-th largest element in the array
int findKth(int arr[], int size, int k)
{
    for (int i = 0; i < size; i++)
        if (k == findAboveCount(arr[i], arr, size) + 1) 
            return arr[i];
    
    // Return -1 if the k-th largest element does not exist
    return -1;
}


