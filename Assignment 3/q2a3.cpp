#include <iostream>
#include <cmath>
using namespace std;

class matrix{
    private:
        double** a;    //double pointer for matrix elements
        int row;        //row of the matrix
        int col;        //column of matrix

    public:
        //constructor
        matrix(int row,int col) : row(row),col(col){
            a = new double*[row];
            for(int i=0;i<row;i++){
                a[i] = new double[col];
        }
    }

   //function to input matrix elements
    void takeinput(){
        cout<<"Enter matrix elements row-wise:"<<endl;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++) {
                cin>>a[i][j];
            }
        }
    }

    void get(){
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cout<<a[i][j]<<" ";
            }
        cout<<endl;
        }
    }
    

    //function to calculate one-norm
    double oneNorm() const{
        double maxcolsum = 0.0;
        for(int j=0;j<col;j++){
            double tempcolsum = 0.0;
            for(int i=0;i<row;i++){
                tempcolsum += abs(a[i][j]);
            }
            if(tempcolsum > maxcolsum){
                maxcolsum = tempcolsum;
            }
        }
        return maxcolsum;
    }

    //function to calculate maximum norm
    double maxNorm() const{
       double maxrowsum = 0.0;
        for(int i=0;i<row;i++){
            double temprowsum = 0.0;
            for(int j=0;j<col;j++){
                temprowsum += abs(a[i][j]);
            }
            if(temprowsum > maxrowsum){
                maxrowsum = temprowsum;
            }
        }
        return maxrowsum;
    }

    //function to calculate Frobenius-2 norm
    double frobNorm() const{
        double sum = 0.0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                sum += a[i][j] * a[i][j];
            }
        }
        return sqrt(sum);
    }


    //overloading  + operator for matrix addition
    void operator+(const matrix& other) const{
        if(row != other.row || col != other.col){
            cout<<"matrix orders do not match for addition"<<endl;
        }else{
            matrix sum_mat(row, col);
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    sum_mat.a[i][j] = a[i][j] + other.a[i][j];
                }
            }
            sum_mat.get();
        }
    }

    //overloading - operator for matrix subtraction
    void operator-(const matrix& other) const{
        if(row != other.row || col != other.col){
            cout<<"matrix orders do not match for subtraction"<<endl;
        }else{
            matrix sub_mat(row, col);
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    sub_mat.a[i][j] = a[i][j] - other.a[i][j];
                }
            }
            sub_mat.get();
        }
    }

    //overloading * operator for matrix multiplication
    void operator*(const matrix& other) const{
        if(col != other.row){
            cout<<"matrix orders do not match for multiplication"<<endl;
        }else{
            matrix mul_mat(row, other.col);
            for(int i=0;i<row;i++){
                for(int j=0;j<other.col;j++){
                    mul_mat.a[i][j] = 0.0;
                    for(int k=0;k<col;k++){
                        mul_mat.a[i][j] += a[i][k] * other.a[k][j];
                    }
                }
            }
            mul_mat.get();
        }
    }
    //destructor to free memory
    ~matrix(){
        for (int i=0;i<row;i++){
            delete[] a[i];
        }
        delete[] a;
    }
};



int main(){
    int r,c;
    cout<<"Enter the number of rows and columns for the 1st matrix, A: ";
    cin>>r>>c;

    matrix A(r, c);   //creating a matrix A with row r , column c
    //taking input for matrix A
    A.takeinput();
    cout<<"The matrix A is :"<<endl;
    A.get();     //printing A

    //calculating and printing the one, maximum and Frobenius-2 norms of A
    cout<<"One Norm of A is: "<<A.oneNorm()<<endl;
    cout<<"Maximum Norm of A is: "<<A.maxNorm()<<endl;
    cout<<"Frobenius-2 Norm of A is: "<<A.frobNorm()<<endl;

    int r1,c1;
    cout<<"Enter the number of rows and columns for the 2nd matrix, B: ";
    cin>>r1>>c1;

    matrix B(r1, c1);   //creating a matrix B with row r1 , column c1
    //taking input for matrix B
    B.takeinput();
    cout<<"The matrix B is :"<<endl;
    B.get();       //printing B


    //evaluating the operators
    cout<<"Matrix A + B:"<<endl;
    A + B;   //matrix addition

    cout<<"Matrix A - B:"<<endl;
    A - B;   //matrix subtraction

    cout<<"Matrix A * B:"<<endl;
    A * B;   //matrix multiplication

    return 0;
}

