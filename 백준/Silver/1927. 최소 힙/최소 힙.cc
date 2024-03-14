#include <iostream>
#include <queue>
using namespace std;

int main(){
  cin.tie(NULL); //입출력 묶음 해제
  ios_base::sync_with_stdio(false);
  int input;
  cin >> input;

  priority_queue<int> pq;
  int num;
  for(int i=0; i<input; i++){
    cin >> num;
    if(num == 0){
      if(pq.size() == 0){
        cout << 0 <<'\n';
      }
      else{
        cout << -pq.top() << '\n';
        pq.pop();
      }
    }
    else{
      pq.push(-num);
    }
  }
}