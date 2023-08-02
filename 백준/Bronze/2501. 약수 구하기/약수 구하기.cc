#include <iostream>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    
    int count = 0;
    for(int i=1; i <= N/2; i++){
        if(N % i == 0){
            count++;
            if(count == K){
                cout << i;
            }
        }   
    }

    count++;
    if(count == K){
        cout << N;
    }
    if(count < K){
        cout << 0;
    }
}