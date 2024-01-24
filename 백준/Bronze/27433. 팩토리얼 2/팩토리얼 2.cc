#include <iostream>
using namespace std;

long long factorial(int num){
  if(num != 0){
    return num * factorial(num-1);
  }
  else{
    return 1;
  }
  
}

int main() {
  int num;
  cin >> num;
  cout << factorial(num);
}