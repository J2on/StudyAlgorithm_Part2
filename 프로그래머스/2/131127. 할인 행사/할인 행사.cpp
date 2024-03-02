#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    unordered_map<string,int> wantHash;
    unordered_map<string,int> discountHash;
    
    queue<string> q;
    
    for(int i = 0; i < want.size(); i++){ // Hash Table을 초기화
        wantHash[want[i]] = number[i]; // 정답지
        discountHash[want[i]] = 0;  // 각 일마다의 구매가능 상품 수 확인
    }
    
    bool isValid;
    for(int i=0; i < 10; i++){ //  1일부터 10일까지 
        if(discountHash.count(discount[i])){ // 있는 경우 1추가
            discountHash[discount[i]] = discountHash[discount[i]] + 1;
        }
        q.push(discount[i]);
        
        // 구매 가능한 날짜인지 확인 
        isValid = true;
        for(auto& c : want){
            if(wantHash[c] > discountHash[c]){
                isValid = false;
                break;
            }
        }
        if(isValid) answer++;
        // 
    }

    for(int i = 10; i < discount.size(); i++){
        
        if(discountHash.count(q.front())){
            discountHash[q.front()] = discountHash[q.front()] - 1;
        }
        q.pop();
        
        // 다음 일자로 넘어감
        q.push(discount[i]);
        if(discountHash.count(discount[i])){
            discountHash[discount[i]] = discountHash[discount[i]] + 1;
        }
        
        
        // 구매 가능한 날짜인지 확인 
        isValid = true;
        for(auto& c : want){
            if(wantHash[c] > discountHash[c]){
                isValid = false;
                break;
            }
        }
        if(isValid) answer++;
        // 
    }
    
    return answer;
}