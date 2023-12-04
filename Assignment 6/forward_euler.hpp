
#ifndef FORWARDEULERSOLVER_H
#define FORWARDEULERSOLVER_H

#include "AbstractOdeSolver.hpp"

class ForwardEulerSolver : public AbstractOdeSolver
{
public:
    ForwardEulerSolver();  // Constructor
    virtual double RightHandSide(double y, double t);
    virtual double SolveEquation();
};

#endif
