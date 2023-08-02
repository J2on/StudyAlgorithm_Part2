#include <iostream>

using namespace std;

int main(){
    int testCase;
    cin >> testCase;
    
    int changeMoney;
    for(int i=0; i<testCase; i++){
        cin >> changeMoney;
        int list[4] = {0,0,0,0};  

        list[0] = changeMoney / 25;
        changeMoney -= 25 * list[0];
        list[1] = changeMoney / 10;
        changeMoney -= 10 * list[1];
        list[2] = changeMoney / 5;
        changeMoney -= 5 * list[2];
        list[3] = changeMoney;
        
        for(int num:list){
            cout << num << ' ';
        }
        cout << endl;
    }
    
}