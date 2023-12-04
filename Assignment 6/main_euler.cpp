#include <iostream>
#include <cmath>
#include "AbstractOdeSolver.hpp"
#include "forward_euler.hpp"
using namespace std;

int main()
{
    // Creating an instance of ForwardEulerSolver
    ForwardEulerSolver euler;

    // Setting the step size, time interval, and initial value
    euler.SetStepSize(0.1); // we can adjust the step size here
    euler.SetTimeInterval(0.0, 1.0);
    euler.SetInitialValue(2.0);

    // The RightHandSide is already done in the forward_euler.cpp

    // Calling the SolveEquation method
    double numerical_sol = euler.SolveEquation();

    // Comparing with the analytical solution
    double analytic_sol = (pow(1.0, 2) + 2.0 * 1.0 + 4.0) / 2.0; // Analytical solution: (t^2 + 2t + 4)/2 at t=1

    // Output the results
    cout << "Numerical solution at t=1 is: " << numerical_sol << endl;
    cout << "Analytical solution at t=1 is: " << analytic_sol << endl;

    return 0;
}
