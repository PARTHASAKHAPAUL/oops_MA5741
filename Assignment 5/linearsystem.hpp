#ifndef LINEARSYSTEMHEADERDEF
#define LINEARSYSTEMHEADERDEF

#include "Matrix.hpp"
#include "Vector.hpp"

class LinearSystem
{
private:
    Matrix* mpA; // coefficient matrix A
    Vector* mpb; // right-hand side vector b
    int mSize;   // size of the system

public:
    LinearSystem(Matrix& A, Vector& b); // constructor
    ~LinearSystem();                     // destructor

    Vector Solve(); // solve the linear system
};

#endif
