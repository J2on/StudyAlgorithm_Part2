#include <iostream>
using namespace std;

int main() {

	int num;
	cin >> num;

	int input[1000];
	for (int i = 0; i < num; i++) {
		cin >> input[i];
	}

	// 각 위치를 마지막으로 하는 수열의 크기를 저장
	int val[1000] = { 0, };
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < i; j++) {
			if (input[j] < input[i]) { // 
				if (val[i] <= val[j]) {	 // 더 큰 수열을 발견했을때만
					val[i] = val[j] + 1;
				}
				
			}
		}

		if (val[i] == 0) {
			val[i] = 1;
		}
	}

	int max = val[0];
	for (int n: val) {
		if (n > max) {
			max = n;
		}
	}

	cout << max;
}