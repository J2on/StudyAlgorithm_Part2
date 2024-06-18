#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int arr[2001];

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> ss;
	for(int i =0; i < n; i++)
	{
		int temp;
		vector<int> s;
		
		cin >> temp;
		for(int j =0; j < temp; j++){
			
			int temp2;
			cin >> temp2;
			s.push_back(temp2);
			arr[temp2]++;
		}
		ss.push_back(s);
	}

	
	for(auto& a : ss)
	{
		bool isPrime = false;
		for(int i=0; i< a.size(); i++)
		{
			if(arr[a[i]] - 1 == 0){
				
				isPrime = true;
			}
		}
		
		if(!isPrime)
		{
			cout << 1;
			return 0;
		}
	}
	cout << 0;
}