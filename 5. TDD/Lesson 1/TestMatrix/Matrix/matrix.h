#ifndef MATRIX_H
#define MATRIX_H
#include <QVector>
#include "Matrix_global.h"

typedef  QVector<QVector<int>> Matrix;

MATRIX_EXPORT Matrix rotate90Degrees( const Matrix& matrix );

#endif // MATRIX_H
