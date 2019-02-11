#include <iostream>
#include <stdlib.h>
using namespace std;

bool equivalent(int a[], int b[], int n){
    int count = 0;
	for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
          if(a[i] == b[j]){
            count++;
            if(count == n) return true;
          }
      }
  }
  return false;
}

int main(){
	cout << boolalpha;
	
	int a[5] = {1, 2, 3, 4, 5};
	int b[5] = {3, 4, 5, 1, 2};
	
	cout << "Both arrays are equivalent: " << equivalent(a, b, 5);
}
