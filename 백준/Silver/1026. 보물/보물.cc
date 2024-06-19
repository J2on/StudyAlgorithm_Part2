#include <queue>
#include <iostream>
using namespace std;
int main() {
	priority_queue<int> pqA;
	priority_queue<int> pqB;
	
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int temp;
		cin >> temp;
		pqA.push(-temp);
	}
	for(int i=0; i<n; i++)
	{
		int temp;
		cin >> temp;
		pqB.push(temp);
	}
	
	int result = 0;
	for(int i=0; i<n; i++)
	{
		result -= pqA.top() * pqB.top();
		pqA.pop();
		pqB.pop();
	}
	
	cout << result;
}