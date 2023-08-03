#include<iostream>
using namespace std;

int main(){
    int testCaseNum;
    cin >> testCaseNum;

  
    int x, y;
    int rectangle[4] = {0,}; // {LeftBotX, LeftBotY, RightTopX, RightTopY}
    for(int i=0; i < testCaseNum; i++){
        cin >> x >> y;
        if(i == 0){
            rectangle[0] = x;
          
            rectangle[2] = x;
          
            rectangle[1] = y;
          
            rectangle[3] = y;
          
            continue;
        }
      
        if(x < rectangle[0]){
            rectangle[0] = x;
        }
        else if(x > rectangle[2]){
            rectangle[2] = x;
        }
        
        if(y < rectangle[1]){
            rectangle[1] = y;
        }
        else if(y > rectangle[3]){
            rectangle[3] = y;
        }
    }
    
    int result = (rectangle[2] - rectangle[0]) * (rectangle[3] - rectangle[1]);
    cout << result;
}