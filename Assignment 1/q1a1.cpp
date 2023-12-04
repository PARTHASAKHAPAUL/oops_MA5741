/*
OOPS ASSIGNMENT 1 SUBMISSION
NAME: PARTHA SAKHA PAUL
ROLL: MA23M016
DATE: 28-08-2023
*/



#include<iostream>
#include<cassert>
#include<math.h>
using namespace std;

//function to multiply two given matrices::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//here we take:
//m = number of rows of the 1st matrix
//n = number of columns of the 1st matrix
//p = number of rows of the 2nd matrix
//q = number of columns of the 2nd matrix
void Multiply(int m,int n,int p,int q,double** A,double** B){
    //initializing the multiply(result) matrix:
    double **C;
    C = new double* [m];
    for(int i=0;i<m;i++){
        C[i] = new double [q];
    }
    //program for finding multiplication of the matrices A,B:
    cout<<"The result matrix of order ("<<m<<"*"<<q<<"), after the multiplication of 1st and 2nd matrices, is: "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<q;j++){
            C[i][j]=0;
            for(int k=0;k<n;k++){
                C[i][j]=C[i][j] + A[i][k] * B[k][j];
            }
            cout<<C[i][j]<<"  ";
        }
        cout<<endl;
    }
}




//function to multiply given vector(of size 1*m) and matrix(of size m*n)::::::::::::::::::::::::::::::::::::::::::::::::
//here we take:
//m = number of rows of the 1st matrix
//n = number of columns of the 1st matrix
void Multiply(int m,int n,int col_r,double** v,double** A){
    //initializing the multiply(result) vector:
    double **C;
    C = new double* [1];
    for(int i=0;i<1;i++){
        C[i] = new double [n];
    }
    //program for finding multiplication of the vector v and the matrix A:
    cout<<"The result vector, of size: (1*"<<n<<") after the multiplication of the vector v and the matrix A, is given by: "<<endl;
    for(int i=0;i<1;i++){
        for(int j=0;j<n;j++){
            C[i][j]=0;
            for(int k=0;k<m;k++){
                C[i][j]=C[i][j] +  v[i][k] * A[k][j];
            }
            cout<<C[i][j]<<"  ";
        }
        cout<<endl;
    }
}



//function to multiply given matrix(of size m*n) and vector(of size n*1) ::::::::::::::::::::::::::::::::::::::::::::::::
//here we take:
//m = number of rows of the 1st matrix
//n = number of columns of the 1st matrix
void Multiply(double** A,double** w,int m,int n,int row_c){
    //initializing the multiply(result) vector:
    double **C;
    C = new double* [m];
    for(int i=0;i<m;i++){
        C[i] = new double [1];
    }
    //program for finding multiplication of the matrix A and the vector w:
    cout<<"The result vector, of size: ("<<m<<"*1) after the multiplication of the matrix A and the vector w, is given by: "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<1;j++){
            C[i][j]=0;
            for(int k=0;k<n;k++){
                C[i][j]=C[i][j] +  A[i][k] * w[k][j];
            }
            cout<<C[i][j]<<"  ";
        }
        cout<<endl;
    }
}





//function to multiply given a scalar and a matrix(of size m*n) ::::::::::::::::::::::::::::::::::::::::::::::::
//here we take:
//m = number of rows of the 1st matrix
//n = number of columns of the 1st matrix
void Multiply(int m,int n,int s,double** A){
    //program for finding multiplication of the scalar s and the matrix A :
    cout<<"Enter the scalar that is to be multiplied: ";
    cin>>s;
    cout<<"The result matrix of order ("<<m<<"*"<<n<<"), after the multiplication of the scalar "<<s<<" with the matrix A, is: "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            A[i][j]=s * A[i][j];
            cout<<A[i][j]<<"  ";
        }
        cout<<endl; 
    }  
}





//function to multiply given matrix(of size p*q) and a scalar ::::::::::::::::::::::::::::::::::::::::::::::::
//here we take:
//p = number of rows of the 2nd matrix
//q = number of columns of the 2nd matrix
void Multiply(int p,double** B,int q,int s){
    //program for finding multiplication of the matrix B and the scalar s:
    cout<<"Enter the scalar that is to be multiplied: ";
    cin>>s;
    cout<<"The result matrix of order ("<<p<<"*"<<q<<"), after the multiplication of the matrix B with the scalar "<<s<<", is: "<<endl;
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            B[i][j]=B[i][j] * s;
            cout<<B[i][j]<<"  ";
        }
        cout<<endl; 
    }  
}


//function to finding the norm value of a vector:::::::::::::::::::::::::::::::::::::::::::::::
void p_norm(int x[],int p1,int n1){
    double sum = 0;
    for(int i=0;i<n1;i++){
        sum=sum+pow(x[i],p1);  
    }
    double ans=pow(sum,1.0/p1);
    cout<<"The p norm of the given vector is :"<< ans;
}




