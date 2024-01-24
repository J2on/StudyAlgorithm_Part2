#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int num;
  cin >> num;
  set<string> ccDanceList;
  ccDanceList.insert("ChongChong");

  bool isChance;
  int section;
  string name1, name2;
  for(int i=0; i< num; i++){
    isChance = false;
    cin >> name1 >> name2;

    if(ccDanceList.find(name1) != ccDanceList.end()){
      isChance = !isChance; 
      section = 1;
    }
    
    if(ccDanceList.find(name2) != ccDanceList.end()){
      isChance = !isChance;
      section = 2;
    }

    if(isChance){
      if(section == 1){
        ccDanceList.insert(name2);
      }
      else{
        ccDanceList.insert(name1);
      }
    }
  }
  cout << ccDanceList.size();

}