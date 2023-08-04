#include <iostream>
#include <vector>
#include <algorithm>>
using namespace std;

int main(){
  string str;
  vector<string> subStrVec;
  cin >> str;
  for(int i=1; i<= str.size(); i++){
    for(int j=0; j <= str.size() - i; j++){
      subStrVec.push_back(str.substr(j,i));
    }
  }

  sort(subStrVec.begin(), subStrVec.end());
  subStrVec.erase(unique(subStrVec.begin(), subStrVec.end()), subStrVec.end());

  cout << subStrVec.size();
}