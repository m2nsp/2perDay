#include <stdio.h>

void Decrease_key_min_heap(int A[], int i, int key) {
    if (key >= A[i]) {
        fprintf(stderr, "Error: New key is not smaller than the current key\n");
        return;
    }

    A[i] = key;
    while (i > 0 && A[i] < A[(i - 1) / 2]) {
        int temp = A[i];
        A[i] = A[(i - 1) / 2];
        A[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void Increase_key_min_heap(int A[], int i, int key) {
    if (key <= A[i]) {
        fprintf(stderr, "Error: New key is not larger than the current key\n");
        return;
    }

    A[i] = key;
    int heap_size = sizeof(A) / sizeof(A[0]);
    int parent, temp;

    while (i > 0) {
        parent = (i - 1) / 2;

        if (A[i] < A[parent]) {
            // Swap the current element with its parent
            temp = A[i];
            A[i] = A[parent];
            A[parent] = temp;

            i = parent;
        }
        else {
            break;
        }
    }
}

int main() {
    int min_heap[] = { 1, 4, 2, 7, 5, 3, 3, 7, 8, 9 };
    int heap_size = sizeof(min_heap) / sizeof(min_heap[0]);

    printf("Initial heap: ");
    for (int i = 0; i < heap_size; i++) {
        printf("%d ", min_heap[i]);
    }
    printf("\n");

    // Increase the key at index 2 (value 2) to 10
    Increase_key_min_heap(min_heap, 2, 10);
    printf("Increased key: ");
    for (int i = 0; i < heap_size; i++) {
        printf("%d ", min_heap[i]);
    }
    printf("\n");

    // Decrease the key at index 3 to 3
    Decrease_key_min_heap(min_heap, 3, 3);
    printf("Decreased key: ");
    for (int i = 0; i < heap_size; i++) {
        printf("%d ", min_heap[i]);
    }
    printf("\n");

    return 0;
}