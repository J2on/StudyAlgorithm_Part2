#include <iostream>
using namespace std;

void swap(long long int &numA, long long int &numB) {
  int temp = numA;
  numA = numB;
  numB = temp;
}

long long int findGcd(long long int numA, long long int numB) {
  int numC; // 나머지
  while (1) {
    numC = numA % numB;

    if (numC == 0)
      break;

    swap(numA, numB);
    numB = numC;
  }

  return numB;
}

long long int findLcd(long long int numA, long long int numB,
                      long long int numGcd) {
  long long int result = numA * numB / numGcd;
  return result;
}

int main() {
  long long int numA, numB;

  cin >> numA >> numB;
  if (numB > numA) {
    swap(numA, numB);
  }

  long long int numGcd = findGcd(numA, numB);
  long long int numLcd = findLcd(numA, numB, numGcd);
  cout << numLcd;
}