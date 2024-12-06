//THIS WHOLE FILE IS NEW
#pragma once
#pragma once

#include "Particle-2.h"
#include "Matrices-5.h"


///Construct a matrix of the specified size.
///Initialize each element to 0.
Matrix::Matrix(int _rows, int _cols)
{
    rows = _rows;
    cols = _cols;
}

///Add each corresponding element.
///usage:  c = a + b;
Matrix operator+(const Matrix& a, const Matrix& b)
{
    //DO ME 
}

///Matrix multiply.  See description.
///usage:  c = a * b;
Matrix operator*(const Matrix& a, const Matrix& b)
{
    //DO ME
}

///Matrix comparison.  See description.
///usage:  a == b
bool operator==(const Matrix& a, const Matrix& b)
{
   //DO ME
}

///Matrix comparison.  See description.
///usage:  a != b
bool operator!=(const Matrix& a, const Matrix& b)
{
    //DO ME
}

///Output matrix.
///Separate columns by ' ' and rows by '\n'
ostream& operator<<(ostream& os, const Matrix& a)
{
    //DO ME
}

/*******************************************************************************/

    ///2D rotation matrix
    ///usage:  A = R * A rotates A theta radians counter-clockwise
    //CLASS NAME::RotationMatrix : publix Matrix

///Call the parent constructor to create a 2x2 matrix
    ///Then assign each element as follows:
    /*
    cos(theta)  -sin(theta)
    sin(theta)   cos(theta)
    */
    ///theta represents the angle of rotation in radians, counter-clockwise
RotationMatrix::RotationMatrix(double theta)
{
    //DO ME
}



