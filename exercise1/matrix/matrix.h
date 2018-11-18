
#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>

typedef struct {
  uint64_t columns;
  uint64_t rows;

  int64_t *cells;
  int64_t *cells_end;
} Matrix;

Matrix *matrix_new(uint64_t columns, uint64_t rows);
Matrix *matrix_mul(const Matrix *matrix1, const Matrix *matrix2);
void matrix_free(Matrix *matrix);

#endif
