#include <iostream>
using namespace std;

int main(){
    int lengths[3];
    
    while(1){
        cin >> lengths[0] >> lengths[1] >> lengths[2];
        if(lengths[0] == 0 && lengths[1] == 0 && lengths[2] == 0){
            break;
        }
        else if(lengths[0] >= lengths[1] + lengths[2] || lengths[1] >= lengths[0] + lengths[2] || lengths[2] >= lengths[1] + lengths[0]){
            cout << "Invalid";            
        }
        else if(lengths[0] == lengths[1] && lengths[1] == lengths[2]){
            cout << "Equilateral";
        }
        else if(lengths[0] == lengths[1] && lengths[1] != lengths[2]){
            cout << "Isosceles";
        }
        else if(lengths[0] == lengths[2] && lengths[1] != lengths[2]){
            cout << "Isosceles";
        }
        else if(lengths[1] == lengths[2] && lengths[0] != lengths[2]){
            cout << "Isosceles";
        }
        else{
            cout << "Scalene";
        }
        cout << endl;
    }
}