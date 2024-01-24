#include <iostream>
using namespace std;

int main(){
  int num;
  int min = 1000000000;
  int max = 2;
  int input;
  
  cin >> num;
  for(int i=0; i<num; i++){
    cin >> input;
    if(input > max){
      max = input;
    }

    if(input < min){
      min = input;
    }
  }

  cout << max * min;
}