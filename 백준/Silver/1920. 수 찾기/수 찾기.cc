#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;
  vector<int> a;
  for(int i=0; i<n; i++)
  {
    int temp;
    cin >> temp;
    a.push_back(temp);
  }
  int m;
  cin >> m;
  sort(a.begin(), a.end());
  
  for(int i=0; i<m; i++)
  {
    int temp;
    cin >> temp;
    cout << binary_search(a.begin(), a.end(), temp) << '\n';
  }
  
}