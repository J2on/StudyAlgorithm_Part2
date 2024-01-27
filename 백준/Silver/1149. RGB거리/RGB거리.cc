#include <iostream>
using namespace std;


int price[1000][3];
int sum[1000][3];

int main() {

	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 3; j++) {
			int temp;
			cin >> temp;
			price[i][j] = temp;
			sum[i][j] = temp;
		}
	}

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