using namespace std;

#include <cmath>
#include <iostream>
#include <cstdlib>

int main(){
string grade;
double gradeVal;
double creditHours = 0;
double courses = 0;
double totalCredit = 0;
double hours = 0;
double gpa = 0;
double credit = 0;

cout<<"How many courses are you taking?"<<endl;
cin>> courses;

for (int i=1; i<=courses;i++){
    cout<<"How many credit hours is course "<<i<<"?"<<endl;
    cin>>hours;
    creditHours=creditHours+hours;

    cout<<"What is your letter grade in the course?"<<endl;
    cin>>grade;
    if (grade==("A")||grade ==("a")||grade==("A+")||grade==("a+")){
        gradeVal=4;
    }
    else if (grade==("A-")||grade ==("a-")){
        gradeVal=3.7;
    }
    else if (grade==("B+")||grade ==("b+")){
        gradeVal=3.3;
    }
    else if (grade==("B")||grade ==("b")){
        gradeVal=3.0;
    }
    else if (grade==("B-")||grade ==("b-")){
        gradeVal=2.7;
    }
    else if (grade==("C+")||grade ==("c+")){
        gradeVal=2.3;
    }
    else if (grade==("C")||grade ==("c")){
        gradeVal=2;
    }
    else if (grade==("C-")||grade ==("c-")){
        gradeVal=1.7;
    }
    else if (grade==("D+")||grade ==("d+")){
        gradeVal=1.3;
    }
    else if (grade==("D")||grade ==("d")){
        gradeVal=1.0;
    }
    else if (grade==("D-")||grade ==("d-")){
        gradeVal=0.7;
    }
    else{
        gradeVal=0.0;
    }
    credit=gradeVal*hours;
    totalCredit=totalCredit+credit;
    gpa=totalCredit/creditHours;

}

cout<<"Your final gpa will be "<<gpa<<" with these grades"<<endl;
}
