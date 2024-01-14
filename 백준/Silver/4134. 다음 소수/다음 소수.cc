#include <iostream>

using namespace std;

bool isPrime(long long int num) {
  if (num == 0 || num == 1)
    return false;

  if(num == 2) return true;
  else if (num % 2 == 0)
    return false;
  
  for (long long int i = 3; i * i <= num; i += 2) {
    if (num % i == 0) {
      return false;
    }
  }

  return true;
}

long long int targetPrime(long long int num) {
  // 0과 1인 경우를 특정
  while (!isPrime(num)) {
    num++;
  }
  return num;
}

int main() {
  int testNum;
  cin >> testNum;

  long long int inputNum;
  for (int i = 0; i < testNum; i++) {
    cin >> inputNum;
    cout << targetPrime(inputNum) << endl;
  }
}