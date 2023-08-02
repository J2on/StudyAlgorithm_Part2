#include <iostream>
using namespace std;

int main(){
    int firstNum, secondNum;

    while(1){
        cin >> firstNum >> secondNum;
        if(firstNum == 0 && secondNum == 0){
            break;
        }
        
        if(firstNum % secondNum == 0){
                cout << "multiple";
        }
        else if(secondNum % firstNum == 0){
                cout << "factor";
        }
        else{
                cout << "neither";
        }
            
        cout << endl;
        
    }
}