#include <iostream>
using namespace std;

// (i-1을 마실 떄, i-2를 마실 때)
long long arr[10001][2];

int main() {

	int num;
	cin >> num;

	
	int temp;
	if (num == 1) {
		cin >> temp;
		cout << temp;
		return 0;
	}

	for (int i = 1; i < num + 1; i++) {
		cin >> temp;
		arr[i][0] = temp;
		arr[i][1] = temp;
	}
	
	long long maxValue = -1;

	long long lastMax;
	for (int i = 2; i < num + 1; i++) {


		if (arr[i][0] == 0) {
			temp = max(arr[i-1][0], arr[i-1][1]);
			arr[i][0] = temp;
			arr[i][1] = temp;
		}
		else {
			arr[i][0] += arr[i - 1][1];
			arr[i][1] += max(arr[i - 2][0], arr[i - 2][1]);
		}

		lastMax = max(arr[i - 1][0], arr[i - 1][1]);
		arr[i][0] = max(arr[i][0], lastMax);
		arr[i][1] = max(arr[i][1], lastMax);

		if (arr[i][0] > maxValue) {
			maxValue = arr[i][0];
		}

		if (arr[i][1] > maxValue) {
			maxValue = arr[i][1];
		}
		//cout << i << ' ' << arr[i][0] << ' ' << arr[i][1] << endl;
	}

	cout << maxValue;
}