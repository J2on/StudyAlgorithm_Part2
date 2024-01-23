#include <deque>
#include <iostream>
using namespace std;

void teskDq(int *textList, deque<int> &dq) {
  int target = 1;
  dq.pop_front();
  cout << target << ' ';
  
  int text;
  while(!dq.empty()){
    text = textList[target];
    if(text > 0){
      for(int i=1; i < text; i++){
        dq.push_back(dq.front());
        dq.pop_front();
      }
      target = dq.front();
      dq.pop_front();
    }
    else{
      text *= -1;
      for(int i=1; i < text; i++){
        dq.push_front(dq.back());
        dq.pop_back();
      }
      target = dq.back();
      dq.pop_back();
    }
    cout << target << ' ';
  }
  
}

int main() {
  deque<int> dq;

  int num;
  cin >> num;
  int *textList = new int[num+1];

  for (int i = 1; i <= num; i++) {
    int text;
    cin >> text;
    textList[i] = text;

    dq.push_back(i);
  }
  teskDq(textList, dq);
  delete[] textList;
}