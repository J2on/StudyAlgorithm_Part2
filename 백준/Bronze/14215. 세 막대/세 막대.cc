#include <iostream>
using namespace std;

int main(){
    int max = 0;
    int sum = 0;
    
    int input;
    for(int i=0; i<3; i++){
        cin >> input;
        if(input > max){
            max = input;
        }
        sum += input;
    }
    
    sum -= max; //이러면 sum에는 max를 제외한 두 변의 합;
    
    if(max >= sum){
        max -= (max-sum)+1;
    }
    
    
    cout << sum + max;
}