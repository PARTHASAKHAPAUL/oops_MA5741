#include <iostream>
#include <cmath>
#include "rk4.hpp"
using namespace std;

int main()
{
    //Creating a member variable of RungeKuttaSolver
    RungeKuttaSolver rkSolver;

    //Setting the step size, time interval, and initial value
    rkSolver.SetStepSize(0.1); // we can adjust the step size here
    rkSolver.SetTimeInterval(0.0, 1.0);
    rkSolver.SetInitialValue(2.0);

    //The RightHandSide is already done in the rk4.cpp

    //Calling the SolveEquation method
    double numerical_sol = rkSolver.SolveEquation();

    //Comparing with the analytical solution
    double analytic_sol = (pow(1.0, 2) + 2.0 * 1.0 + 4.0) / 2.0; // Analytical solution: (t^2 + 2t + 4)/2 at t=1

    // Output the results
    cout << "Numerical solution (Runge-Kutta) at t=1 is : " << numerical_sol << endl;
    cout << "Analytical solution at t=1 is : " << analytic_sol << endl;

    return 0;
}
