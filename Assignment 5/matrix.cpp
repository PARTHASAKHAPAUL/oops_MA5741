#include <iostream>
#include <cmath>
#include <cassert>
#include "Matrix.hpp"
using namespace std;

// Constructor for a matrix of a given size
Matrix::Matrix(int rows, int cols)
{
    assert(rows > 0 && cols > 0);
    mRows = rows;
    mCols = cols;
    mData = new double*[mRows];
    for (int i = 0; i < mRows; ++i)
    {
        mData[i] = new double[mCols];
        for (int j = 0; j < mCols; ++j)
        {
            mData[i][j] = 0.0;
        }
    }
}

// copy constructor
Matrix::Matrix(const Matrix& otherMatrix)
{
    mRows = otherMatrix.GetRows();
    mCols = otherMatrix.GetCols();
    mData = new double*[mRows];
    for (int i = 0; i < mRows; ++i)
    {
        mData[i] = new double[mCols];
        for (int j = 0; j < mCols; ++j)
        {
            mData[i][j] = otherMatrix.mData[i][j];
        }
    }
}

//destructor
Matrix::~Matrix()
{
    for (int i = 0; i < mRows; ++i)
    {
        delete[] mData[i];
    }
    delete[] mData;
}

// Method to get the number of rows in a matrix
int Matrix::GetRows() const
{
    return mRows;
}

// Method to get the number of columns in a matrix
int Matrix::GetCols() const
{
    return mCols;
}

//printing matrix
void Matrix::printmat(){
    for(int i=0; i < mRows; i++){
        for(int j=0; j < mCols; j++){
            cout<<mData[i][j]<<"  ";
        }
        cout<<endl;
    }
}

// Overloading round brackets
double& Matrix::operator()(int i, int j)
{

    assert(i > 0 && i <= mRows);
    assert(j > 0 && j <= mCols);
    return mData[i - 1][j - 1];
}


// Overloading the assignment operator
Matrix& Matrix::operator=(const Matrix& otherMatrix)
{
    assert(mRows == otherMatrix.mRows);
    assert(mCols == otherMatrix.mCols);
    for (int i = 0; i < mRows; ++i)
    {
        for (int j = 0; j < mCols; ++j)
        {
            mData[i][j] = otherMatrix.mData[i][j];
        }
    }
    return *this;
}

// Overloading the unary + operator
Matrix Matrix::operator+() const
{
    Matrix mat(mRows, mCols);
    for (int i = 0; i < mRows; ++i)
    {
        for (int j = 0; j < mCols; ++j)
        {
            mat(i + 1, j + 1) = mData[i][j];
        }
    }
    return mat;
}

// Overloading the unary - operator
Matrix Matrix::operator-() const
{
    Matrix mat(mRows, mCols);
    for (int i = 0; i < mRows; ++i)
    {
        for (int j = 0; j < mCols; ++j)
        {
            mat(i + 1, j + 1) = -mData[i][j];
        }
    }
    return mat;
}

// Overloading the binary + operator
Matrix Matrix::operator+(const Matrix& m1) const
{
    assert(mRows == m1.mRows);
    assert(mCols == m1.mCols);
    Matrix mat(mRows, mCols);
    for (int i = 0; i < mRows; ++i)
    {
        for (int j = 0; j < mCols; ++j)
        {
            mat(i + 1, j + 1) = mData[i][j] + m1.mData[i][j];
        }
    }
    return mat;
}

// Overloading the binary - operator
Matrix Matrix::operator-(const Matrix& m1) const
{
    assert(mRows == m1.mRows);
    assert(mCols == m1.mCols);
    Matrix mat(mRows, mCols);
    for (int i = 0; i < mRows; ++i)
    {
        for (int j = 0; j < mCols; ++j)
        {
            mat(i + 1, j + 1) = mData[i][j] - m1.mData[i][j];
        }
    }
    return mat;
}

// Overloading scalar multiplication
Matrix Matrix::operator*(double a) const
{
    Matrix mat(mRows, mCols);
    for (int i = 0; i < mRows; ++i)
    {
        for (int j = 0; j < mCols; ++j)
        {
            mat(i + 1, j + 1) = a * mData[i][j];
        }
    }
    return mat;
}

// Overloading matrix multiplication
Matrix Matrix::operator*(const Matrix& m1) const
{
    assert(mCols == m1.mRows);
    Matrix mat(mRows, m1.mCols);
    for (int i = 0; i < mRows; ++i)
    {
        for (int j = 0; j < m1.mCols; ++j)
        {
            mat(i + 1, j + 1) = 0.0;
            for (int k = 0; k < mCols; ++k)
            {
                mat(i + 1, j + 1) += mData[i][k] * m1.mData[k][j];
            }
        }
    }
    return mat;
}

//member function to calculate the determinant of a square matrix  (doing by recursion method)
double Matrix::determinant() const
{
    assert(mRows == mCols); // checking the matrix is square or not

    if (mRows == 1) {
        return mData[0][0]; // Base case for a 1x1 matrix
    }

    if (mRows == 2) {
        return mData[0][0] * mData[1][1] - mData[0][1] * mData[1][0]; // Base case for a 2x2 matrix
    }

    double det = 0.0;

    for (int j = 0; j < mCols; ++j) {
        Matrix submatrix(mRows - 1, mCols - 1);
        for (int i = 1; i < mRows; ++i) {
            for (int k = 0, l = 0; k < mCols; ++k) {
                if (k == j) {
                    continue; // Skipping the current column
                }
                submatrix(i , l+1) = mData[i][k];
                ++l;
            }
        }
        double sign = (j % 2 == 0) ? 1.0 : -1.0;  //sign detection
        det += sign * mData[0][j] * submatrix.determinant();
    }
    return det;
}

