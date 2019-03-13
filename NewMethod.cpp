//fourth time writing this program 
//this keyboard is kinda nice for typing code after all

#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c){
	static int adj[8][5] = {{-1}, {0, -1}, {0, 1, -1},{0, 2, -1}, {1, 2, -1}, {1, 2, 3, 4, -1}, {2, 3, 5, -1}, {4, 5, 6, -1}};
	for(int i = 0; i < c; i++){
		if(q[c] == q[i]) return false;	
	}
	
	for(int i = 0; i < c; i++){
		if(abs(q[c] - q[adj[c][i]]) == 1) return false;
	}
	
	return true;
}

void print(int q[]){
    static int count = 0;
    cout << "Solution number: " << ++count << endl << endl;
	cout<< " " << q[1] << q[4] << endl << q[0] << q[2] << q[5] 
	<< q[7] << endl <<" " << q[3] << q[6] <<" " << endl << endl;
}

void backtrack(int c){
    c--;
    if(c == -1) exit(0);
}

int main(){
	int q[8] = {}, c;
	q[0] = 1;
	c = 0;
	

	while (c >= 0) {
		c++;
		if (c == 8) {
			print(q);
			backtrack(c);
		}
		else q[c] = 0;
		while (q[c] <= 9) {
			q[c]++;
			if (q[c] == 9) {
				backtrack(c);
				continue;
			}
			if (ok(q, c)) break;
		}
	}
}
