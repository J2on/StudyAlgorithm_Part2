#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int numN;
    int sum;
    while(1){
        sum = 1;
        vector<int> vec = {1};
        cin >> numN;
        if(numN == -1){break;}
        
        for(int i = 2; i< sqrt(numN); i++){
            if(numN % i == 0){
                vec.push_back(i);
                vec.push_back(numN/i);
                sum += i;
                sum += numN/i;
            }
        }
        
        if(sum != numN){
            cout << numN << " is NOT perfect.";
        }
        else{
            sort(vec.begin(),vec.end());
            cout << numN << " = " << vec[0];
            
            for(int i=1; i<vec.size(); i++){
                cout << " + " << vec[i];
            }
        }
        cout << endl;
    }
}