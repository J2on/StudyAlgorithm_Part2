#include <iostream>
using namespace std;

int sum[1000][3];

int main() {

	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 3; j++) {
			int temp;
			cin >> temp;
			sum[i][j] = temp;
		}
	}

	// 뒤에서 부터 채워가는 방식
	for (int i = num - 2; i >= 0; i--) {
		for (int j = 0; j < 3; j++) {
			if (sum[i + 1][(j + 1) % 3] > sum[i + 1][(j + 2) % 3]) {
				sum[i][j] += sum[i+1][(j + 2) % 3];
			}
			else {
				sum[i][j] += sum[i + 1][(j + 1) % 3];
			}
		}
	}

	int min = sum[0][0];
	for (int i = 1; i < 3; i++) {
		if (sum[0][i] < min) {
			min = sum[0][i];
		}
	}

	cout << min;
}