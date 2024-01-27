#include <iostream>
using namespace std;

void fillTable(long long*& arr){
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	for (int i = 4; i < 101; i++) {
		arr[i] = arr[i - 2] + arr[i - 3];
	}
}


int main() {

	int num;
	cin >> num;
	
	long long* arr = new long long[101];
	fillTable(arr);

	int numN;
	for (int i = 0; i < num; i++) {
		cin >> numN;
		if (numN < 4) {
			cout << 1 << '\n';
			continue;
		}
		
		cout << arr[numN] << '\n';
		
	}
	delete[] arr;
}