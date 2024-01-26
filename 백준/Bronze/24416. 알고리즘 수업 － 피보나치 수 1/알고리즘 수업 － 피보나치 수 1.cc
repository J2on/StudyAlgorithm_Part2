#include <iostream>
#include <vector>
using namespace std;


int code1 = 0;

int code2 = 0;

int fib(int n) {
	if (n == 1 || n == 2) {
		code1++;
		return 1; 
	}
	else {
		return fib(n - 1) + fib(n - 2);
	}
}

int fibonacci(int n) {

	vector<int> vec;
	vec.push_back(1);
	vec.push_back(1);

	for (int i = 2; i < n; i++) {
		vec.push_back(vec[i - 1] + vec[i - 2]);
		code2++;
	}
	return vec[n - 1];
}

int main() {
	int num;
	cin >> num;

	fib(num);
	fibonacci(num);

	cout << code1 << ' ' << code2;
}