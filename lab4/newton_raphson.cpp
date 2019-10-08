#include<iostream>
#include <cmath>

using namespace std;

const double TOLERANCE = .0001;

double f(double x){
    return(pow(x,4))+(2*pow(x,3))-(31*pow(x,2))-(32*x)+60;
}

double fprime(double x){
    return (4*pow(x,3))+(6*pow(x,2))-(62*x)-32;
}

double newtonRoot(double guess){
    double x = guess;
    double previousX;

    do{
        previousX = x;
        x = previousX - (f(previousX))/(fprime(previousX));
    }while((abs(x-previousX))>TOLERANCE);
           return x;
}

int main(){
    double x;
    bool stop = 0;
    string ans;

    while(!stop){
        cout<<"Enter Guess: "<<endl;
        cin >> x;
        cout<<"Root: "<<newtonRoot(x)<<endl;
        cout<<"Enter another guess: y/n?"<<endl;
        cin >> ans;
        if(ans == "n"){
            cout<<"Goodbye."<<endl;
            stop = 1;
        }

    }
    return 0;
}

