#include <cstdio>
#include <string>
using namespace std;

int table[64][64];

void quadTree(int num, int y, int x){
	if (num == 1) {
		printf("%d", table[y][x]);
		return;
	}

	bool isWhite = false;
	bool isBlack = false;
	bool isClear = true;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (table[y + i][x + j] == 0) {
				isWhite = true;
			}
			else {
				isBlack = true;
			}
		}
	}

	if (isWhite && isBlack) {
		isClear = false;
	}

	
	if (!isClear) {
		printf("%c", '(');
		quadTree(num / 2, y, x);
		quadTree(num / 2, y, x + num / 2);
		quadTree(num / 2, y + num / 2, x);
		quadTree(num / 2, y + num / 2, x + num / 2);
		printf("%c", ')');
	}
	else if (isWhite && !isBlack) {
		printf("%d",0);
	}
	else if (isBlack && !isWhite) {
		printf("%d", 1);
	}
	
}


int main() {
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			scanf("%1d", &table[i][j]);
		}
	}
	quadTree(num, 0, 0);
}