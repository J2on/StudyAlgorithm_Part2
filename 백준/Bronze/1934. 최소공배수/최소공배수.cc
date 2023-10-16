#include<iostream>
#include<vector>
using namespace std;

int find(int a, int b){
  int factorA = 1;
  int factorB = 1;

  int mulA = a;
  int mulB = b;
  if(a == b){ return a; }

  int z;
  if (a > b){ z = a;}
  else { z = b; }

  while(mulA != mulB){
    if(mulA == mulB){ return mulA; }
    else if(mulA > mulB) factorB++;
    else if (mulA < mulB) factorA++;
    
    if(mulA > mulB){
      mulB = b * factorB;
    }
    else{
      mulA = a * factorA;
    }
  }
  return mulA;
}

int main() {
  int num;
  int numA, numB;
  cin >> num;
  
  for(int i=0; i< num; i++){
    cin >> numA >> numB;
    cout << find(numA,numB) << endl;
  }
  
}
