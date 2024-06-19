#include <string>
#include <vector>
#include <iostream>
using namespace std;

int table[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for(auto& a : puddles){ // 물 웅덩이 표시
        table[a[0]][a[1]] = -1;
    }
    
    table[1][1] = 1;
    
    for(int i = 1; i<=m; i++){
        for (int k=1; k<=n; k++){
            if(table[i][k] == -1){
                continue;
            }
            
            int valRight = table[i][k-1] ;
            int valDown = table[i-1][k];
            if(valRight == -1){
                valRight = 0;
            }
            if(valDown == -1){
                valDown = 0;
            }
            
            table[i][k] += (valRight + valDown) %  1000000007;
        }
    }
    
    answer = table[m][n];
    return answer;
}