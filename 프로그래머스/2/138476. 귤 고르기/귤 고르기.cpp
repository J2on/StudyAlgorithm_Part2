#include <string>
#include <vector>
#include <queue>
using namespace std;

int tCount[10000001];

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    for(auto& t : tangerine){
        tCount[t]++;
    }
    
    priority_queue<int> pq; // 여긴 수만 저장
    for(auto& n : tCount){
        if(n != 0){
            pq.push(n);
        }
        
    }
    
    while(k > 0){
        k -= pq.top();
        pq.pop();
        answer++;
    }
    
    
    return answer;
}