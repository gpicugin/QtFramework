#include "matrix.h"

Smart_Matrix::Smart_Matrix()
{
    m_store = {{}};
}


Smart_Matrix::Smart_Matrix(int n, int m)
{
    m_store.resize(n);
    for(int i = 0; i < n; i++)
        m_store[i].resize(m);
}

Smart_Matrix::~Smart_Matrix()
{
}

const Matrix& Smart_Matrix::getStore()
{
    return m_store;
}

void Smart_Matrix::setStore(const Matrix &tmp)
{
    m_store = tmp;
}

Smart_Matrix Smart_Matrix::operator+(Smart_Matrix& matrix2)
{
    int rows = getRows();
    int columns = getColumns();
    Smart_Matrix tmp(0,0);
    if(rows == matrix2.getRows() && columns == matrix2.getColumns())
    {
        Matrix temp(rows, QVector<int>(columns,0));
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < columns; j++)
                temp[i][j] = (*this)(i,j) + matrix2(i,j);
        tmp.setStore(temp);
    }
    return tmp;
}

QVector<int>& Smart_Matrix::operator()(int index)
{
    return m_store[index];
}

const QVector<int>& Smart_Matrix::operator()(int index) const
{
    return m_store[index];
}

int& Smart_Matrix::operator()(int index1, int index2)
{
    return m_store[index1][index2];
}

const int& Smart_Matrix::operator()(int index1, int index2) const
{
    return m_store[index1][index2];
}

bool Smart_Matrix::operator==(const Smart_Matrix& matrix2) const
{
    if(getRows() != matrix2.getRows())
        return false;
    for(int i = 0; i < getRows(); i++)
    {
        if((*this)(i).size() != matrix2(i).size())
            return false;
        for(int j = 0; j < this->getColumns(); j++)
        {
            if((*this)(i,j) != matrix2(i,j))
                return false;
        }
    }
    return true;
}

int Smart_Matrix::getRows() const
{
    return m_store.size();
}

int Smart_Matrix::getColumns() const
{
    return m_store[0].size();
}
