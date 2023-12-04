#include <iostream>
#include <cmath>
using namespace std;

class Vector{
private:
    double* a;        //pointer to store vector elements
    int size;        //size of the vector

public:
    //constructor
    Vector(int size) : size(size){
        a = new double[size]; //creating memomry for vector elements
    }

    //function to set the value of an element in the vector
    void set(int i, double value){
        if(i >= 0 && i< size){
            a[i] = value;
        }else{
            cout<<"cannot insert"<<endl;
        }
    }

    //function to get the value of an element of the vector at a index
    double get(int i) const{
        if(i >= 0 && i < size){
            return a[i];
        }else{
            cout<<"does not exist"<<endl;
            return 0.0;
        }
    }

    //function to calculate the one-norm of the vector
    double oneNorm() const{
        double norm = 0.0;
        for(int i = 0;i < size;i++){
            norm += abs(a[i]);
        }
        return norm;
    }

    //function to calculate the two-norm of the vector
    double twoNorm() const{
        double norm = 0.0;
        for(int i = 0;i < size;i++){
            norm += a[i] * a[i];
        }
        return sqrt(norm);
    }

    //function to calculate the maximum norm of the vector
    double maxNorm() const{
        double norm = 0.0;
        for(int i = 0;i < size;i++){
            double absValue = abs(a[i]);
            if(absValue > norm){
                norm = absValue;
            }
        }
        return norm;
    }

    Vector operator+(const Vector& other) const{
        if(size != other.size){
            cout<<"Vector sizes do not match for addition"<<endl;
        }

        Vector sum(size);
        for(int i=0;i<size;i++){
            sum.a[i] = a[i] + other.a[i];
        }
        return sum;
    }

    Vector operator-(const Vector& other) const{
        if(size != other.size){
            cout<<"Vector sizes do not match for subtraction"<<endl;
        }

        Vector minus(size);
        for(int i=0;i<size;i++){
            minus.a[i] = a[i] - other.a[i];
        }
        return minus;
    }

    Vector operator*(const Vector& other) const{
        Vector prod(size);
        for (int i=0;i<size;i++) {
            prod.a[i] = a[i] * other.a[i];
        }
        return prod;
    }
    
    double& operator[](int i){
        if(i >= 0 && i < size){
            //cout<<a[i]<<"  ";
            return a[i];
            //cout<<a[i];
        }else{
            throw("Index out of bounds");
        }
    }

    Vector operator*(double s) const{
        Vector prod_s(size);
        for (int i=0;i<size;i++){
            prod_s.a[i] = a[i] * s;
        }
        return prod_s;
    }

    
    //destructor
    ~Vector(){
        delete[] a; //deallocating memory
    }
   
};

int main() {
    Vector v1(3),v2(3); //creating two vectors of size 3

    //setting the elements of the vector
    v1.set(0, 1.0);
    v1.set(1, -2.0);
    v1.set(2, -7.0);
    v1.set(3, 0.5);  //for showing a index that cannot exist
    cout<<"the vector v1:"<<endl;  //printing v1
    for(int i= 0;i<3;i++){
        cout<<v1.get(i)<<" ";
    }
    cout<<endl;

    v2.set(0, 2.0);
    v2.set(1, 1.0);
    v2.set(2, -1.0);
    cout<<"the vector v2:"<<endl;  //printing v2
    for(int i= 0;i<3;i++){
        cout<<v2.get(i)<<" ";
    }
    cout<<endl;

    //calculating and printing the norms
    cout<<"One-Norm of v1: "<<v1.oneNorm()<<endl;
    cout<<"Two-Norm of v1: "<<v1.twoNorm()<<endl;
    cout<<"Maximum Norm of v1: "<<v1.maxNorm()<<endl;


    //vector addition
    Vector v3 = v1 + v2;
    cout<<"vector addition of v1 and v2:"<<endl;
    for(int i= 0;i<3;i++){
        cout<<v3.get(i)<<" ";
    }
    cout<<endl;

    //vector subtraction
    Vector v4 = v1 - v2;
    cout<<"vector subtraction of v1 and v2:"<<endl;
    for(int i=0;i<3;i++){
        cout<<v4.get(i)<<" ";
    }
    cout<<endl;

    //vector multiplication
    Vector v5 = v1 * v2;
    cout<<"vector multiplication of v1 and v2:"<<endl;
    for(int i=0;i<3;i++){
        cout<<v5.get(i)<<" ";
    }
    cout<<endl;

    Vector v(3);

    //setting the elements of the vector by [] operator
    v[0] = 1.0;
    v[1] = 8.0;
    v[2] = -7.0;
    //v[3]=5;

    cout<<"vector [] operator overloading and a vector v is:"<<endl;
    for(int i = 0; i<3;i++){
        cout<<v.get(i)<<" ";
    }
    cout<<endl;

    //scalar multiplication with a vector and a scalar
    Vector v6 = v1 * 5;
    cout<<"scalar multiplication of v1 and 5:"<<endl;
    for(int i=0;i<3;i++){
        cout<<v6.get(i)<<" ";
    }
    cout<<endl;
    
    return 0;
}
