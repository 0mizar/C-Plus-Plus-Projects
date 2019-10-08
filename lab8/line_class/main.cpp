#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
#include <cstdlib>

using namespace std;

// Please replace this Point class with your version from Part B
class Point {

    // cout implementation for Point class
    friend ostream & operator<<( ostream &output, const Point &P ){
        output << "x: " << P.x << " y: " << P.y;
        return output;
    }

    // cin implementation for Point class
    friend istream & operator>>( istream &input, Point &P ){
        input >> P.x >> P.y;
        return input;
    }

public:
    Point(){
        x = 0;
        y = 0;
    }

    Point(double in_x, double in_y){
        x = in_x;
        y = in_y;
    }

    void setX(double in_x){
        x=in_x;
    }

    void setY(double in_y){
        y = in_y;
    }

    double getX(){
        return x;
    }

    double getY(){
        return y;
    }

private:


    double x,y;
};

class Line {
    // implement cout for Line classes objects
    friend ostream & operator<<( ostream &output, const Line &L ){
        output << "Point 1: " << L.P1 << endl << "Point 2: " << L.P2;
        return output;
    }

    // implement cin for Line classes objects
    friend istream & operator>>( istream &input, Line &L ){
        input >> L.P1 >> L.P2;
        return input;
    }

public:
    // Add your functions/methods here //
    Line(){
        P1.setX(0);
        P1.setY(0);
        P2.setX(0);
        P2.setY(0);
    }

    Line(int in_x1,int in_y1,int in_x2,int in_y2){
        P1.setX(in_x1);
        P1.setY(in_y1);
        P2.setX(in_x2);
        P2.setY(in_y2);
    }

    Point getP1(){
        return P1;
    }

    Point getP2(){
        return P2;
    }

    double slope(){
        double m;
        double deltaX=P2.getX()-P1.getX();
        double deltaY=P2.getY()-P1.getY();
        m=deltaY/deltaX;
        return m;
    }

    double length(){
        double deltaX=P2.getX()-P1.getX();
        double deltaY=P2.getY()-P2.getX();
        double l = sqrt(deltaX*deltaX+deltaY*deltaY);
        return l;
    }

    double yInt(){
        double y;
        y= P1.getY()-slope()*P1.getX();
        return y;
    }

    void Horizontal(){
        if (slope()==0.0){
            cout<<"This line is horizontal."<<endl;
        }}
    void Vertical(){
        if (slope()==INFINITY){
            cout<<"This line is vertical."<<endl;
        }
    }
    void Parallel(Line L2){
        if (slope()==L2.slope()){
            cout<<"The two lines are parallel."<<endl;
        }
        else{
            cout<<"The two lines are not parallel."<<endl;
        }
    }


private:

    Point P1, P2;
};

int main(){
    Line L1;
    Line L2;
    // Line L2(5,6,7,8);
    cout << "L1: should have all zeros for values" << endl;
    cout << L1 << endl;

    cout << "Enter Two Points For Line 1: ";
    cin >> L1;
    cout << L1 << endl;

    cout<<"Enter Two Points For Line 2: ";
    cin>>L2;

    cout<<"Line 1 Stats"<<endl;
    cout<<"The Slope is: "<<L1.slope()<<endl;
    cout<<"The Length is: "<<L1.length()<<endl;
    cout<<"Y intercept is: "<<L1.yInt()<<endl;
    L1.Parallel(L2);
    L1.Horizontal();
    L1.Vertical();



    return 0;
}
