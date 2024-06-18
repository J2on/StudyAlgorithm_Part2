#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
  BaekJoon_1427 소트인사이드
*/

int main(){
  int numN;
  scanf("%d", &numN);

  vector<vector<int>> vecXY;
  for(int i=0; i<200001; i++){
    vector<int> emVec = {};
    vecXY.push_back(emVec);
  }

  // vec[1번][2번]에서 1번에 x좌표, 2번에 y좌표들이 들어갈 수 있도록 정리
  int numX, numY;
  int numX2, numY2;
  for(int i=0; i<numN; i++){
    scanf("%d %d", &numX, &numY);
    numX2= numX;
    numY2= numY;
    vecXY[numX2+100000].push_back(numY2); // . (-100,000 ≤ xi, yi ≤ 100,000) 이므로 100000을 더해서 생각함
  }

  int matN[numN][2];
  int numOfProgress = 0;
  for(int i=0; i<200001; i++){
    if(vecXY[i].empty() != true){
      sort(vecXY[i].begin(),vecXY[i].end()); // y좌표들끼리 오름차순으로 배열해줌
      for(int k=0; k<vecXY[i].size(); k++){
        matN[numOfProgress][0] = i;
        matN[numOfProgress][1] = vecXY[i][k];
        numOfProgress++;
      }
    }
  }

  for(int i=0; i<numN; i++){
    printf("%d %d\n", matN[i][0]-100000, matN[i][1]);
  }
}