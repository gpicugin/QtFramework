#ifndef MATRIX_H
#define MATRIX_H
#include <QVector>
#include "Matrix_global.h"

typedef QVector<QVector<int>> Matrix;

class MATRIX_EXPORT Smart_Matrix
{
public:
    Smart_Matrix();
    Smart_Matrix(int n, int m);
    ~Smart_Matrix();

    const Matrix& getStore();
    void setStore(const Matrix& tmp);
    Smart_Matrix operator+(Smart_Matrix& matrix_2);

    QVector<int>& operator ()(int index);
    const QVector<int>& operator ()(int index) const;
    int& operator() (int index1, int index2);
    const int& operator() (int index1, int index2) const;
    bool operator== (const Smart_Matrix& matrix2) const;
    int getRows() const;
    int getColumns() const;
private:
    Matrix m_store;
};

#endif // MATRIX_H
