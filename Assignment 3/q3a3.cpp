#include<iostream>
#include <cmath>
using namespace std;

class GaussQ{
    private:
    double GPts[3]={0,-sqrt(3.0/5.0),sqrt(3.0/5.0)};
    double w[3]={8.0/9.0,5.0/9.0,5.0/9.0};
    
    public:
    //calculating the GQ rule for an arbitrary polynomial x+19*x*x-48*x*x*x+47*x*x*x*x-104*x*x*x*x*x
    double f0(double x){
        return w[0] * (x+19*x*x-48*x*x*x+47*x*x*x*x-104*x*x*x*x*x);  //this is w_0*f(x)
    }
    double f1(double x){
        return w[1] * (x+19*x*x-48*x*x*x+47*x*x*x*x-104*x*x*x*x*x);   //this is w_1*f(x)
    }
    double f2(double x){
        return w[2] * (x+19*x*x-48*x*x*x+47*x*x*x*x-104*x*x*x*x*x);  //this is w_2*f(x)
    }
    
    //function for get the values of GPts+
    
    double getGPts(int i){
        return GPts[i];
    } 
};

//function for finding exact integration value
double integration(double x){
    return 1/2.0 * x*x + 19/3.0 * x*x*x - 16 * x*x*x*x + 47/5.0 * x*x*x*x*x - 104/6.0 * x*x*x*x*x*x;
}

int main(){
    GaussQ g1,g2;

    //finding components of GQ rule
    double a = g1.f0(g1.getGPts(0));
    double b = g1.f1(g1.getGPts(1));
    double c = g1.f2(g1.getGPts(2));
    //summing the three components
    cout<<"The value of the Gauss Quadrature rule: "<<a+b+c<<endl;
    
    //calculating the integration value
    double int_upper = integration(1);
    double int_lower = integration(-1);
    cout<<"The value of the integration is: "<<int_upper - int_lower<<endl<<"HENCE THE RULE IS EXACT FOR POLYNOMIAL OF DEGREE LESS THAN OR EQUAL TO 5";
    
    return 0;
}
