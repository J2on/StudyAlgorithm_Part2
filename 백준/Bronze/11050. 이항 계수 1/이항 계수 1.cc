#include <iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int temp = k;
    int result = 1;
    int div = 1;
    for(int i=0; i<temp; i++){
        result *= n;
        div *= k;
        n -= 1;
        k -= 1;
    }
    cout << result / div;
}