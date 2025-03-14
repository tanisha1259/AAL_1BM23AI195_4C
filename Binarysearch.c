#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
int main() {
    int n = 20, arr[20], key, i;
    srand(time(0));

    for (i = 0; i < n; i++) arr[i] = rand() % 100 + 1;

    printf("Generated random numbers: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    bubbleSort(arr, n);
    printf("Sorted array: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    printf("Enter the key to be searched: ");
    scanf("%d", &key);
    int index = binarySearch(arr, n, key);
    if (index != -1)
        printf("Key %d found at index %d\n", key, index);
    else
        printf("Key %d not found\n", key);
    return 0;
}
