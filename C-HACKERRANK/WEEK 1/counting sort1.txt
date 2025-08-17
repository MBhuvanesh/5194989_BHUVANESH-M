#include <stdio.h>
#include <stdlib.h>

int* countingSort(int arr_count, int* arr, int* result_count) {
    *result_count = 100; 
    int *frequency = (int*)calloc(100, sizeof(int));

    for (int i = 0; i < arr_count; i++) {
        frequency[arr[i]]++;
    }

    return frequency;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result_count;
    int *result = countingSort(n, arr, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}