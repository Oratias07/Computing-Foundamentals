#include <stdio.h>

// Function to sum only the even elements of an array
int sumArr(int arr[], int size)
{
    int sum = 0, i;

    // Loop through each element of the array
    for (i = 0; i < size; i++)
        // Check if the element is even
        if ((arr[i] & 1) == 0)
            sum += arr[i]; // Add even element to sum

    return sum; // Return the total sum of even elements
}

int main()
{
    int arr[] = {100, 200, 21, -5};

    // Call sumArr to get sum of even elements and print the result
    printf("The sum of even members is: %d\n", sumArr(arr, sizeof(arr) / sizeof(arr[0])));

    return 0;
}
