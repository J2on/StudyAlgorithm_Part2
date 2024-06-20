#include <iostream>

using namespace std;

//	5로 나누었을 때, 짝수개로 나머지가 남아야 한다.

int main() {
	
	int n;
	cin >> n;
	
	
	if(n == 1 || n ==3){
		cout << -1;
		return 0;
	}
	
	int result = n/5;
	int g = n%5;
	
	while(1){
		
		
		if(g % 2 == 0){
			result += g/2;
			break;
		}
		else{
			result -= 1;
			g += 5;
		}	
	}
	
	cout << result;
}