#include <iostream>
#include <math.h>
using namespace std;

class Point3D{
private:
    double x;  //for x-coordinate
    double y;  //for y-coordinate
    double z;  //for z-coordinate

public:
    //an overridden default constructor
    Point3D() : x(0.0), y(0.0), z(0.0){
    }

    //copy constructor
    Point3D(const Point3D& some) : x(some.x), y(some.y), z(some.z){ //???????????
    }

    //a formatted constructor(taking from parameterized constructor)
    Point3D(double x_coor, double y_coor, double z_coor) : x(x_coor), y(y_coor), z(z_coor){
    }

    //a negate() function to transform the point into its negative
    void negate(){
        x=-x;
        y=-y;
        z=-z;
    }

    //a norm() function to return the point’s distance from the origin (0, 0, 0)
    double norm(Point3D point){
        double n = sqrt(pow(point.x,2)+pow(point.y,2)+pow(point.z,2));
        return n;
    }

    //a function to print the coordinates
    void print(){
        cout << "(" << x << "," << y << "," << z <<")"<<endl;
    }
};

int main(){
    //creating Point3D objects using the default and formatted constructors
    Point3D default_point; //calling overridden default constructor
    Point3D formatted_point(1.0, 2.0, 5.0); //calling formatted constructor
    
    //creating a copy of the formatted_point using the copy constructor
    Point3D copied_point(formatted_point);

    //printing the coordinates of the points
    cout<<"Default Point: ";
    default_point.print();

    cout<<"Formatted Point: ";
    formatted_point.print();

    cout<<"Copied Point from the formatted point is: ";
    copied_point.print();

    formatted_point.negate(); //negationing point
    cout<<"After negation of the formatted point,the point is : ";
    formatted_point.print();    

    //finding norm of formatted point
    double n = formatted_point.norm(formatted_point);
    cout<<"The norm of the negated formatted point is: "<<n;
    return 0;
}
