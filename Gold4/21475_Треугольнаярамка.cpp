#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

long double Heron(long double a, long double b, long double c){
    long double s = (a+b+c)/2;
    return pow((s*(s-a)*(s-b)*(s-c)), 0.5);
}

long double insideCircle(long double a, long double b, long double c, long double size){
    long double s = (a+b+c)/2;
    return size / s;
}


int main(){
    cout.precision(5);

    long double a, b, c, d;
    cin >> a >> b >> c >> d;

    long double size = Heron(a, b, c);
    long double bigR = insideCircle(a, b, c, size);
    long double smallR = bigR-d;

    long double rate = smallR / bigR;
    cout << fixed << setprecision(5);
    cout << size * (1 - rate * rate);
}