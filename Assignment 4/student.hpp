#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <string>

using namespace std;

class Student {
//private:
//public:
protected:
    double lib_fine;    //double precision floating-point variable for library fines

public:
//protected:
    string name;
    double tut_fees;    // double precision floating-point variable for tuition fees

    Student(string studentName, double fines, double fees);      //constructor to initialize the name, library fines and tuition fees

    void set_lib_fines(double fines);     //one method that allows the user to set this variable(library fines) only to nonnegative values
    double get_lib_fines() const;         //another method that can be used to access the private variable
    double total_owed() const;            //a method that returns the total money owed by the student,that is, the sum of the library fines and tuition fees associated with a given student
    void print() const;                   //public member function to display student's information
};

#endif

