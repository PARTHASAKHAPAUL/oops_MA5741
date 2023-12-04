#ifndef RUNGEKUTTASOLVER_H
#define RUNGEKUTTASOLVER_H

#include "AbstractOdeSolver.hpp"

class RungeKuttaSolver : public AbstractOdeSolver
{
public:
    RungeKuttaSolver();  // Constructor
    virtual double RightHandSide(double y, double t);
    virtual double SolveEquation();
};

#endif
