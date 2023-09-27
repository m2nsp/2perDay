#include <stdio.h>
#include <stdlib.h>

// Function to allocate a 3D double array
double ***mem_alloc_3D_double(int dim1, int dim2, int dim3) {
    double ***array;
    int i, j;

    array = (double ***)malloc(dim1 * sizeof(double **));

    for (i = 0; i < dim1; i++) {
        array[i] = (double **)malloc(dim2 * sizeof(double *));
        for (j = 0; j < dim2; j++) {
            array[i][j] = (double *)malloc(dim3 * sizeof(double));
        }
    }

    return array;
}

void mem_free_3D_double(double ***array, int dim1, int dim2) {
    int i, j;

    for (i = 0; i < dim1; i++) {
        for (j = 0; j < dim2; j++) {
            free(array[i][j]);
        }
        free(array[i]); 
    }

    free(array); 
}


void addition_3D(double ***A, double ***B, double ***result, int dim1, int dim2, int dim3) {
    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim2; j++) {
            for (int k = 0; k < dim3; k++) {
                result[i][j][k] = A[i][j][k] + B[i][j][k];
            }
        }
    }
}

int main(void) {
    int dim1 = 2; 
    int dim2 = 3;
    int dim3 = 4; 

   
    double ***A = mem_alloc_3D_double(dim1, dim2, dim3);
    double ***B = mem_alloc_3D_double(dim1, dim2, dim3);

   
    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim2; j++) {
            for (int k = 0; k < dim3; k++) {
                A[i][j][k] = 1.0; 
                B[i][j][k] = 2.0; 
            }
        }
    }


    double ***result = mem_alloc_3D_double(dim1, dim2, dim3);


    addition_3D(A, B, result, dim1, dim2, dim3);


    mem_free_3D_double(A, dim1, dim2);
    mem_free_3D_double(B, dim1, dim2);
    mem_free_3D_double(result, dim1, dim2);

    return 0;
}