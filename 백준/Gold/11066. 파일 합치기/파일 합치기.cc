#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define INF 1000000000


int sum[501], dp[501][501];

int main()
{
	int numT, numK;
	cin >> numT;

	for(int i = 0; i < numT; i++)
	{
		cin >> numK;
		for (int i = 1; i <= numK; i++)
		{
			int temp;
			cin >> temp;
			sum[i] = sum[i - 1] + temp;
		}

		for (int i = 1; i <= numK; i++)
		{
			for (int j = 1; j <= numK - i; j++)
			{
				dp[j][i + j] = INF;
				for (int k = j; k < i + j; k++)
				{
					dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + sum[i + j] - sum[j - 1]);
				}
			}
		}


		

		cout << dp[1][numK] << endl;

	}

}