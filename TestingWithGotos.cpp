#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int q[8] = {}, c = 0;
	int count = 0;
	static int adj[8][5] = {{-1}, {0, -1}, {0, 1, -1},{0, 2, -1}, {1, 2, -1}, {1, 2, 3, 4, -1}, {2, 3, 5, -1}, {4, 5, 6, -1}};

	q[0] = 1;
	
	nextBox:c++;
	if(c == 8) goto print;
	q[c] = 0;
	
	nextNumber:q[c]++;
	if(q[c] == 9) goto backtrack;
	
	for(int i = 0; i < c; i++){
		if(q[c] == q[i]) goto nextNumber;
	}
	
	for(int i = 0; adj[c][i] != -1; i++){
		if(abs(q[c] - q[adj[c][i]]) == 1) goto nextNumber;
	}
	
	goto nextBox;
	
	backtrack:c--;
	if(c == -1) return 0;
	goto nextNumber;
	
	print:	cout << "Solution number: " << ++count << endl << endl;
	cout<<" " <<q[1] <<q[4] <<endl <<q[0] <<q[2] <<q[5] <<q[7] <<endl <<" " <<q[3] <<q[6] <<" " <<endl << endl;
	goto backtrack;

}
