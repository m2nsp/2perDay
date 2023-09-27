#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

typedef struct{
    int row;
    int col;
    int value;
}element;

typedef struct SparseMatrix{
  element data[MAX_TERMS];
  int rows;
  int cols;
  int terms;
}SparseMatrix;


int main(void){

  //Add B as an input
  SparseMatrix B = {
    {{0,3,7}, {1,0,9}, {1,5,8},{3,0,6},{3,1,5},{4,5,1},{5,2,2}},
    6,
    6,
    7
  };

  //Perform the transpose operation
    SparseMatrix tran_B;

    int tran_B_index;
    tran_B.rows = B.cols;
    tran_B.cols = B.rows;
    tran_B.terms = B.terms;
    
    if(B.terms > 0){
      tran_B_index = 0;
      for(int c = 0; c < B.cols; c++){
        for(int i = 0; i < B.terms; i++){
          if(B.data[i].col == c){
            tran_B.data[tran_B_index].row = B.data[i].col;
            tran_B.data[tran_B_index].col = B.data[i].row;
            tran_B.data[tran_B_index].value = B.data[i].value;
            tran_B_index++;
          }
        }
      }
    }

  //Print out B and B^T in a dense matrix form to check

  //B
  int dense[B.rows][B.cols];

  // Initialize the dense matrix with zeros
  for (int i = 0; i < B.rows; i++) {
      for (int j = 0; j < B.cols; j++) {
          dense[i][j] = 0;
      }
  }

  // Fill in the non-zero values from the sparse matrix
  for (int i = 0; i < B.terms; i++) {
      dense[B.data[i].row][B.data[i].col] = B.data[i].value;
  }


  // Print the dense matrix
  printf("B:\n");
  for (int i = 0; i < B.rows; i++) {
      for (int j = 0; j < B.cols; j++) {
          printf("%d ", dense[i][j]);
      }
      printf("\n");
  }


  //B^T
  int dense_T[tran_B.rows][tran_B.cols];
  
  printf("B^T:\n");

  for (int i = 0; i < tran_B.rows; i++) {
      for (int j = 0; j < tran_B.cols; j++) {
          dense_T[i][j] = 0;
      }
  }

  for (int i = 0; i < tran_B.terms; i++) {
      dense_T[tran_B.data[i].row][tran_B.data[i].col] = tran_B.data[i].value;
  }

  for (int i = 0; i < tran_B.rows; i++) {
      for (int j = 0; j < tran_B.cols; j++) {
          printf("%d ", dense_T[i][j]);
      }
      printf("\n");
  }

  return 0;
}