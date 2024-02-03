#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <iostream>

using namespace std;
// -48


vector<int> convertDay(string today){
    
    vector<int> result;
    int year,month,day;
    year = 0;
    month = 0;
    day = 0;
    
    year += (int(today[0])-48) * 1000;
    year += (int(today[1])-48) * 100;
    year += (int(today[2])-48) * 10;
    year += (int(today[3])-48);
    
    if(today[5] != '0'){
        month += (int(today[5])-48) * 10;
    }
    month += (int(today[6])-48);
    
    if(today[8] != '0'){
        day += (int(today[8])-48) * 10;
    }
    day += (int(today[9])-48);
    
    result.push_back(year);
    result.push_back(month);
    result.push_back(day);
    return result;
}

void calcMonth(vector<int>& input){
    while(1){
        if(input[1] > 12){
            input[0]++;
            input[1] -= 12;
        }
        else{
            break;
        }
    }
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    vector<int> todayVec = convertDay(today);
    
    // 계약, 기간
    map<char, int> termsMap;
    for(auto& t : terms){
        int num = 0;
        int daySize = t.size() - 2;
        
        for(int i=0; i<daySize; i++){
            num += (int(t[2 + i]) - 48) * pow(10,daySize -1 - i);
        }
        
        termsMap[t[0]] = num;
        cout << num << endl;
    }
    
    for(int i = 0; i < privacies.size(); i++){
        vector<int> signDay = convertDay(privacies[i]);
        signDay[1] += termsMap[privacies[i][11]];
        calcMonth(signDay);
        
        
           
        
        bool isOver = false;
        for(int j = 0; j < 3; j++){
            if(todayVec[j] > signDay[j]){
                isOver = true;
                break;
            }
            else if(todayVec[j] < signDay[j]){
                break;
            }
            else{
                if(j == 2){
                    isOver = true;
                }
            }
        }
        
        if(isOver){
            answer.push_back(i+1);
        }
                
            
        
    }
    
    
    return answer;
}