#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool comp(pair<string, int> p1, pair<string, int> p2){
  // 단어의 출현 수
  if(p1.second != p2.second){
      return p1.second > p2.second;
  }
  
  // 단어 길이
  if(p1.first.size() != p2.first.size()){
      return p1.first.size() > p2.first.size();
  }
  
  // 사전 순
  if(p1.first != p2.first){
      return p1.first < p2.first;
  }

}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int numN, numM;
  cin >> numN >> numM;

  int top = 0;
  map<string, int> wordMap;
  string str;
  for(int i=0; i<numN; i++){
    cin >> str;
    if(str.size() < numM){
      continue;
    }
    
    auto address = wordMap.find(str);
    if(address == wordMap.end()){
      wordMap.insert({str, 1});
    }
    else{
      address->second++;
      if(address->second > top){
        top = address->second;
      }
    }
  }
  
  vector<pair<string,int>> vec;
  for(auto& a : wordMap){
    vec.push_back(a);
  }
  
  sort(vec.begin(), vec.end(), comp);
  
  for(auto& v : vec){
    cout << v.first << '\n';
  }
}