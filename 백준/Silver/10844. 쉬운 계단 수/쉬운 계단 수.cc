#include <iostream>
using namespace std;

long long arr[100][10];

int main() {

	int num;
	cin >> num;

	arr[0][0] = 0;
	for (int i = 1; i < 10; i++) {
		arr[0][i] = 1;
	}

	for (int i = 1; i < num; i++) {
		for (int j = 0; j < 10; j++) {
			
			if (j == 0) {
				arr[i][j] = arr[i - 1][1];
			}
			else if (j == 9) {
				arr[i][j] = arr[i - 1][8];
			}
			else {
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j + 1];
			}

			arr[i][j] %= 1000000000;
		}
	}
	long long sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += arr[num - 1][i];
		sum %= 1000000000;
	}

	cout << sum;
}