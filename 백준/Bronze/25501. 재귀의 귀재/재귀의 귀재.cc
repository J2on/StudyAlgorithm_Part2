#include <iostream>
#include <string>
using namespace std;

int count;

int recursion(string& s, int l, int r){
    count++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(string& s){
    count = 0;
    return recursion(s, 0, s.size()-1);
}

int main() {
  int num;
  cin >> num;
  string str;

  for(int i=0; i<num; i++){
    cin >> str;
    cout << isPalindrome(str) << ' ' << count << '\n';
  }
}