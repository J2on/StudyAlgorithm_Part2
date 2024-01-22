#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int num;
  cin >> num;
  
  int result = 0;
  for(int i=1; i*i <= num; i++){
    result++;
  }
  cout << result;
}