int main(){
    int m,n,p,q,i,j,k;


    //initializing the 1st matrix:
    cout<<"Enter the size of the 1st matrix: "<<endl;
    cin>>m>>n;
    double **A;
    A = new double* [m];
    for(i=0;i<m;i++){
        A[i] = new double [n];
    }
    cout<<"Enter the elements of the matrix A of size:  ("<<m<<"*"<<n<<")"<<endl;
    //taking input rowwise:
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cin>>A[i][j];  ///???????????
        }
    }
    //printing 1st matrix rowwise:
    cout<<"The 1st matrix is, A: "<<endl;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cout<<A[i][j]<<"  ";
        }
        cout<<endl;
    }
    




    
    //initializing the 2nd matrix:
    cout<<"Enter the size of the 2nd matrix B: "<<endl;
    cin>>p>>q;
    double **B;
    B = new double* [p];
    for(int i=0;i<p;i++){
        B[i] = new double [q];
    }
    //assertion to verify that the matrices are of suitable sizes to be multiplied(here we have to check whether the number of columns of the 1st matrix is equal to the number of rows of the 2nd matrix):
    assert(n==p);
    cout<<"Enter the elements of the matrix B of size:  ("<<p<<"*"<<q<<")"<<endl;
    //taking input rowwise:
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            cin>>B[i][j];
        }
    }
    //printing 2nd matrix rowwise:
    cout<<"The 2nd matrix is, B: "<<endl;
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            cout<<B[i][j]<<"  ";
        }
        cout<<endl;
    }





    //initializing the  (1*m) row vector:
    int col_r;       //column of row vector
    cout<<"Enter the number of columns of the row vector: (should be equal to: "<<m<<")"<<endl;
    cin>>col_r;
    double **v;
    v = new double* [1];
    for(i=0;i<1;i++){
        v[i] = new double [col_r];
    }
    //assertion to verify that the vector and the matrix are of suitable sizes to be multiplied(here we have to check whether the number of columns of the vector is equal to the number of rows of the 1st matrix):
    assert(m==col_r);
    cout<<"Enter the elements of the row vector of size (1*"<<col_r<<") :"<<endl;
    //taking input rowwise:
    for(i=0;i<1;i++){
        for(j=0;j<col_r;j++){
            cin>>v[i][j];
        }
    }
    //printing row vector rowwise:
    cout<<"The row vector is, v: "<<endl;
    for(i=0;i<1;i++){
        for(j=0;j<col_r;j++){
            cout<<v[i][j]<<"  ";
        }
        cout<<endl;
    }






    //initializing the  (n*1) column vector:
    int row_c;       //row of column vector
    cout<<"Enter the number of rows of the column vector: (should be equal to: "<<n<<")"<<endl;
    cin>>row_c;
    double** w;
    w = new double* [row_c];
    for(i=0;i<row_c;i++){
        w[i] = new double [1];
    }
    //assertion to verify that the vector and the matrix are of suitable sizes to be multiplied(here we have to check whether the number of rows of the vector is equal to the number of columns of the 1st matrix):
    assert(n==row_c);
    cout<<"Enter the elements of the column vector of size ("<<row_c<<"*1) :"<<endl;
    //taking input rowwise:
    for(i=0;i<row_c;i++){
        for(j=0;j<1;j++){
            cin>>w[i][j];
        }
    }
    //printing column vector rowwise:
    cout<<"The column vector is, w: "<<endl;
    for(i=0;i<row_c;i++){
        for(j=0;j<1;j++){
            cout<<w[i][j]<<"  ";
        }
        cout<<endl;
    }






    //for scalar multiplication let us take the scalar:
    int s;
    
    Multiply(m,n,p,q,A,B);
    Multiply(m,n,col_r,v,A);
    
    Multiply(A,w,m,n,row_c);
    Multiply(m,n,s,A);
    Multiply(p,B,q,s);
    for (int i = 0; i < m; i++)
    {
        delete[] A[i];  ///??????????
    }
    





    //program to finding the norm value of a vector:::::::::::::::::::::::::::::::::::::::::::::::
    int n1,p1;
    //length of the vector
    cout<<"enter the size of the vector:"<<endl;
    cin>>n1;
    int x[n1];

    //taking input of vector
    cout<<"Enter the elements of the vector :";
    for(int i=0;i<n1;i++){
    cin>>x[i];
    }

    //printing the vector
    cout<<"The vector is : "<<endl;
    for(int i=0;i<n1;i++){
    cout<<x[i]<<" ";
    }
    cout<<endl;
    cout<<"Enter the norm(p) value: ";    ///???????????
    cin>>p1;

    p_norm(x,p1,n1);
}