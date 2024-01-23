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
  
  int dsList[n];
  stack<int> st;
  for(int i=0; i<n; i++){
    cin >> dsList[i];  
  }

  int temp;
  for(int i:dsList){
    cin >> temp;
    if(i==0){
      st.push(temp);
    }
  }

  queue<int> q;
  int m;
  cin >> m;
  for(int i=0; i<m; i++){
    cin >> temp;
    q.push(temp);
  }

  while(!st.empty() && m != 0){
    cout << st.top() << ' ';
    st.pop();
    m--;
  }

  if(m != 0){
    for(int i=0; i<m; i++){
      cout << q.front() << ' ';
      q.pop();
    }
  }
}