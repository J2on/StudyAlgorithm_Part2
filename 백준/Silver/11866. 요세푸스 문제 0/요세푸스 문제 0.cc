#include <iostream>
#include <queue>
using namespace std;


void josephus(int n, int k){
  queue<int> q;

  for(int i = 1; i <= n; i++){
    q.push(i);
  }
  
  while(q.size() != 1){
    for(int i =1; i<k; i++){
      q.push(q.front());
      q.pop();
    }
    cout << q.front() << ',' << ' ';
    q.pop();
  }
  cout << q.front();
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, k;
  cin >> n >> k;

  cout << '<';
  josephus(n, k);
  cout << '>';
}