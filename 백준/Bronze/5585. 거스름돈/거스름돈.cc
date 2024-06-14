#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;

void calc(int& n, int m)
{
	if (n >= m)
	{
		cnt += n / m;
		n %= m;
	}
}

int main() {
	
	int n;
	cin >> n;

	n = 1000 - n;

	int moneys[6] = { 500, 100, 50, 10, 5, 1 };
	for (auto& m : moneys)
	{
		calc(n, m);
	}
	
	cout << cnt;
}