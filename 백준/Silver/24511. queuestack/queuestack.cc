#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n;
  cin >> n;

  // data structure의 종류 확인
  int dsList[n];
  stack<int> st;
  for(int i=0; i<n; i++){
    cin >> dsList[i];  
  }
  // Queue인 경우에만 stack에 쌓는다. 
  // Stack인 경우엔 바뀌지 않으니 
  int temp;
  for(int i:dsList){
    cin >> temp;
    if(i==0){
      st.push(temp);
    }
  }
  // 뒤에 입력될 수를 queue에 담는다.
  queue<int> q;
  int m;
  cin >> m;
  for(int i=0; i<m; i++){
    cin >> temp;
    q.push(temp);
  }
  // stack에 있는 수 먼저 출력
  while(!st.empty() && m != 0){
    cout << st.top() << ' ';
    st.pop();
    m--;
  }
  // 모자르다면 q에 있는 수도 출력
  if(m != 0){
    for(int i=0; i<m; i++){
      cout << q.front() << ' ';
      q.pop();
    }
  }
}