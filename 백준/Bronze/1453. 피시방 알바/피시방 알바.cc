#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int num;

	scanf("%d", &num);
	vector<int> vec;
	int input;
	int result = 0;
	for (int i = 0; i < num; i++) {
		scanf("%d", &input);
		if (find(vec.begin(), vec.end(), input) == vec.end()) {
			vec.push_back(input);
		}
		else {
			result++;
		}
	}
	printf("%d", result);
}