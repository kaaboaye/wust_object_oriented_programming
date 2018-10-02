/*
  Author: Mieszko Wawrzyniak

  Task: Implement in C language an algorithm for matrix multiplication.
*/

#include <stdio.h>

#include "matrix.h"
#include "cli.h"

int main(int argc, char const *argv[])
{
  puts("Reading 1st matrix");
  Matrix *matrix1 = read_matrix();
  print_matrix(matrix1);

  puts("Reading 2nd matrix");
  Matrix *matrix2 = read_matrix();
  print_matrix(matrix2);

  puts("Multiplication…");
  Matrix *result = matrix_mul(matrix1, matrix2);
  print_matrix(result);

  matrix_free(matrix1);
  matrix_free(matrix2);
  matrix_free(result);
  return 0;
}
