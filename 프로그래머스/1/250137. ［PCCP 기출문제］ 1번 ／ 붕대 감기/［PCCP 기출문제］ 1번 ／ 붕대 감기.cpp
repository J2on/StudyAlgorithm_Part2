#include <string>
#include <vector>

using namespace std;

int Table[1001];

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int healthNow = health;
    int lastTime;
    for(auto& attack : attacks)
    {
        lastTime = attack[0];
        Table[attack[0]] = attack[1];
    }
    
    int cnt = 0;
    for(int i=0; i<=lastTime; i++)
    {
        if(Table[i] != 0) // 공격이 있는 경우
        {
            healthNow -= Table[i];
            if(healthNow <= 0){
                return -1;
            }
            cnt = 0;
            
            continue;
        }
        
        healthNow += bandage[1];
        cnt++;
        if(cnt == bandage[0]) 
        {
            cnt = 0;
            healthNow += bandage[2];
        }
        
        if(healthNow > health) // 최대 체력 넘었을 경우
        {
            healthNow = health;
        }
    }
    
    
    
    return healthNow;
}