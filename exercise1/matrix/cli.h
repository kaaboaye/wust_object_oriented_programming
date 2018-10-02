#ifndef HELPERS_H
#define HELPERS_H

#include "matrix.h"

void error(const char *message);
Matrix *read_matrix();
void print_matrix(const Matrix *matrix);

#endif