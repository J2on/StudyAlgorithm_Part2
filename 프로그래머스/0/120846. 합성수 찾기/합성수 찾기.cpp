#include <string>
#include <cmath>
#include <vector>

using namespace std;

// 합성수 => 소수가 아닌 것.
int num[101];

int solution(int n) {
    int answer = 0;
    
    int k;
    for(int i = 2; i <= 10; i++){
        k =2;
        while(i*k <= 100){
            num[i*k] = 1;
            k++;
        }
    }
    
    for(int i=0; i<= n; i++){
        if(num[i] == 1){
            answer++;
        }
    }
    
    
    return answer;
}