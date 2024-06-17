#include <iostream>
using namespace std;

int val[10];

int main()
{
	int n, k;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> val[i];
	}

	int cnt = 0;
	for (int i = n-1; i >= 0; i--)
	{
		int mod = k / val[i];
		
		if (mod != 0)
		{
			k %= val[i];
			cnt += mod;
		}
		
	}

	cout << cnt;
}