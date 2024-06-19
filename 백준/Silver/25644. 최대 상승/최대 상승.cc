#include <iostream>
using namespace std;

int price[200001];
int table[200001];

int main(){
  int n;
  cin >> n;

  for(int i=0; i<n; i++)
  {
    cin >> price[i];
  }

  int min = price[0];
  for(int i=0; i<n; i++)
  {
    if(price[i] < min){
      min = price[i];
    }

    table[i] = max(price[i] - min, table[i-1]);
  }

  cout << table[n-1];
}