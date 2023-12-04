#include <iostream>
#include "Vector.hpp"
#include "Matrix.hpp"
#include "LinearSystem.hpp"
using namespace std;

int main()
{
    //example with Vector class
    Vector v1(3); //creating a vector of size 3
    v1[0] = 1.0;
    v1[1] = 2.0;
    v1[2] = 3.0;

    Vector v2 = -v1; //unary - operator
    Vector v3 = v1 + v2; //binary + operator

    cout << "Vector v1 is: \n";
    v1.print();
    cout << "Vector v2(using Unary - operator to v1) is: \n";
    v2.print();
    cout << "Vector v3(using Binary + operator to v1 and v2) is: \n";
    v3.print();

    //example with Matrix class
    Matrix m1(2, 2); //creating a 2x2 matrix
    m1(1, 1) = 1.0;
    m1(1, 2) = 2.0;
    m1(2, 1) = 3.0;
    m1(2, 2) = 4.0;

    Matrix m2 = -m1; //unary - operator
    Matrix m3 = m1 + m2; //binary + operator
    Matrix m4 = m1 * 2.0; //scalar multiplication
    Matrix m5 = m1 * m4; //matrix multiplication

    cout << "Matrix m1 is: \n";
    m1.printmat();
    cout << "Matrix m2(using Unary - operator to m1) is: \n";
    m2.printmat();
    cout << "Matrix m3(using Binary + operator to m1 and m2) is: \n";
    m3.printmat();
    cout << "Matrix m4(using scalar multiplication to m1 and 2) is: \n";
    m4.printmat();
    cout << "Matrix m5(using Binary * operator to m1 and m4) is: \n";
    m5.printmat();

    //the LinearSystem class
    Matrix A(4, 4);
    Vector b(4);

    A(1, 1) = 1.0;
    A(1, 2) = 8.0;
    A(1, 3) = 3.0;
    A(1, 4) = 9.0;
    A(2, 1) = 5.0;
    A(2, 2) = 14.0;
    A(2, 3) = 7.0;
    A(2, 4) = 8.0;
    A(3, 1) = 9.0;
    A(3, 2) = 6.0;
    A(3, 3) = 15.0;
    A(3, 4) = 12.0;
    A(4, 1) = 19.0;
    A(4, 2) = 13.0;
    A(4, 3) = 12.0;
    A(4, 4) = 12.0;

    b(1) = 8.0;
    b(2) = 20.0;
    b(3) = 13.0;
    b(4) = 17.0;
    cout<<"The matrix and the vector A and b of the given linear system is:: "<<endl;
    cout<<"A is::"<<endl;
    A.printmat();
    cout<<"b is::"<<endl;
    b.print();
    cout<<"The det of A is: "<<A.determinant()<<endl;

    LinearSystem linearSys(A, b);
    Vector solution = linearSys.Solve();

    cout << "Linear System Solution:\n";
    for (int i = 1; i <= solution.GetSize(); i++){
        cout << "x" << i << " = " << solution(i) <<endl;
    }
    
    cout<<"Hence all the functions are used and showed...";

    return 0;
}
