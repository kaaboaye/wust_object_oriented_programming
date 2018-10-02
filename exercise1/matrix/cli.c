#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "matrix.h"

void error(const char *message)
{
  fprintf(stderr, "%s\n", message);
  exit(1);
}

Matrix *read_matrix()
{
  int64_t columns, rows;

  printf("Matrix columns: ");
  if (scanf("%llu", &columns) == EOF)
  {
    error("Field to read Matrix columns");
  }

  printf("Matrix rows: ");
  if (scanf("%llu", &rows) == EOF)
  {
    error("Field to read Matrix rows");
  }

  Matrix *matrix = matrix_new(columns, rows);

  for (int64_t *cell = matrix->cells; cell < matrix->cells_end; ++cell)
  {
    printf("Matrix cell: ");
    if (scanf("%lld", cell) == EOF)
    {
      error("Field to read cell");
    }
  }

  return matrix;
}

void print_matrix(const Matrix *matrix)
{
  printf("Matrix rows: %llu, columns: %llu\n", matrix->rows, matrix->columns);
  for (int64_t *cell = matrix->cells; cell < matrix->cells_end; ++cell)
  {
    printf("%lld ", *cell);
  }
  printf("\n");
}
