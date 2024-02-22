#include <string>
#include <vector>
#include <unordered_map>
#include <queue> 

using namespace std;

vector<int> solution(string s) {
    
    unordered_map<int,int> um;
    
    string temp = "";
    for(int i=0; i < s.size(); i++){
        if(s[i] == '{'){
            continue;
        }
        
        if(s[i] == ',' || s[i] == '}'){
            if(temp.size() != 0){
                int num = stoi(temp);
                um[num] += 1;
                temp = "";
            }
        }
        else{
            temp += s[i];
        }
    }
    
    priority_queue<pair<int,int>> pq;
    for(auto& n : um){
        pair<int,int> p(n.second, n.first);    
        pq.push(p);
    }
    
    vector<int> answer;
    while(!pq.empty()){
        pair<int,int> p = pq.top();
        answer.push_back(p.second);
        pq.pop();
    }
    
    return answer;
}