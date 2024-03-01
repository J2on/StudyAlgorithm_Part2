#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i','j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    
    vector<char> vec;
    bool isValid;
    for(auto& c : alphabet){
        isValid = true;
        for(int i = 0; i < skip.size(); i++){
            if(skip[i] == c){
                isValid = false;
                break;
            }
        }
        if(isValid) vec.push_back(c);
    }
    
    unordered_map<char, char> um;
    int vecSize = vec.size();
    for(int i=0; i<vecSize; i++){
        um[vec[i]] = vec[(i+index) % vecSize];
    }
    
    for(auto& c:s){
        answer += um[c];
    }
    
    return answer;
}