#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) 
    {
        for (int j = 0; j < n-i-1; j++) 
        {
            if (arr[j] > arr[j+1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) 
        {
            return mid;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else 
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main() 
{
    int n = 10;
    int arr[n];
    srand(time(0)); 
    printf("Generated random numbers: \n");
    for (int i = 0; i < n; i++) 
    {
        arr[i] = rand() % 100; 
        printf("%d ", arr[i]);
    }
    printf("\n");
    bubbleSort(arr, n);
    printf("\nSorted array: \n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, n, key);
    if (result != -1) 
    {
        printf("Element %d found at index %d.\n", key, result);
    } 
    else 
    {
        printf("Element %d not found.\n", key);
    }
    return 0;
}
