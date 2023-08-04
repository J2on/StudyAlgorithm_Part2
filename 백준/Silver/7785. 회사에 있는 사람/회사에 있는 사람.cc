#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  string name, status;

  int num;   
  cin >> num;

  vector<string> employees;
  for(int i=0; i<num; i++){
    cin >> name >> status;
    employees.push_back(name);
  }
  
  sort(employees.rbegin(), employees.rend());
  for(int i=0; i<employees.size(); i++){
    if(employees[i] == employees[i+1]){
      i++;
    }
    else{
      cout << employees[i] << '\n';
    }
  }  
}