#ifndef PHDSTUDENT_HPP
#define PHDSTUDENT_HPP
#include "grad.hpp"

using namespace std;

class PhDStudent : public GraduateStudent {
public:
    PhDStudent(string studentName, double fines, double fees, bool fullTime);
    double total_owed_phd() const;
    void print_phd_student() const;          //public member function to display student's information
};

#endif
