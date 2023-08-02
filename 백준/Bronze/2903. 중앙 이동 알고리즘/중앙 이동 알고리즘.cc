#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int vertexForOneSide = 2;
    int iteration;
    
    cin >> iteration;
    for(int i=0; i< iteration; i++){
        vertexForOneSide += vertexForOneSide-1;
    }   
    int result = pow(vertexForOneSide, 2);
    cout << result;
}