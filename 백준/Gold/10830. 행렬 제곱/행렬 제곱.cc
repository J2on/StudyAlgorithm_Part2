#include <iostream>
#include <vector>
using namespace std;

long long A, B;

vector<vector<int>> mul(const vector<vector<int>>& matA, const vector<vector<int>>& matB)
{	
	vector<vector<int>> result(A, vector<int>(A));
	for (int i = 0; i < A; i++)
	{
		for (int j = 0; j < A; j++) // i, j는 위치 잡기
		{
			for (int k = 0; k < A; k++)
			{
				result[i][j] += (matA[i][k] * matB[k][j]) % 1000;
				//cout << '(' << i << ',' << k << " = " << A1[i][k] << ')' << '(' << k << ',' << j  << " = " << A2[k][j] << ')' << ' ';
			}
			result[i][j] %= 1000;
			//cout << A3[i][j] << ' ';
		}
		//cout << " \n";
	}
	return result;
}


vector<vector<int>> square(const vector<vector<int>>& matA, int numB) {
	vector<vector<int>> result(A, vector<int>(A));

	for (int i = 0; i < A; i++) result[i][i] = 1;
	if (numB == 0) {
		return result;
	}
	else if (numB == 1) {
		return matA;
	}
		
	if (numB % 2) {
		result = mul(matA, result);
	}
	return mul(result, square(mul(matA, matA), numB / 2));
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	cin >> A >> B;
	
	vector<vector<int>> matA(A, vector<int>(A));

	for (int i = 0; i < A; i++)
	{
		for (int j = 0; j < A; j++)
		{
			cin >> matA[i][j];
		}
	}

	vector<vector<int>> result(A, vector<int>(A));
	for (int i = 0; i < A; i++) result[i][i] = 1;
	
	while (B > 0)
	{
		if (B % 2 != 0)
		{
			result = mul(result, matA);
			B--;
		}
		
		matA = mul(matA, matA);
		B /= 2;
	}

	for (int i = 0; i < A; i++)
	{
		for (int j = 0; j < A; j++)
		{
			cout << result[i][j] << ' ';
		}
		cout << "\n";
	}


}
