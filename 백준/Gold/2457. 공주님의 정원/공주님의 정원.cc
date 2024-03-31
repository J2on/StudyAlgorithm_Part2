#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {

	int Num;
	cin >> Num;

	priority_queue<vector<int>> TimeTable;
	for (int i = 0; i < Num; i++)
	{
		vector<int> Vec(2); //[끝난 시간, 시작 시간]
		int MonthA, DayA, MonthB, DayB;
		cin >> MonthA >> DayA >> MonthB >> DayB;

		Vec[0] = MonthB * 100 + DayB;
		Vec[1] = MonthA * 100 + DayA;
		TimeTable.push(Vec);
	}
	
	vector<int> NextDay = {1231, 1201};
	int LastDay = 1201;
	int result = 0;

	while (1) {
		if (TimeTable.top()[0] >= LastDay && NextDay[1] > TimeTable.top()[1]) {
			NextDay = TimeTable.top();
			TimeTable.pop();
		}
		else if (NextDay[1] <= TimeTable.top()[1]) {
			TimeTable.pop();
		}

		else {
			LastDay = NextDay[1];
			if (LastDay > TimeTable.top()[0]) {// 연결이 안되는 경우
				result = 0;
				break;
			}
			result++;

			if (LastDay <= 301) {
				break;
			}
		}

		if (TimeTable.empty()) {
			if (NextDay[1] <= 301 ) {
				result++;
			}
			break;
		}
	}
	

	cout << result << endl;
	
}