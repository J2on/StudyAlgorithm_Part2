#include <iostream>
using namespace std;


int arr[300][2];

int main() {

	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {

		int temp;
		cin >> temp;
		arr[i][0] = temp;
		arr[i][1] = temp;

	}

	arr[1][0] += arr[0][0];

	for (int i = 2; i < num; i++) {
		arr[i][0] += arr[i - 1][1];
		arr[i][1] += max(arr[i - 2][0], arr[i - 2][1]);
	}
	cout << max(arr[num-1][0],arr[num-1][1]) << endl;
}