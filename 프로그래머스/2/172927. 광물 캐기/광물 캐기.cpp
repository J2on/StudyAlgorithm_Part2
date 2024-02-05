#include <string>
#include <vector>
#include <queue>

using namespace std;

// 곡괭이와 미네랄 셋을 입력받아 한 세트의 피로도 계산
int calc(int pick, vector<int> mineral){ 
    int result = 0; 
    
    if(pick == 0){
        result += mineral[0];
        result += mineral[1];
        result += mineral[2];
    }
    else if(pick == 1){
        result += mineral[0] * 5;
        result += mineral[1];
        result += mineral[2];
    }
    else if(pick == 2){
        result += mineral[0] * 25;
        result += mineral[1] * 5;
        result += mineral[2];
    }
    return result;
}

// 5개씩 {다이아, 철, 돌} 를 해서 정렬해서 다이아 많은 것 부터 다이아 곡괭이 쓰면 될 듯  
int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    // 곡괭이의 수.. 곡괭이를 앞에서부터 쓰니까 곡괭이 수를 넘어서는 광물은 고려대상이 아님.
    int pickNum = 0;
    for(auto& p :picks){
        pickNum += p;
    }
    
    priority_queue<vector<int>> pq;
    queue<string> q;
    
    // 순차적으로 꺼내기 위해 q사용
    for(auto& a : minerals){
        q.push(a);
    }
    
    // 캘 수 있는 광물 중 다이아 곡괭이에 대한 우선순위 부여
    for(int i = 0; i < pickNum; i++){
        vector<int> newVec = {0,0,0};
        for(int j=0; j<5; j++){
            if(q.front() == "diamond"){
                newVec[0]++;
            }
            else if(q.front() == "iron"){
                newVec[1]++;
            } 
            else if(q.front() == "stone"){
                newVec[2]++;
            }
            q.pop();
            if(q.empty()){
                break;
            }
        }
        pq.push(newVec);
        if(q.empty()){
                break;
        }
    }

    // 곡괭이와 미네랄 세트를 입력
    while(!pq.empty()){
        int pick;

        if(picks[0] > 0){
            pick = 0;
            picks[0]--;
        }
        else if(picks[1] > 0){
            pick = 1;
            picks[1]--;
        }
        else if(picks[2] > 0){
            pick = 2;
            picks[2]--;
        }
        else{
            break;
        }
        answer += calc(pick, pq.top());
        pq.pop();
    }
    
    
    return answer;
}
