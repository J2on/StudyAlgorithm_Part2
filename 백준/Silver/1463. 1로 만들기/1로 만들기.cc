#include <iostream>
using namespace std;


int arr[1000001];

void fillTable(int num) {
	arr[0] = 2000000000;
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;

	int op1, op2, op3;
	int min;
	for (int i = 4; i < num+1; i++) {
		op1 = 0;
		op2 = 0;
		op3 = i - 1;
		if (i % 2 == 0) {
			op1 = i / 2;
		}

		if (i % 3 == 0) {
			op2 = i / 3;
		}

		min = arr[op1];
		if (arr[op2] < min) {
			min = arr[op2];
		}
		if (arr[op3] < min) {
			min = arr[op3];
		}

		arr[i] = min + 1;
		//cout << arr[i] << endl;
	}
}

int main() {

	int num;
	cin >> num;

	fillTable(num);
	cout << arr[num];
}