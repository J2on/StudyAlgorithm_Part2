#include <iostream>
using namespace std;

// 3
// 010 011 100 101
// 4
// 0101 0110 1001 1010
// 5
// 01010 01011 01101 01100 10010 10011 10101 10100

int dp[100001];

int main(){
  int n;
  cin >> n;

  dp[1] = 2;
  
  for(int i=2; i<n+1; i++)
  {
    if(i % 2 == 0) { // 짝수인 경우 
      dp[i] = dp[i-1];
    }
    else{ // 홀수인 경우
      dp[i] = (dp[i-1] * 2) % 16769023;
    }
  }

  cout << dp[n];
}