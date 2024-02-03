#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    int num = people.size();
    sort(people.begin(), people.end());
    
    int start = 0;
    while(start < num){
        if(people[start] + people[num-1] > limit){
            answer++;
            num--;
        }
        else{
            answer++;
            start++;
            num--;
            
        }
    }
    
    return answer;
}