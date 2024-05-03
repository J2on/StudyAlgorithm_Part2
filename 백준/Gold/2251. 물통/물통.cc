#include <iostream>
#include <set>
#include <algorithm>>

using namespace std;

int numA, numB, numC;
int visited[201][201][201];
set<int> Result;

void BottleProcess(int a, int b, int c)
{
  if(visited[a][b][c]) return;
  // 방문 했다는 표시
  visited[a][b][c] = 1;

  if(a == 0 && Result.find(c) == Result.end())
  {
    Result.insert(c);
  }

  BottleProcess(max(0, a + b - numB), min(a + b, numB), c); // a->b
  BottleProcess(max(0, a + c - numC), b, min(a + c, numC)); // a->c
  
  BottleProcess(min(a + b, numA), max(0, b + a - numA), c); // b->a
  BottleProcess(a, max(0, b + c - numC), min(b + c, numC)); // b->c
  
  BottleProcess(min(a + c, numA), b, max(0, c + a - numA)); // c->a
  BottleProcess(a, min(c + b, numB), max(0, c + b - numB)); // c->b
}

int main()
{
  
  cin >> numA >> numB >> numC;
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  BottleProcess(0,0,numC);
  for(auto& a : Result)
  {
    cout << a << ' ';
  }
}  