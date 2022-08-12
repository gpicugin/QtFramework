#include <../Matrix/matrix.h>
#include <QtTest>
#include <QCoreApplication>

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
    void rotate90DegreesTest();
    void rotate90DegreesTest_data();
    void rotate90DegreesExceptionTest();
    void rotate90DegreesExceptionTest_data();
private:
    Matrix matrix;
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


void TMatrix::rotate90DegreesTest()
{
    QFETCH( Matrix, matrix ); // объявление перменной в тестировании
    QFETCH( Matrix, result ); // объявление перменной в тестировании

    QCOMPARE( rotate90Degrees( matrix ), result ); // сравнение двух объектов
}

void TMatrix::rotate90DegreesTest_data()
{
    QTest::addColumn< Matrix >( "matrix" );
    QTest::addColumn< Matrix >( "result" );

    QTest::newRow( "Empty matrix" ) << Matrix { { } } << Matrix { { } };

    QTest::newRow( "2x1 single value matrix" ) <<
                                     Matrix { { 0, 0 } } <<
                                     Matrix { { 0 },
                                              { 0 } };

    QTest::newRow( "2x1 different values matrix" ) <<
                                         Matrix { { 1, 2 } } <<
                                         Matrix { { 1 },
                                                  { 2 } };

    QTest::newRow( "1x2 different values matrix" ) <<
                                     Matrix { { 1 },
                                              { 2 } } <<
                                     Matrix { { 2, 1 } };

    QTest::newRow( "2x2 different values matrix" ) <<
                                         Matrix { { 1, 2 },
                                                  { 3, 4 } } <<
                                         Matrix { { 3, 1 },
                                                  { 4, 2 } };

    QTest::newRow( "3x1 different values matrix" ) <<
                                     Matrix { { 1, 2, 3 } } <<
                                     Matrix { { 1 },
                                              { 2 },
                                              { 3 } };

    QTest::newRow( "3x2 different values matrix" ) <<
                                     Matrix { { 1, 2, 3 },
                                              { 4, 5, 6 } } <<
                                     Matrix { { 4, 1 },
                                              { 5, 2 },
                                              { 6, 3 } };
}

void TMatrix::rotate90DegreesExceptionTest()
{
    QFETCH( Matrix, matrix );
    QFETCH( QString, errorMsg );

    try
    {
        rotate90Degrees( matrix );
        QFAIL( "Must not reach this place" );
    } catch( const std::invalid_argument& e )
    {
        QCOMPARE( QString::fromStdString( e.what() ), errorMsg );
    }
}

void TMatrix::rotate90DegreesExceptionTest_data()
{
    QTest::addColumn< Matrix >( "matrix" );
    QTest::addColumn< QString >( "errorMsg" );

    QTest::newRow( "Matrix with no columns" ) << Matrix { } << "Matrix must have at least one column";

    QTest::newRow( "Matrix with rows of different sizes" ) << Matrix { { 1 },
                                                                          { 2, 3 } } <<
                                                                 "Matrix must have the rows of the same size";
}

QTEST_MAIN(TMatrix)

#include "tst_tmatrix.moc"
