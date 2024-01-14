#include <iostream>
using namespace std;

void swap(int &numA, int &numB) {
  int temp = numA;
  numA = numB;
  numB = temp;
}

int makeGcd(int numA, int numB) {
  if (numB > numA)
    swap(numA, numB);

  int numC;
  while (1) {
    numC = numA % numB;
    if (numC == 0) {
      break;
    } else {
      numA = numB;
      numB = numC;
    }
  }

  return numB;
}

int main() {
  int numTree;
  cin >> numTree;

  int distanceList[numTree - 1];

  int distance = 999999999;

  // 지난 위치
  int lastLocation;

  // 현재 위치
  int nowLocation;

  // 초기값 설정
  cin >> lastLocation;
  cin >> nowLocation;
  distance = nowLocation - lastLocation;
  distanceList[0] = 0;
  distanceList[1] = distance;
  lastLocation = nowLocation;

  for (int i = 2; i < numTree; i++) {
    cin >> nowLocation;
    
    distanceList[i] = nowLocation - lastLocation;

    distance = makeGcd(distance, distanceList[i]);

    lastLocation = nowLocation;
  }


  int temp;
  int result = 0;
  for (int i = 1; i < numTree; i++) {
    temp = distanceList[i] / distance;
    //cout << distanceList[i] << distance << temp << endl;
    if (temp != 1) {
      result += (temp - 1);
    }
  }

  cout << result;
}