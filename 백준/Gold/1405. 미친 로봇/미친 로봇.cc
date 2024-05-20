#include <iostream>
#include <iomanip>
using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

double result = 0;
int visited[30][30];
double percent[4];

void dfs(int x, int y, int index, int n, double totalPercent) 
{
	if (index == n)
	{
		result += totalPercent;
		return;
	}

	visited[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int newX = x + dx[i];
		int newY = y + dy[i];

		if (newX >= 0 && newY >= 0 && newX < 30 && newY < 30) // 범위를 벗어나지 않는지
		{
			if (visited[newX][newY] == false) {
				visited[newX][newY] = true;
				dfs(newX, newY, index + 1, n, totalPercent * percent[i]);
				visited[newX][newY] = false;
			}
		}
	}
}

int main() 
{
	int n;
	cin >> n;

	for (int i = 0; i < 4; i++) {
		int temp;
		cin >> temp;
		percent[i] = temp * 0.01;
	}

	dfs(15, 15, 0, n, 1);
	cout << setprecision(16);
	cout << result;
}