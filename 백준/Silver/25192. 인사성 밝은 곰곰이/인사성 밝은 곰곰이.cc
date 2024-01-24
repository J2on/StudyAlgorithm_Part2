#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  int num;
  cin >> num;
  set<string> nameSet;
  
  string str;
  int count = 0;
  for(int i =0; i< num; i++){
    cin >> str;

    if(str == "ENTER"){
      nameSet.clear();
    }
    else{
      if(nameSet.find(str) == nameSet.end()){
        nameSet.insert(str);
        count++;
      }
    }
  }
  cout << count;
}