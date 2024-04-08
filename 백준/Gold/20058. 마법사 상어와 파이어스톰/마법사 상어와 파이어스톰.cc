#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int n, q;
int TableSize;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void DivideAndRotate(int& _y, int& _x, int& size, vector<vector<int>>& Table) {
	vector<vector<int>> TempTable(size, vector<int>(size));

	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			TempTable[x][size - 1 - y] = Table[_y + y][_x + x];
		}
	}

	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			Table[_y + y][_x + x] = TempTable[y][x];
		}
	}

}

void Rotate(int& l, vector<vector<int>>& Table) {
	int size = pow(2, l);
	//cout << endl << size << endl;

	for (int y = 0; y < TableSize; y += size) {
		for (int x = 0; x < TableSize; x += size) {
			DivideAndRotate(y, x, size, Table);
		}
	}
}


void IceCheck(vector<vector<int>>& Table) {
	queue<pair<int,int>> q;
	for (int y = 0; y < TableSize; y++) {
		for (int x = 0; x < TableSize; x++) {
			// Ice Count
			int count = 0;
			// -1,0 / 0,-1 / 0,1 / 1,0
			if (x - 1 >= 0 && Table[y][x - 1] > 0) {
				count++;
			}
			if (y - 1 >= 0 && Table[y - 1][x] > 0) {
				count++;
			}
			if (x + 1 < TableSize && Table[y][x + 1] > 0) {
				count++;
			}
			if (y + 1 < TableSize && Table[y + 1][x] > 0) {
				count++;
			}

			// 인접에 3개 미만이고, 0이 아닐 때 
			// 지금 빼면 나중에 계산에 영향을 줄 수 있으니 이번 턴에 빼질 값들을 다 모아두고 한번에 빼줌
			if (count < 3 && Table[y][x] > 0) {
				q.push(make_pair(y, x));
			}
		}
	}

	while (!q.empty()) {
		pair<int, int> p = q.front();
		Table[p.first][p.second] -= 1;
		q.pop();
	}
}

int SumIce(vector<vector<int>>& Table) {
	int sum = 0;

	for (auto& y : Table) {
		for (auto& x : y) {
			sum += x;
		}
	}

	return sum;
}


int dfs(int y, int x, vector<vector<bool>>& Visit, vector<vector<int>>& Table) {
	Visit[y][x] = true;
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int newX = x + dx[i];
		int newY = y + dy[i];

		if (newX < 0 || newX >= TableSize || newY < 0 || newY >= TableSize) continue;
		if (Visit[newY][newX] || Table[newY][newX] == 0) continue;
		ret += dfs(newY, newX, Visit, Table);
	}
	return ret;
}

int main() {
	
	cin >> n >> q;
	TableSize = pow(2, n);

	vector<vector<int>> Table(TableSize,vector<int>(TableSize));

	for (int i = 0; i < TableSize; i++) {
		for (int j = 0; j < TableSize; j++) {
			cin >> Table[i][j];
		}
	}

	for (int i = 0; i < q; i++) {
		int l;
		cin >> l;
		Rotate(l, Table);
		IceCheck(Table);
	}

	// 얼음 총합
	int sum = SumIce(Table);
	
	// MaxIce 뭉텅이
	vector<vector<bool>> VisitTable(TableSize, vector<bool>(TableSize, false));
	int MaxIce = 0;
	for (int y = 0; y < TableSize; y++) {
		for (int x = 0; x < TableSize; x++) {
			if (Table[y][x] > 0 && !VisitTable[y][x]) {
				MaxIce = max(MaxIce, dfs(y, x, VisitTable, Table));
			}
				
		}
	}

	//  result
	cout << sum << '\n' << MaxIce;

}