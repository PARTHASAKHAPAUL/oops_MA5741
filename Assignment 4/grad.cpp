#include "grad.hpp"
#include <iostream>

using namespace std;

GraduateStudent::GraduateStudent(string studentName, double fines, double fees, bool fullTime) : Student(studentName, fines, fees) {
    //lib_fine=fines+51;
    is_full_time = fullTime;
    }

void GraduateStudent::print_grad_student() const {
    print();
    cout << "Study Type: " << (is_full_time ? "Full-Time" : "Part-Time") << endl;
}
