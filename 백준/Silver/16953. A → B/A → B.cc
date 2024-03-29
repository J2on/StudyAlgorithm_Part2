#include <iostream>
using namespace std;

int main() {
	int NumA, NumB;
	cin >> NumA >> NumB;

	int result = 1;
	while (1) {
		if (NumB % 10 == 1) {
			NumB /= 10;
		}
		else if (NumB % 2 == 0){
			NumB /= 2;
		}
		else {
			result = -1;
			break;
		}

		result++;

		if (NumB == NumA) {
			break;
		}
		else if(NumB < NumA) {
			result = -1;
			break;
		}
	}
	cout << result;
}