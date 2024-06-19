#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

// upper_bound()

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> powVec;
	unordered_map<int, string> map; // index, Name
	for(int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		map[i] = str;
		
		int pow;
		cin >> pow;
		powVec.push_back(pow + 1);
	}
	
	for(int i = 0; i < m; i++)
	{
		int pow;
		cin >> pow;
		int idx = upper_bound(powVec.begin(), powVec.end(), pow) - powVec.begin();
		cout << map[idx] << '\n';
	}
}