#include <stdio.h>
#include <stdlib.h>

int heap[100000], sz = 0;

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void heapify_up(int i) {
    while (i > 0 && heap[(i-1)/2] > heap[i]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void heapify_down(int i) {
    int l = 2*i+1, r = 2*i+2, smallest = i;
    if (l < sz && heap[l] < heap[smallest]) smallest = l;
    if (r < sz && heap[r] < heap[smallest]) smallest = r;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify_down(smallest);
    }
}

void insert(int x) {
    heap[sz] = x;
    heapify_up(sz);
    sz++;
}

void delete_val(int x) {
    int idx = -1;
    for (int i = 0; i < sz; i++) if (heap[i] == x) { idx = i; break; }
    if (idx == -1) return;
    heap[idx] = heap[--sz];
    heapify_down(idx);
    heapify_up(idx);
}

int main() {
    int Q; scanf("%d", &Q);
    while (Q--) {
        int t, x; scanf("%d", &t);
        if (t == 1) { scanf("%d", &x); insert(x); }
        else if (t == 2) { scanf("%d", &x); delete_val(x); }
        else printf("%d\n", heap[0]);
    }
    return 0;
}
