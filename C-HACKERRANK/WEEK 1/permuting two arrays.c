#include <stdio.h>
#include <stdlib.h>


int cmpAsc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int cmpDesc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

char* twoArrays(int k, int A[], int B[], int n) {
    
    qsort(A, n, sizeof(int), cmpAsc);
    
    qsort(B, n, sizeof(int), cmpDesc);

    for (int i = 0; i < n; i++) {
        if (A[i] + B[i] < k) {
            return "NO";
        }
    }
    return "YES";
}