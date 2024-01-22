#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkString(const string &str) {
  stack<char> st;
  
  int round = 0;
  int square = 0;

  for (char ch : str) {
    if (ch == '(') {
      round++;
      st.push(ch);
    } 
    else if (ch == '[') {
      square++;
      st.push(ch);
    } 
    else if (ch == ')') {
      if (!st.empty() && st.top() == '(') {
        round--;
        st.pop();
      }
      else{
        return false;
      }
    } 
    else if (ch == ']') {
      if (!st.empty() && st.top() == '[') {
        square--;
        st.pop();
      } 
      else{
        return false;
      }
    } 
  }
  if (round == 0 && square == 0) {
    return true;
  } else {
    return false;
  }
}

int main() {
  string input;
  while(1){
    getline(cin, input);

    if(input == "."){ break; }
    
    if (checkString(input)) {
      cout << "yes" << '\n';
    } else {
      cout << "no" << '\n';
    }
  }
}