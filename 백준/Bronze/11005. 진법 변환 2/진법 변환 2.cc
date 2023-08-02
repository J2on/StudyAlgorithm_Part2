#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
  int N;
  int B;
  
  cin >> N >> B;

  int square = 0;
  int div = N / pow(B,square);
  
  while( int(N / pow(B,square+1)) > 0){
    square++;
    div = N / pow(B,square);
  }


  for(int i=square; i>=0; i--){
    div = N / pow(B,i);
    N -= div * pow(B,i);
    if(div >= 10){
      div +=55;
    }
    else{
      div += 48;
    }
    cout << char(div);
    
  }
}