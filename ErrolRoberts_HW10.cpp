#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
    for(int i = 0; i < c; i++){
        if(q[i] == q[c] || (c - i) == abs(q[c] - q[i])) return false;
    }
    return true;
}

int nqueens(int n) {
	int count = 0, c = 0;
	int *q;
	q = new int[n];
	for(int i = 0; i < n; i++) q[i] = 0;
	q[0] = 0;
	
	while (c >= 0) {
	        c++;
	        if(c == n){
	            count++;
	            c--;
	           // if(c == -1 ){
			//		break;
				}
	        else q[c] = -1;
	        while (c >= 0) {
	            q[c]++;
	            if(q[c] == n){
	                c--;
	                continue;
	            }
	            if(ok(q, c)){
	                break;
	            }
	        }
	    }
   delete []q;
   return count;
}

int main() {
   int n = 12;
   for (int i = 1; i <= n; ++i)
      cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
   return 0;
}
 
