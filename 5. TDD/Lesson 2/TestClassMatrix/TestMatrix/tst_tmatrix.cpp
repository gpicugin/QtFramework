#include <QtTest>
#include <QCoreApplication>
#include "../Matrix/matrix.h"
#include <QtAlgorithms>
#include <algorithm>
// add necessary includes here

class TMatrix : public QObject
{
    Q_OBJECT

public:
    TMatrix();
    ~TMatrix();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testMatrixConstructor();
    void testMatrixConstructor_data();
    void testMatrixSetStore();
    void testMatrixSetStore_data();
    void testMatrixSum();
    void testMatrixSum_data();
};

TMatrix::TMatrix()
{

}

TMatrix::~TMatrix()
{

}

void TMatrix::initTestCase()
{

}

void TMatrix::cleanupTestCase()
{

}

void TMatrix::testMatrixConstructor()
{
    QFETCH(Matrix, matrix);
    QFETCH(Matrix, result);

    QCOMPARE(matrix, result);
}

void TMatrix::testMatrixConstructor_data()
{
    QTest::addColumn<Matrix>("matrix");
    QTest::addColumn<Matrix>("result");

    QTest::newRow("default constructor") << Smart_Matrix().getStore() << Matrix{{}};
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            QString numbers = "parametr constructor [" + QString::number(i) + "," + QString::number(j) + "]";
            QTest::newRow(numbers.toStdString().c_str()) << Smart_Matrix(i, j).getStore() << Matrix(i, QVector<int>(j,0));
        }
    }

}

void TMatrix::testMatrixSetStore()
{
    QFETCH(Smart_Matrix, matrix);
    QFETCH(Matrix, result);

    QCOMPARE(matrix.getStore(), result);


}

void TMatrix::testMatrixSetStore_data()
{
    QTest::addColumn<Smart_Matrix>("matrix");
    QTest::addColumn<Matrix>("result");


    for(int i = 0 ; i < 10; i++)
        for(int j = 0; j < 10; j++)
        {
            Smart_Matrix matrix(i,j);
            Matrix tmp(i, QVector<int>(j,0));
            for(int n = 0; n < i; n++)
                for(int m = 0; m < j; m++)
                     tmp[n][m] = QRandomGenerator::global()->generate();
            matrix.setStore(tmp);
            QString numbers = "set store [" + QString::number(i) + "," + QString::number(j) + "]";
            QTest::newRow(numbers.toStdString().c_str()) << matrix << tmp;
        }
}

void TMatrix::testMatrixSum()
{
    QFETCH(Smart_Matrix, matrix_1);
    QFETCH(Smart_Matrix, matrix_2);
    QFETCH(Matrix, result);
    QVERIFY(matrix_1.getRows() == matrix_2.getRows());
    for(int i = 0; i < matrix_1.getRows(); i++)
        QVERIFY(matrix_1.getColumns() == matrix_2.getColumns());
    QCOMPARE((matrix_1 + matrix_2).getStore(), result);
//    Smart_Matrix matrix = matrix_1 + matrix_2;
//    QVERIFY(std::equal(result.begin(), result.end(), matrix.getStore().begin()));
}

void TMatrix::testMatrixSum_data()
{
    QTest::addColumn<Smart_Matrix>("matrix_1");
    QTest::addColumn<Smart_Matrix>("matrix_2");
    QTest::addColumn<Matrix>("result");

    for(int i = 1; i < 10; i++)
    {
        for(int j = 1; j < 10; j++)
        {
            Smart_Matrix matrix(i,j);
            Smart_Matrix tmp(i,j);
            Matrix result(i, QVector<int>(j,0));
            for(int n = 0; n < i; n++)
                for(int m = 0; m < j; m++)
                {
                    matrix(n,m) = QRandomGenerator::global()->bounded(-10, 10);
                    tmp(n,m) = QRandomGenerator::global()->bounded(-10, 10);
                    result[n][m] = matrix(n,m) + tmp(n,m);
                }
            QString numbers = "test sum [" + QString::number(i) + "," + QString::number(j) + "]";
            QTest::newRow(numbers.toStdString().c_str()) << matrix << tmp << result;
        }
    }
}

QTEST_MAIN(TMatrix)

#include "tst_tmatrix.moc"
