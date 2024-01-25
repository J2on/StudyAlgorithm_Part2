#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calc(int num1, int num2, const int& opr) {
	// 0 (덧셈) , 1 (뺄셈), 2(곱셈), 3(나눗셈) 
	switch (opr)
	{
	case 0:
		return num1 + num2;
		break;
	case 1 :
		return num1 - num2;
		break;
	case 2:
		return num1 * num2;
		break;
	case 3:
		if (num1 < 0) {
			num1 *= -1;
			return (num1 / num2) * -1;
		}
		else {
			return num1 / num2;
		}
	}
}


int main() {
	int num;
	cin >> num;

	int* numList = new int[num];
	for (int i = 0; i < num; i++) {
		cin >> numList[i];
	}


	vector<int> oprVec;
	for (int i = 0; i < 4; i++) {
		int n;
		cin >> n;
		for (int k = 0; k < n; k++) {
			oprVec.push_back(i);
		}
	}

	int min = 2000000000;
	int	max = -2000000000;
	int result;
	do {
		// 전부 계산 해보기	
		result = numList[0];
		for (int i = 0; i < num-1; i++) {
			result = calc(result, numList[i+1], oprVec[i]);
		}

		if (result > max) {
			max = result;
		}

		if (result < min) {
			min = result;
		}

	} while (next_permutation(oprVec.begin(), oprVec.end()));


	cout << max << '\n' << min;

	delete[] numList;
}