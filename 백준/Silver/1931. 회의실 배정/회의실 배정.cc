#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int main()
{
	int n;
	cin >> n;

	priority_queue<vector<int>> timeTables;
	
	for (int i = 0; i < n; i++)
	{
		int start, end;
	
		vector<int> timeTable;
		cin >> start >> end;
		
		// 끝나는 시간, 시작 시간
		timeTable.push_back(-end);
		timeTable.push_back(-start);

		timeTables.push(timeTable);
	}
	
	int cnt = 0;
	int lastTime = 0; // 마지막 끝난 시간
	while (!timeTables.empty())
	{
		if (-timeTables.top()[1] >= lastTime)
		{
			cnt++;
			lastTime = -timeTables.top()[0];
			timeTables.pop();
		}
		else {
			timeTables.pop();
		}
	}

	cout << cnt;
}