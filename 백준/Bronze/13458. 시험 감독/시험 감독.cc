#include <iostream>
#include <vector>
using namespace std;

int main() {
	
	int n, b, c;

	vector<int> as;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		as.push_back(a);
	}
	cin >> b >> c;

	long long count = n; // 일단 응시장 만큼은 필요

	for (auto& a : as)
	{
		a -= b;
		if (a <= 0) {
			continue;
		}

		count += a / c;
		if (a % c > 0) count++; // 딱 나누어 떨어지지 않은 경우
	}

	cout << count;
}