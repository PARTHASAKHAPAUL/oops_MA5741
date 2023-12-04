#include<iostream>
#include "rk4.hpp"

RungeKuttaSolver::RungeKuttaSolver()
{

}

// Implementing the right-hand side of the ODE for Runge-Kutta method
double RungeKuttaSolver::RightHandSide(double y, double t)
{
    return 1.0 + t;   // our ODE function
}

// Implementing the fourth-order Runge-Kutta method for solving the ODE
double RungeKuttaSolver::SolveEquation()
{
    FILE *outputFile = fopen("output_rk.txt", "w"); 

    double y = initialValue;
    double h = stepSize;
    double t = initialTime;
    fprintf(outputFile, "%f %f\n", t, y);

    while (t <= finalTime - h)
    {
        double k1 = h * RightHandSide(y, t);
        double k2 = h * RightHandSide(y + 0.5 * k1, t + 0.5 * h);
        double k3 = h * RightHandSide(y + 0.5 * k2, t + 0.5 * h);
        double k4 = h * RightHandSide(y + k3, t + h);

        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
        t += h;
        fprintf(outputFile, "%f %f\n", t, y);
    }
    fclose(outputFile);


    return y;
}
