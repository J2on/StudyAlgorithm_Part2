#include <iostream>
#include <string>
using namespace std;


int main()
{
	string str;

	cin >> str;

	int cnt0 = 0;
	int cnt1 = 0;

	char current = str[0];
	
	for (auto& a : str)
	{
		if (a == current)
		{
			continue;
		}

		if (a == '0') {
			cnt1++;
		}
		else if (a == '1')
		{
			cnt0++;
		}
		current = a;
	}

	if (current == '0')
	{
		cnt0++;
	}
	else
	{
		cnt1++;
	}


	cout << min(cnt0, cnt1);
}