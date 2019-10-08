#include <iostream>
#include <cmath>
#include <string>

using namespace std;
const double Q = 1e-9;//Coulomb
const double ke = 9e9;//(N-m^2)/C^2

double Efield(double r, double a = 1){
    if ((r>=0)&&(r<=100)){
        if(r<a){
        return(ke*Q*(r/pow(a,3)));
        }
        else{
        return((ke*Q)/pow(r,2));
        }
}
    else{
        return 0;
    }
}

int main(){
    double r;
    double a;

    cout<<"Enter r: "<<endl;
    cin>>r;
    cout<<"Enter a: "<<endl;
    cin>>a;

    cout<<"Efield: "<<Efield(r,a)<<endl;
}
