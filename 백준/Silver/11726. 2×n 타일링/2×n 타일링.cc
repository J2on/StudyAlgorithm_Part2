#include <iostream>
#include <vector>
using namespace std;

// n이 홀수가 되면 양쪽 끝에 하나를 더 하는거니까 


// 2X2 사각형에서는 두가지 경우의 수
// 2

// 2X3 
// 3

// 2X4
// 5

// 2X5
// 8

// 2X6
// 13 21 34 55


int table[1001];

int main() {
	
	table[0] = 0;
	table[1] = 1;
	table[2] = 2;

	for (int i = 3; i < 1001; i++)
	{
		table[i] = (table[i - 1] + table[i - 2]) % 10007;
	}

	int n;
	cin >> n;
	cout << table[n];
}