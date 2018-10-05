#include <stdlib.h>
#include <stdint.h>

#include "cli.h"
#include "matrix.h"

static int64_t *matrix_cell_pointer(const Matrix *matrix, uint64_t row, uint64_t column)
{
  return matrix->cells + (row * matrix->columns + column);
}

static int64_t matrix_cell(const Matrix *matrix, uint64_t row, uint64_t column)
{
  return matrix->cells[row * matrix->columns + column];
}

Matrix *matrix_new(uint64_t columns, uint64_t rows)
{
  Matrix *matrix = malloc(sizeof(Matrix));
  if (matrix == 0)
  {
    error("Field to allocate matrix");
  }

  matrix->columns = columns;
  matrix->rows = rows;

  matrix->cells = malloc(columns * rows * sizeof(int64_t));
  if (matrix->cells == 0)
  {
    error("Field to allocate matrix");
  }

  matrix->cells_end = matrix->cells + columns * rows;
  return matrix;
}

Matrix *matrix_mul(const Matrix *matrix1, const Matrix *matrix2)
{
  if (matrix1->columns != matrix2->rows)
  {
    error("Columns of 1st matrix are not equal rows of 2nd matrix");
  }

  Matrix *result = matrix_new(matrix2->columns, matrix1->rows);

  for (uint64_t row1 = 0; row1 < matrix1->rows; ++row1)
  {
    for (uint64_t col2 = 0; col2 < matrix2->columns; ++col2)
    {
      int64_t sum = 0;
      for (uint64_t col1 = 0; col1 < matrix1->columns; ++col1)
      {
        sum +=
            matrix_cell(matrix1, row1, col1) * matrix_cell(matrix2, col1, col2);
      }
      matrix_cell_pointer(result, row1, col2)[0] = sum;
    }
  }

  return result;
}

void matrix_free(Matrix *matrix)
{
  free(matrix->cells);
  free(matrix);
}