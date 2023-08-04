#include <iostream>
using namespace std;

int main(){
    long a,b,c,d,e,f,x,y;
    cin >> a >> b >> c >> d >> e >> f;
    
    x = (c * e - f * b) / (a * e - d * b);
    y = (c * d - a * f) / (b * d - a * e);
    cout << x << ' ' << y;
}