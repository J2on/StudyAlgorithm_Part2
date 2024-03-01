#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
        
    vector<pair<int, string>> timeStamps;
    
    int min;
    for(auto& time : book_time){
        pair<int, string> timeStamp;
        for(int i=0; i<2; i++){
            min = 0;
            min += stoi(time[i].substr(0,2)) * 60;
            min += stoi(time[i].substr(3,2)); 
            
            if(i == 0){ // 입장시간
                timeStamp.first = min;
                timeStamp.second = "입장";
            }
            else{
                timeStamp.first = min + 9; // 청소시간까지 고려
                timeStamp.second = "퇴장"; 
            }
            
            timeStamps.push_back(timeStamp);
        }
    }
    
    sort(timeStamps.begin(), timeStamps.end());
    
    int usingRoom = 0;
    for(auto& p : timeStamps){
        if(p.second == "입장"){
            usingRoom++;
        }
        else if(p.second == "퇴장"){
            usingRoom--;
        }
        
        if(usingRoom > answer){
            answer = usingRoom;
        }
    }
    
    return answer;
}