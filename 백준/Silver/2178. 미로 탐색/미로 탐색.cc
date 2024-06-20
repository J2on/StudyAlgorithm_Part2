#include <iostream>
#include <queue>
#include <map>
using namespace std;

int table[101][101];

int dx[4] = {-1, 1 , 0, 0};
int dy[4] = {0, 0 , -1, 1};


int main(){
  int n, m;
  cin >> n >> m;

  for(int i=1; i<=n; i++){
    for( int j = 1; j<=m; j++){
      char c;
      cin >> c;
      table[i][j] = atoi(&c);
    }
  }

  queue<pair<int,int>> q;
  pair<int, int> p = make_pair(1,1);
  q.push(p);

  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;

    q.pop();
    
    for(int i =0; i<4; i++){
      int newX = x+ dx[i];
      int newY = y + dy[i];

      if(table[newX][newY] == 0){ // 범위를 벗어나거나 벽인 경우
        continue;
      }

      if(table[newX][newY] == 1){
        table[newX][newY] = table[x][y] + 1;
        q.push(make_pair(newX,newY));
      }
    }
  }

  cout << table[n][m];
}