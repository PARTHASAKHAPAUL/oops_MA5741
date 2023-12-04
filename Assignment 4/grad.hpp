#ifndef GRADUATESTUDENT_HPP
#define GRADUATESTUDENT_HPP
#include "student.hpp"

using namespace std;

class GraduateStudent : public Student {
private:
    bool is_full_time;     //for indicating whether the student is full-time or part-time

public:
    GraduateStudent(string studentName, double fines, double fees, bool fullTime);
    void print_grad_student() const;     //public member function to display student's information
};

#endif


