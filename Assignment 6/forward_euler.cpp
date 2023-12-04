#include<iostream>
#include "forward_euler.hpp"

ForwardEulerSolver::ForwardEulerSolver()
{

}

double ForwardEulerSolver::RightHandSide(double y, double t)
{
    // The right-hand side of the ODE for Forward Euler method
    return 1.0 + t;   // ODE function
}

// Implementing the Forward Euler method for solving the ODE
double ForwardEulerSolver::SolveEquation()
{
    FILE *outputFile = fopen("output.txt", "w"); // Open a file to write the results

    double y = initialValue;

    for (double t = initialTime; t <= finalTime - stepSize; t += stepSize)
    {
        //std::cout << "The solution of the given ODE at t=" << t << " is: " << y << std::endl; //for the intermidiate steps
        fprintf(outputFile, "%f %f\n", t, y);
        y += stepSize * RightHandSide(y, t);
    }

    fclose(outputFile);

    return y;
}
