#include <iostream>
using namespace std;

class myDeck {
private:
  int list[2000002];
  int head = 1000001;
  int last = 1000001;

public:
  void pushFront(int num) {
    head--;
    list[head] = num;
  }

  void pushBack(int num) {
    list[last] = num;
    last++;
  }

  int popFront() {
    if (empty())
      return -1;

    int result = list[head];
    head++;
    return result;
  }

  int popBack() {
    if (empty())
      return -1;

    int result = list[last - 1];
    last--;
    return result;
  }

  int size() { return last - head; }

  bool empty() {
    if (head == last) {
      return true;
    } else {
      return false;
    }
  }

  int front() {
    if (empty())
      return -1;

    return list[head];
  }

  int back() {
    if (empty())
      return -1;

    return list[last - 1];
  }
};

void deckAction(myDeck &d, int input) {

  switch (input) {
  int temp;
  case 1:
    cin >> temp;
    d.pushFront(temp);
    break;
  case 2:
    cin >> temp;
    d.pushBack(temp);
    break;
  case 3:
    cout << d.popFront() << '\n';
    break;
  case 4:
    cout << d.popBack() << '\n';
    break;
  case 5:
    cout << d.size() << '\n';
    break;
  case 6:
    cout << d.empty() << '\n';
    break;
  case 7:
    cout << d.front() << '\n';
    break;
  case 8:
    cout << d.back() << '\n';
    break;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  myDeck d;
  
  int input;
  for (int i = 0; i < n; i++) {
    cin >> input;
    deckAction(d, input);
  }
}