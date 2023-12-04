#ifndef MATRIXHEADERDEF
#define MATRIXHEADERDEF

#include "Vector.hpp"

class Matrix
{
private:
    double** mData; // 2D array to store matrix data
    int mRows;      // number of rows
    int mCols;      // number of columns

public:
    Matrix(int rows, int cols); // constructor
    Matrix(const Matrix& otherMatrix); // copy constructor
    ~Matrix(); // destructor

    int GetRows() const;
    int GetCols() const;
    void printmat();

    double& operator()(int i, int j); // one-based indexing

    Matrix& operator=(const Matrix& otherMatrix);
    Matrix operator+() const; // unary +
    Matrix operator-() const; // unary -
    Matrix operator+(const Matrix& m1) const; // binary +
    Matrix operator-(const Matrix& m1) const; // binary -
    Matrix operator*(double a) const; // scalar multiplication
    Matrix operator*(const Matrix& m1) const; // matrix multiplication

    double determinant() const; //for calculating determinant
};

#endif
