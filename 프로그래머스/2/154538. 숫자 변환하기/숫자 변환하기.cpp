#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int x, int y, int n) {
    int answer = 0;

    if(x == y){
        return 0;
    }
    
    queue<int> q;
    q.push(y);
    
    int qSize;
    int head;
    int num;
    bool isOver = false;
    while(!isOver && !q.empty()){
        qSize = q.size();       
        for(int i = 0; i < qSize; i++){
            head = q.front();
            if(head % 2 == 0){
                num = head / 2;
                if(num == x) { 
                    isOver = true; 
                    break;
                }
                q.push(num);
            }
            
            if(head % 3 == 0){
                num = head / 3;
                if(num == x) { 
                    isOver = true; 
                    break;
                }
                q.push(num);
            }
            
            if(head >= n){
                num = head - n;
                if(num == x) { 
                    isOver = true; 
                    break;
                }
                q.push(num);
            }
            q.pop();
        }
        answer++;
    }
    
    if(!isOver){
        answer = -1;
    }
    
    return answer;
}