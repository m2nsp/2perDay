#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void generate_input_data(int A[], int n, int b) {
    for (int i = 0; i < n; i++) {
        A[i] = rand() % (1 << b); // 0에서 (1 << b) - 1 사이의 값으로 조정
    }
}

void counting_sort(int A[], int B[], int n, int k, int shift) {
    int* C = (int*)malloc(k * sizeof(int));

    for (int i = 0; i < k; i++) {
        C[i] = 0;
    }

    for (int j = 0; j < n; j++) {
        C[(A[j] >> shift) & (k - 1)] += 1;
    }

    for (int i = 1; i < k; i++) {
        C[i] = C[i] + C[i - 1];
    }

    for (int j = n - 1; j >= 0; j--) {
        B[--C[(A[j] >> shift) & (k - 1)]] = A[j];
    }

    free(C);
}


void radix_sort(int A[], int n, int b, int r) {
    int d = b / r;
    int* B = (int*)malloc(n * sizeof(int));

    for (int i = 1; i <= d; i++) {
        counting_sort(A, B, n, 1 << r, (i - 1) * r);

        for (int j = 0; j < n; j++) {
            A[j] = B[j];
        }
    }

    free(B);
}


int main() {
    int n = 1000;
    int b = 24;
    int r = 6;
    int* A = (int*)malloc(n * sizeof(int));

    if (A == NULL) {
        fprintf(stderr, "메모리 할당 실패\n");
        return 1;
    }

    srand((unsigned int)time(NULL));

    generate_input_data(A, n, b);

    printf("Original Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    radix_sort(A, n, b, r);

    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    free(A);

    return 0;
}

