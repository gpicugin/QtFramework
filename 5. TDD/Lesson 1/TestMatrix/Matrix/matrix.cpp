#include "matrix.h"

//Matrix::Matrix()
//{
//}


Matrix rotate90Degrees( const Matrix& matrix )
{
    const int columnCount = matrix.size();
    if( columnCount == 0 )
    {
        throw std::invalid_argument( "Matrix must have at least one column" );
    }

    const int rowCount = matrix[ 0 ].size();

    if( rowCount == 0 )
    {
        return matrix;
    }

    Matrix rotatedMatrix( rowCount );
    for( int i = 0; i < rowCount; ++i )
    {
        rotatedMatrix[ i ].resize( columnCount );
        for( int j = 0; j < columnCount; ++j )
        {
            if( matrix[ columnCount - 1 - j ].size() != rowCount )
            {
                throw std::invalid_argument( "Matrix must have the rows of the same size" );
            }
            rotatedMatrix[ i ][ j ] = matrix[ columnCount - 1 - j ][ i ];
        }
    }
    return rotatedMatrix;
}
