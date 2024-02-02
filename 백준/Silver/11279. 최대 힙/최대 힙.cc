#include <iostream>
#include <queue>
using namespace std;


void process(int input, priority_queue<int>& pq) {
	int result;
	if (input == 0) {
		if (pq.empty()) {
			cout << 0 << '\n';
		}
		else {
			cout << pq.top() << '\n';
			pq.pop();
		}
	}
	else {
		pq.push(input);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<int> pq;

	int num;
	cin >> num;

	int input;
	for (int i = 0; i < num; i++) {
		cin >> input;
		process(input, pq);
	}
}