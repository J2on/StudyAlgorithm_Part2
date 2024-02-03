#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

/*
두 사람이

1. A-B 둘 중 서로에게 선물 많이 준 사람이 다음 달에 선물 하나를 더 받음
2. A-B 둘이 서로에게 준 선물이 같다면 전체 선물+- 에서 작은 사람이 선물 하나를 더 받음
3. A-B 둘이 선물 수 같고, 지수도 같으면 주고 받지 않음
*/

int table[50][50];
int factors[50];
int nextGifts[50];

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int fSize = friends.size();
    
    map<string, int> nameHash;
    for(int i = 0; i < fSize; i++){
        nameHash[friends[i]] = i; 
    }
    
    for(auto& g : gifts){
        int x, y;
        y = nameHash[g.substr(0, g.find(' '))];
        x = nameHash[g.substr(g.find(' ') + 1)];
        table[y][x]++;
    }
    
    for(int i = 0; i < fSize; i++){
        for(int j = 0; j < fSize; j++){
            factors[i] += table[i][j];
            factors[i] -= table[j][i];
        }
    }
    
    for(int i = 0; i < fSize; i++){
        for(int j = i; j < fSize; j++){
            if(j == i){ continue; }
            if(table[i][j] > table[j][i]){
                nextGifts[i]++;
            }
            else if(table[i][j] < table[j][i]){
                nextGifts[j]++;
            }
            else{
                if(factors[j] > factors[i]){
                    nextGifts[j]++;
                }
                else if(factors[i] > factors[j]){
                    nextGifts[i]++;
                }
                else{
                    // 그냥 진행
                }
            }
        }
    }
    
    for(auto& k : nextGifts){
        if (k > answer){
            answer = k;
        }
    }

    return answer;
}