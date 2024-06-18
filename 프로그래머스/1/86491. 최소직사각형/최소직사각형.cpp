#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    for(auto& a : sizes){
        if(a[0] > a[1])
        {
            int temp = a[0];
            a[0] = a[1];
            a[1] = temp;
        }
    }
    
    int max0 = 0;
    int max1 = 0;
    for(auto& a : sizes){
        if(a[0] > max0)
        {
            max0 = a[0];
        }
        
        if(a[1] > max1)
        {
            max1 = a[1];
        }
    }
    
    answer = max0 * max1;
    return answer;
}