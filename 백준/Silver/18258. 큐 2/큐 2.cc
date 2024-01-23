#include <iostream>
#include <string>
using namespace std;

struct myQueue {
  int* list = new int[2000001];
  int head = 0;
  int last = 0;
};

bool empty(myQueue &q) {
  if (q.head == q.last) {
    return true;
  } else {
    return false;
  }
}

void push(myQueue &q, int num) {
  q.list[q.last] = num;
  q.last++;
}

int pop(myQueue &q) {
  if (q.last == q.head) {
    return -1;
  }

  int result = q.list[q.head];
  q.head++;

  return result;
}

int size(myQueue &q) {
  return q.last - q.head; 
}

int front(myQueue &q) {
  if (empty(q)) {
    return -1;
  }

  return q.list[q.head];
}

int back(myQueue &q) {
  if (empty(q)) {
    return -1;
  }

  return q.list[q.last - 1];
}

void task(myQueue &q, string str) {
  if (str == "push") {
    int num;
    cin >> num;
    push(q, num);
  } 
  else if (str == "pop") {
    cout << pop(q) << '\n';
  } 
  else if (str == "size") {
    cout << size(q) << '\n';
  } 
  else if (str == "empty") {
    cout << empty(q) << '\n';
  } 
  else if (str == "front") {
    cout << front(q) << '\n';
  } 
  else if (str == "back") {
    cout << back(q) << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int num;
  cin >> num;

  myQueue q;

  for (int i = 0; i < num; i++) {
    string input;
    cin >> input;

    task(q, input);
  }
  delete[] q.list;
}