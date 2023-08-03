#include<iostream>
using namespace std;

int main(){
    long num;
    cin >> num;
    long long sum = 0;
    
    for(long i = 1; i <= num-2; i++){
      sum += i*(i+1)/2;
    }
    cout << sum << endl << 3;
}