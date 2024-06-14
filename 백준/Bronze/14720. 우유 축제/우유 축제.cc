#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> markets;

	int market;
	for (int i = 0; i < n; i++)
	{
		cin >> market;
		markets.push_back(market);
	}
	
	int max = 0;
	int cnt = 0;
	for (auto& a : markets)
	{
		if (cnt % 3 == a)
		{
			cnt++;
		}
	}

	cout << cnt;
}