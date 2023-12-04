#include "student.hpp"
#include <iostream> 

using namespace std;

Student::Student(string studentName, double fines, double fees) {
    name = studentName;
    set_lib_fines(fines);
    tut_fees = fees;
}

void Student::set_lib_fines(double fines) {
    if (fines >= 0) {
        lib_fine = fines;
    } else {
        cout << "\n\n As you are trying to put negative Library fines, hence that cannot be possible. Thus setting Library fines to 0." << endl;
        lib_fine = 0;
    }
}

double Student::get_lib_fines() const {
    return lib_fine;
}

double Student::total_owed() const {
    return lib_fine + tut_fees;
}

void Student::print() const {
    cout << "\nStudent's Name: " << name << endl;
    cout << "Library Fines (by first method) : Rs. " << lib_fine << endl;
    cout << "Tuition Fees: Rs. " << tut_fees << endl;
    cout << "Total Money Owed : Rs. " << total_owed() << endl;
}
