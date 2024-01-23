#include <iostream>
#include <queue>
using namespace std;

int cardProcess(int num){
  queue<int> q;

  for(int i=1; i<=num; i++){
    q.push(i);
  }

  while(q.size() != 1){
    q.pop();
    q.push(q.front());
    q.pop();
  }

  return q.front();
}

int main() {
  int num;
  cin >> num;
  cout << cardProcess(num);
}