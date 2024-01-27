#include <iostream>
using namespace std;


int arr[100000];
int val[100000];

int main() {

	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}

	val[0] = arr[0];
	int maxVal = val[0];
	for (int i = 1; i < num; i++) {
		val[i] = max(val[i-1] + arr[i], arr[i]);
		if (val[i] > maxVal) {
			maxVal = val[i];
		}
	}

	cout << maxVal;
}