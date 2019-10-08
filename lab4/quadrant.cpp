#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int whichQuadrant(double x,double y){
    if((x==0.0)&&(y==0.0)){
        return 'C';}
    else if (x==0.0){
        return 'Y';}
    else if (y==0.0){
        return 'X';}
    else if ((x>0.0)&&(y>0.0)){
        return 1.0;}
    else if ((x<0.0)&&(y>0.0)){
        return 2.0;}
    else if ((x<0.0)&&(y<0.0)){
        return 3.0;}
    else if ((x>0.0)&&(y<0.0)){
        return 4.0;}
    else {
        cout<<"error"<<endl;
        return 0.0;
    }
}
int main(){
 double x;
 double y;
 int ans;
 cout<<"Enter X Y Pair"<<endl;
 cin>>x;
 cin>>y;
 ans = whichQuadrant(x,y);
 if(ans == 'C'){
     cout<<"Center Point"<<endl;}
 else if (ans == 'Y'){
     cout<<"On Y-Axis"<<endl;}
 else if (ans == 'X'){
     cout<<"On X-Axis"<<endl;}
 else if (ans == 1.0){
     cout<<"Quadrant is Q1"<<endl;}
 else if (ans == 2.0){
     cout<<"Quadrant is Q2"<<endl;}
 else if (ans == 3.0){
     cout<<"Quadrant is Q3"<<endl;}
 else if (ans == 4.0){
     cout<<"Quadrant is Q4"<<endl;}
 else {
     cout<<"Error."<<endl;


   return 0;
}}
