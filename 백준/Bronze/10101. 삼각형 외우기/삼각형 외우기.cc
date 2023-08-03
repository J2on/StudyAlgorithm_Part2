#include <iostream>
using namespace std;

int main(){
    int angles[3];
    cin >> angles[0] >> angles[1] >> angles[2];
    
    if(angles[0] + angles[1] + angles[2] != 180){
        cout << "Error";
    }
    else if(angles[0] == 60 && angles[1] == 60 && angles[2] == 60 ){
        cout << "Equilateral";
    }
    else if(angles[0] == angles[1] || angles[0] == angles[2] || angles[1] == angles[2]){
        cout << "Isosceles";
    }
    else{
        cout << "Scalene";
    }
}