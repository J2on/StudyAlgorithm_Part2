#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int dp[1001][1001];

int main() {

	string str1, str2;
	cin >> str1 >> str2;

	for (int i = 1; i < str1.length()+1; i++) {
		for (int j = 1; j < str2.length()+1; j++) {
			
			if (str1[i-1] == str2[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	
	cout << dp[str1.size()][str2.size()];
}