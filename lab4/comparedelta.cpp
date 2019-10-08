#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool compareDelta(double a,double b,double c){
    if (fabs(a-b)<=c){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    double a,b,c;
    bool g;
    string e;
    cout<<"Number 1: "<<endl;
    cin>>a;
    cout<<"Number 2: "<<endl;
    cin>>b;
    cout<<"Delta: "<<endl;
    cin>>c;

    g = compareDelta(a,b,c);
    if (g == true){
        e = "true";
    }
    else{
        e = "false";
    }


    cout<<e<<endl;



    return 0;
}
