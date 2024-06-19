#include <queue>
#include <iostream>
using namespace std;
int main() {
	priority_queue<int> pq;
	
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int temp;
		cin >> temp;
		pq.push(-temp);
	}
	
	int time = 0; // 지난 시간
	int result = 0;
	while(!pq.empty())
	{
		time += -pq.top();
		result += time;
		pq.pop();
	}
	cout << result;
}