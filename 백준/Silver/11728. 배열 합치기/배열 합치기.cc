
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, m;
	
	cin >> n >> m;
	vector<int> vec;
	for(int i =0; i < n + m; i++)
	{
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end());
	
	for(int i =0; i < n + m; i++)
	{
		cout << vec[i] << ' ';
	}
}
