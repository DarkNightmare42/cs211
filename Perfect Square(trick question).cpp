#include <iostream>
using namespace std;

int main(){
  long i = 1, square = 0, temp1 = 0, temp2 = 0; 
  
  while (true){
      square = i * i;
      if (square > 1){
          temp1 = square % 10;
          if (temp1 % 2 != 0){
              temp2 = (square / 10) % 10;
              if (temp2 % 2 != 0) break;
          }
              
      }
      square = 0;
      temp1 = 0;
      temp2 = 0;
      i++;
  }

  cout << i << " squared produces " << square << " which is a perfect square with the last two digits being odd";

  return 0;
}
