#include <iostream>
using namespace std;

int wTable[21][21][21];

void fillTable() {
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			for (int k = 0; k < 21; k++) {
				if (i == 0 || j == 0 || k == 0) {
					wTable[i][j][k] = 1;
				}
				else if (i < j && j < k) {
					wTable[i][j][k] = wTable[i][j][k - 1] + wTable[i][j - 1][k - 1] - wTable[i][j - 1][k];
				}
				else {
					wTable[i][j][k] = wTable[i - 1][j][k] + wTable[i - 1][j - 1][k] + wTable[i - 1][j][k - 1] - wTable[i - 1][j - 1][k - 1];
				}
			}
		}
	}
}

int main() {

	fillTable();

	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) {
			break;
		}
		cout << "w(" << a << ", " << b << ", " << c << ") = ";
		
		if (a <= 0 || b <= 0 || c <= 0) {
			a = 0;
			b = 0;
			c = 0;
		}
		else if (a > 20 || b > 20 || c > 20) {
			a = 20;
			b = 20;
			c = 20;
		}
		

		cout <<  wTable[a][b][c] << '\n';
	}
}