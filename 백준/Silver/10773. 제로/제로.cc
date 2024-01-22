#include <iostream>
using namespace std;

struct myStack {
  int itemNum = -1;
  int item[1000000];
  int sum = 0;
};

void stackSum(myStack &s1, int input) {
  s1.itemNum++;
  s1.item[s1.itemNum] = input;
  s1.sum += input;
}

void stackZero(myStack &s1) {
  s1.sum -= s1.item[s1.itemNum];
  s1.itemNum--;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  myStack s1;

  int num;
  cin >> num;

  int input;
  for (int i = 0; i < num; i++) {
    cin >> input;
    if(input == 0){
      stackZero(s1);
    }
    else{
      stackSum(s1, input);
    }
  }

  cout << s1.sum;
}