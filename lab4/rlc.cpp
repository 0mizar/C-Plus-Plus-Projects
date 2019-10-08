#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;
double const pi = 3.14159265359;

double convertFreq(double f){
    return(2*pi*f);
}

double ACPeriod(double f){
    return(1/f);
}

double AppliedVolts(double Eo,double omega,double t){
    return(Eo*sin(omega*t));
}

double CurrentAmps(double omega,double Eo,double L,double C,double R){
    return((omega*Eo)/sqrt(pow(L*pow(omega,2)-(1/C),2)+(pow(R,2)*pow(omega,2))));
}

double PhaseAngle(double L,double omega,double R,double C){
    return(atan(((L*omega)/R)-(1/(R*C*omega))));
}

double TotalCurrent(double omega,double A,double t,double phi){
    return(A*sin((omega*t)-phi));
}

double ResistorVolt(double R,double A,double omega,double t,double phi){
    return(R*A*sin((omega*t)-phi));
}

double InductorVolt(double L,double omega,double A,double t,double phi){
    return(L*omega*A*cos((omega*t)-phi));
}

double CapacitorVolt(double A,double C,double omega, double t,double phi){
    return(((-1*A)/(C*omega))*cos((omega*t)-phi));
}

double ThetaT(double nstep,double T){
    return(T/nstep);
}

int vDiffy(double VR,double VL,double VC,double V){
    return(V-(VR+VL+VC));
}


int main(){
    double R, L, C, A, phi, f, omega, Eo, T, ChangeT;
    //(R=resistor value)(L=inductor value)(C=capacitor value)(A=amplitude)(phi = phase angle)
    //(f = freq.)(omega = circ. line freq.)(Eo=applied volt amps)(T=circuit period)
    double nstep; // #timesteps/cycle
    double t, I, VR, VL, VC, Vdiff, V;

    cout<<"Enter Applied voltage amplitude(Eo): "<<endl;
    cin>>Eo;//use in applied volts function and set equal to result
    cout<<"Enter line frequency(f): "<<endl;
    cin>>f;//use in convertFreq & ACPeriod
    cout<<"Enter Resistor Value(R): "<<endl;
    cin>>R;
    cout<<"Enter Inductor Value(L): "<<endl;
    cin>>L;
    cout<<"Enter Capacitor Value(C): "<<endl;
    cin>>C;
    cout<<"Enter data points per AC period(nstep): "<<endl;
    cin>>nstep;

    omega= convertFreq(f);
    phi= PhaseAngle(L,omega,R,C);
    T= ACPeriod(f);
    ChangeT=ThetaT(nstep,T);
    A=CurrentAmps(omega,Eo,L,C,R);
    t=0;
    cout<<"Current Amplitude: "<<A<<endl;
    cout<<"Phase Angle: "<<phi*(180/pi)<<endl;

    cout<<left<<setw(15)<<setfill(' ')<<"Iter.";
    cout<<left<<setw(15)<<setfill(' ')<<"Time";
    cout<<left<<setw(15)<<setfill(' ')<<"AV";
    cout<<left<<setw(15)<<setfill(' ')<<"I";
    cout<<left<<setw(15)<<setfill(' ')<<"VR";
    cout<<left<<setw(15)<<setfill(' ')<<"VL";
    cout<<left<<setw(15)<<setfill(' ')<<"VC";
    cout<<left<<setw(15)<<setfill(' ')<<"VT";
    cout<<left<<setw(15)<<setfill(' ')<<"Vdiff";
    cout<<endl;

    for(int i=0;i<nstep*2;++i){
    cout<<left<<setw(15)<<setfill(' ')<<i;
    cout<<left<<setw(15)<<setfill(' ')<<t;
    cout<<left<<setw(15)<<setfill(' ')<<AppliedVolts(Eo,omega,t);
    cout<<left<<setw(15)<<setfill(' ')<<TotalCurrent(omega,A,t,phi);
    cout<<left<<setw(15)<<setfill(' ')<<ResistorVolt(R,A,omega,t,phi);
    cout<<left<<setw(15)<<setfill(' ')<<InductorVolt(L,omega,A,t,phi);
    cout<<left<<setw(15)<<setfill(' ')<<CapacitorVolt(A,C,omega,t,phi);
    cout<<left<<setw(15)<<setfill(' ')<<AppliedVolts(Eo,omega,t);
    cout<<left<<setw(15)<<setfill(' ')<<vDiffy(ResistorVolt(R,A,omega,t,phi),InductorVolt(L,omega,A,t,phi),CapacitorVolt(A,C,omega,t,phi),AppliedVolts(Eo,omega,t));
    cout<<endl;


        t=t+ChangeT;
    }}
