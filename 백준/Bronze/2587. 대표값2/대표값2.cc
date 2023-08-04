#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> numVec;
    int num;
    int sum = 0;
    for(int i=0; i<5; i++){
        cin >> num;
        numVec.push_back(num);
        sum += num;
    }
    
    int temp;
    for(int i = 0; i < numVec.size(); i++){
        for(int j=0; j < numVec.size() - i -1; j++){
            if(numVec[j] > numVec[j+1]){
                temp = numVec[j];
                numVec[j] = numVec[j+1];
                numVec[j+1] = temp;
            }
        }
    }
    
    cout << sum/5 << ' ' << numVec[2];
}