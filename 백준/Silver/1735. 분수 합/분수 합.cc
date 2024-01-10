#include <iostream>
using namespace std;

void swap(int &numA, int &numB) {
  int temp = numA;
  numA = numB;
  numB = temp;
}
int findGcd(int numA, int numB) {
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

void makeReducedFraction(long long int& numA, long long int& numB){
  int numGcd;
  while(1){
    numGcd = findGcd(numA, numB);
    if(numGcd == 1) break;

    numA /= numGcd;
    numB /= numGcd;
  }
}


int main() {
  int numA, numB, numC, numD;

  cin >> numA >> numB >> numC >> numD;

  long long int numChild, numParent;
  numChild = (numA * numD) + (numB * numC);
  numParent = numB * numD;
  
  makeReducedFraction(numChild, numParent);
  cout << numChild << ' ' << numParent;
  
}