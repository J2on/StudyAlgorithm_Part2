#include <iostream>
#include <queue>
using namespace std;

int main() {
    int InputNum;
    cin >> InputNum;

    priority_queue<int> pq;
    for (int i = 0; i < InputNum; i++) {
        int n;
        cin >> n;
        pq.push(-n);
    }
    
    if (InputNum == 1) {
        cout << 0;
        return 0;
    }

    long long result = 0;
    int arg1, arg2;
    while (1) {
        arg1 = -pq.top();
        pq.pop();
        arg2 = -pq.top();
        pq.pop();

        result += (arg1 + arg2);

        if (pq.empty()) {
            break;
        }
        pq.push(-(arg1 + arg2));
    }
    cout << result;
    return 0;
}