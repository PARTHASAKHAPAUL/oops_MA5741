#include "phd.hpp"
#include <iostream>

using namespace std;

PhDStudent::PhDStudent(string studentName, double fines, double fees, bool fullTime)
    : GraduateStudent(studentName, fines, fees, fullTime) {}

double PhDStudent::total_owed_phd() const {
    return total_owed() + 5000.00 - get_lib_fines();  //assuming that Ph.D. students pay an additional research fee of Rs. 5000
}

void PhDStudent::print_phd_student() const {
    print_grad_student();
    cout << "Student Type: PhD" << endl;
    cout << "Total Money(without library fines but including a research fees of 5000) Owed (PhD): Rs. " << total_owed_phd() << endl;
}
