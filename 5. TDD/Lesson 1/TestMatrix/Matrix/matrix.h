#ifndef MATRIX_H
#define MATRIX_H
#include <QVector>
#include "Matrix_global.h"

typedef  QVector<QVector<int>> Matrix;

MATRIX_EXPORT Matrix rotate90Degrees( const Matrix& matrix );

//class MATRIX_EXPORT Matrix
//{
//public:
//    Matrix();
//private:
//    QVector<QVector<int>> m_store;
//};

#endif // MATRIX_H
