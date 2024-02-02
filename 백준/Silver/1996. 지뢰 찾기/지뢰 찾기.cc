#include <iostream>
using namespace std;

int map[1002][1002];
int mine[1002][1002];


void fillMap(int y, int x) {
	if (mine[y][x] != 0) {
		map[y][x] = -1;
		return;
	}

	int val = 0;
	for (int i = y - 1; i <= y + 1; i++) {
		for (int j = x - 1; j <= x+1; j++) {
			val += mine[i][j];
		}
	}
	
	map[y][x] = val;
}

int main() {
	int num;
	cin >> num;

	char c;
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			cin >> c;
			if(c == '.') {
				mine[i][j] = 0;
			}
			else {
				mine[i][j] = int(c) - 48;
			}

		}
	}

	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			fillMap(i, j);
			int result = map[i][j];

			
			if (result >= 10) {
				cout << 'M';
			}
			else if (result == -1) {
				cout << '*';
			}
			else {
				cout << result;
			}
			
		}
		cout << endl;
	}
}