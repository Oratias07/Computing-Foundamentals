# include <stdio.h>

int sumArr(int arr[], int size)
{
    int sum = 0, i;
    for (i = 0; i < size; i++)
        if ((arr[i] & 1) == 0)
            sum += arr[i];
    return sum;
}

int main()
{
    int arr[] = {100, 200, -5, 21};
    printf("The sum of even members is: %d\n", sumArr(arr, sizeof(arr) / sizeof(arr[0])));
    return 0;
}