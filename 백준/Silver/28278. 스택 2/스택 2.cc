#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int itemNum = -1;
  int item[1000000];
  
  int num;
  cin >> num;

  int input;
  int result;
  for (int i = 0; i < num; i++) {
    cin >> input;
    int result = -2;
    switch (input) {
    case 1:
      int temp;
      cin >> temp;
      itemNum++;
      item[itemNum] = temp;
      break;

    case 2:
      if (itemNum == -1) {
        result = -1;
      } else {
        result = item[itemNum];
        itemNum = itemNum - 1;
      }
      break;

    case 3:
      result = itemNum + 1;
      break;

    case 4:
      if (itemNum == -1) {
        result = 1;
      } else {
        result = 0;
      }
      break;

    case 5:
      if (itemNum == -1) {
        result = -1;
      } else {
        result = item[itemNum];
      }
      break;
    }
    if(result != -2){
      cout << result << '\n';
    }
  }
}
