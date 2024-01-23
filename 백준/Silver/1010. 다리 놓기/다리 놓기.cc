#include <iostream>
using namespace std;

int main(){
  int t;
  cin >> t;

  int n, m;
  for(int i=0; i<t; i++){
    cin >> n >> m;

    if(n > (m/2)){
      n = (m-n);
    }
    
    int temp = n;
    long long int result = 1;
    long long int div = 1;
    for(int j=0; j<temp; j++){
      result *= m;
      div *= n;
      m -= 1;
      n -= 1;
    }
    cout << result / div << '\n';
  }
}