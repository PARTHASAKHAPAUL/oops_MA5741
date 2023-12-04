#include <iostream>
#include <math.h>
using namespace std;

class matrix{
    private:
    double a[3][3]; //decalring a 2D array with dimension 2*2 named 'a'
    
    public:
    //default constructor
    matrix(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                a[i][j]=0.0;         //initializing a 2D array by default constructor where the all elements are 0
            }
        }
    }

    //copy constructor
    matrix(const matrix& some){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                a[i][j]=some.a[i][j];
            }
        }
    }

    //determinant finder function
    double det(){
        return a[0][0]*(a[1][1]*a[2][2]-a[1][2]*a[2][1]) + a[0][1]*(a[1][2]*a[2][0]-a[1][0]*a[2][2]) + a[0][2]*(a[1][0]*a[2][1]-a[1][1]*a[2][0]);
    }

    //a function to take input from user
    void get(){
        cout<<"Enter the values of the matrix(rowwise) whose inverse has to be calculated: "<<endl;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cin>>a[i][j];
            }
        }
    }

    //a function to find inverse of a matrix
    void inverse(){
        //storing elements of matrix
        double p=a[0][0],q=a[0][1],r=a[0][2];
        double s=a[1][0],t=a[1][1],u=a[1][2];
        double v=a[2][0],w=a[2][1],x=a[2][2];
        //creating a 2D array to store the elements of the inverse of the matrix
        double temp[3][3];
        temp[0][0]=(t*x-u*w)/det();
        temp[0][1]=-(q*x-r*w)/det();
        temp[0][2]=(q*u-r*t)/det();
        temp[1][0]=-(s*x-u*v)/det();
        temp[1][1]=(p*x-r*v)/det();
        temp[1][2]=-(p*u-r*s)/det();
        temp[2][0]=(s*w-t*v)/det();
        temp[2][1]=-(p*w-q*v)/det();
        temp[2][2]=(p*t-q*s)/det();
        //storing the values to the inverse matrix(specifically assigning the inverse values to the calling matrix itself)
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                a[i][j]=temp[i][j];
            }
        }
    }

    //a function to determine wheather a matrix is singular or not
    bool singular(matrix a){
        if(a.det()==0){
            return 1;
        }else{
            return 0;
        }
    }

    //printing matrices
    void print(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<a[i][j]<<"   ";
            }
            cout<<endl;
        }
    }
};

int main(){
    matrix a;  //creating an object by default constructor
    cout<<"The matrix called by default constructor is : "<<endl;
    a.print();  //printing the matrix a
    
    matrix b(a);  //an object creation by copy constructor
    cout<<"The matrix called by copy constructor is : "<<endl;
    b.print();

    //decalring and taking input for finding inverse of a matrix
    matrix c;
    c.get();
    cout<<"Determinant of the matrix whose inverse has to be calculated: "<<c.det()<<endl;
    if(c.det()==0){
        cout<<"Matrix is not invertible. Inverse does not exist(as the determinant is zero)."<<endl;
    }else{
        cout<<"Inverse of matrix is : "<<endl;
        c.inverse();
        c.print();
    }

    //checking the matrices are singular or not
    if(a.singular(a)){
        cout<<"The matrix(by default constructor) is singular "<<endl;
    }else{
        cout<<"The matrix(by default constructor) is non-singular"<<endl;
    }
    if(b.singular(b)){
        cout<<"The matrix(by copy constructor) is singular "<<endl;
    }else{
        cout<<"The matrix(by copy constructor) is non-singular"<<endl;
    }
    if(c.singular(c)){
        cout<<"The matrix(by user-input) is singular "<<endl;
    }else{
        cout<<"The matrix(by user-input) is non-singular"<<endl;
    }
}