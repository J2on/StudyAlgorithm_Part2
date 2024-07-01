#include <iostream>
#include <vector>
using namespace std;
 
 
int lw[100001];
int op[100001];

int main()
{
    int n;
    cin >> n;
    
    for( int i=0; i<n-1; i++){
        cin >>lw[i];
    }
    
    for( int i=0; i<n; i++){
        cin >>op[i];
    }
    
    int totalPrice = 0;
    int oil = lw[0]; // 구매 양, 다음 지점 까지는 무조건 사야하니
    int nowPrice = op[0];
    
    for(int i=1; i<n; i++)
    {
        if(nowPrice > op[i])
        {
            totalPrice += oil * nowPrice;
            oil = lw[i];
            nowPrice = op[i];
        }
        else
        {
            oil += lw[i];
        }
    }
    
    totalPrice += oil * nowPrice; // 마지막까지 남아있는 경우
    
    cout << totalPrice;
    
    return 0;
}