#include <queue>
#include <iostream>
using namespace std;

// 5
// 1 3 1
// 1 1 1 1 1
// 3 1 1

// 마지막에 2나 4로 짝수개가 남아야 sk가 이김
// 1 3 5 

int main() {
	int n;
	cin >> n;
	
	if(n % 2 == 1){
		cout << "SK";
	}
	else
	{
		cout << "CY";
	}
}