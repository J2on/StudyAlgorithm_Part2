#include <iostream>
#include <vector>
using namespace std;


// 0 시작, 0 -> 1 -> 2 ->


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
	int milk[3] = { 0, 1, 2 };
	for (auto& a : markets)
	{
		if (cnt % 3 == a)
		{
			cnt++;
		}
		else
		{
			/*if (cnt > max)
			{
				max = cnt;
			}

			cnt = 0;
			if (a == 0) {
				cnt = 1;
			}*/
		}

		
	}

	if (cnt > max)
	{
		max = cnt;
	}

	cout << max;
}