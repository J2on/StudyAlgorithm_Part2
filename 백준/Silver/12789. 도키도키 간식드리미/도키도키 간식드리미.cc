#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(stack<int> st1) {
  stack<int> st2;

  int currentNum = 1;
  while (!st1.empty()) {
    if (st1.top() == currentNum) {
      st1.pop();
      currentNum++;
    } 
    else if (!st2.empty() && st2.top() == currentNum) {
      st2.pop();
      currentNum++;
    } 
    else {
      st2.push(st1.top());
      st1.pop();
    }
  }
  
  while(!st2.empty()){
    if(st2.top() == currentNum){
      st2.pop();
      currentNum++;
    }
    else{
      return false;
    }
  }
  
  return true;
}

void stackInversing(stack<int>& st){
  stack<int> temp;

  while(!st.empty()){
    temp.push(st.top());
    st.pop();
  }

  st.swap(temp);
}

int main() {
  int num;
  cin >> num;

  stack<int> st;

  for (int i = 0; i < num; i++) {
    int input;
    cin >> input;
    st.push(input);
  }

  stackInversing(st);
  
  if(isValid(st)){
    cout << "Nice" << '\n';
  }
  else{
    cout << "Sad" << '\n';
  }
}