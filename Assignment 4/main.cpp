#include <iostream>
#include <string>
#include "student.hpp"
#include "grad.hpp"
#include "phd.hpp"

using namespace std;

int main() {
    //creating a student object
    Student s1("Abhirup Dey", 25.50, 1500.00);
    Student s2("Kamal Roy", 36.00, 1500.00);
    Student s3("Ajay Paul", 30.00, 1000.00);
    Student s4("Kanika Roy", 26.00, 1200.00);

    s1.print();
    s2.print();
    s3.print();
    s4.print();

    // setting library fines using the non-negative method
    s1.set_lib_fines(-0.75); //attempting to set negative fines

    //printing the student's information
    s1.print();
    cout << "Library Fines(by another method) : Rs. " << s1.get_lib_fines() << endl;
    

    //creating a GraduateStudent object with name, library fines, tuition fees and full-time status
    GraduateStudent gradS1("Sayan Bhadra", 10.75, 3000.00, true);

    //creating another GraduateStudent object with name, library fines, tuition fees and part-time status
    GraduateStudent gradS2("Abani Das", 8.25, 3000.00, false);

    //printing the graduate student's information
    gradS1.print_grad_student();
    cout << "Student Type: Graduate" << endl;

    //printing the graduate student's information
    gradS2.print_grad_student();
    cout << "Student Type: Graduate" << endl;
    
    //creating a PhDStudent object with name, library fines, tuition fees and full-time status
    PhDStudent phdStudent("Rajdeep Paul", 25.50, 3500.00, true);

    //printing the Ph.D. student's information
    phdStudent.print_phd_student();
    
    return 0;
}
