#include <iostream>
#include <vector>
using namespace std;

// 에라토스테네스의 체
vector<int> eratos(int n) {
  vector<int> result(n + 1, 1);

  for (int i = 2; i * i <= n; i++) {
    if (result[i]) {
      for (int j = i * i; j <= n; j += i)
        result[j] = 0;
    }
  }

  return result;
}

int goldbach(int num) {
  vector<int> eratosTable = eratos(num);

  int result = 0;
  for (int i = 2; i <= num / 2; i++) {
    if (eratosTable[i] && eratosTable[num - i]) {
      result++;
    }
  }

  return result;
}

int main() {
  int testNum;
  cin >> testNum;

  int inputNum;

  for (int i = 0; i < testNum; i++) {
    cin >> inputNum;
    cout << goldbach(inputNum) << endl;
  }

  return 0;
}