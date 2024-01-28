#include <iostream>
using namespace std;


int sum[500][500];

int main() {

	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < i+1; j++) {
			int temp;
			cin >> temp;
			sum[i][j] = temp;
		}
	}
	

	
	

	for (int i = num - 2; i >= 0; i--) {
		for (int j = 0; j < i+1; j++) {
			if (sum[i + 1][j] > sum[i + 1][j + 1]) {
				sum[i][j] += sum[i + 1][j];
			}
			else {
				sum[i][j] += sum[i + 1][j + 1];
			}
		}
	}

	cout << sum[0][0];
}