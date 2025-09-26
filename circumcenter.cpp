#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

long double dist_sq(long double a,long double b){
    return a*a+b*b;
}

int main(){
    long double x1,y1,x2,y2,x3,y3;
    
    cin >> x1 >> y1
        >> x2 >> y2
        >> x3 >> y3;
    
    long double d1,d2,d3;
    d1 = dist_sq(x1,y1);
    d2 = dist_sq(x2,y2);
    d3 = dist_sq(x3,y3);
    
    long double denominator = 
    2*((x2-x3)*(y1-y2)-(x1-x2)*(y2-y3));
    
    if(fabsl(denominator)<1e-15L){
        cout << "Points are collinear" << '\n';
        return 0;
    }
    //X,Yはそれぞれ外心のx,y座標
    long double numerator_X =
    -(d1*(y2-y3)+d2*(y3-y1)+d3*(y1-y2));
    
    long double numerator_Y =
    d1*(x2-x3)+d2*(x3-x1)+d3*(x1-x2);

    cout << fixed << setprecision(10)
         << numerator_X/denominator << " " 
         << numerator_Y/denominator << '\n';
}