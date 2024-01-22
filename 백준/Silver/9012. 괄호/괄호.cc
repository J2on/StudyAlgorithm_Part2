#include <iostream>
#include <string>
using namespace std;

bool checkVPS(string str) {
  int stack = 0;

  for (char ch : str) {
    if (ch == '(')
      stack++;
    else if (')')
      stack--;
    // 중간에 -1이 된 경우는 무조건 false
    if (stack < 0)
      return false;
  }
  // 0일 때만 true
  if (stack == 0)
    return true;
  else
    return false;
}

int main() {
  int num;
  cin >> num;

  string input;
  for (int i = 0; i < num; i++) {
    cin >> input;
    if(checkVPS(input)){
      cout << "YES" << '\n';
    }
    else{
      cout << "NO" << '\n';
    }
  }
}