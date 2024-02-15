#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> numbers) {
    
    int size = numbers.size();
    vector<int> answer(size, -1);
 
    for(int i = size - 2; i >= 0; i--){
        for(int k = i+1; k < size; k++){
            if(numbers[i] < numbers[k]){
                answer[i] = numbers[k];
                break;
            }
            else{
                if(answer[k] == -1){
                    break;
                }
                else if(numbers[i] < answer[k]){
                    answer[i] = answer[k];
                    break;
                }
            }
        }
    }

    return answer;
}