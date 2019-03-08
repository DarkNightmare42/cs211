//
//  main.cpp
//  1D8QueensNoGotos
//
//  Created by Errol Roberts on 3/3/19.
//

#include <iostream>
#include <cmath>
using namespace std;
bool ok(int q[], int c) {
    for(int i = 0; i < c; i++){
        if(q[i] == q[c] || (c - i) == abs(q[c] - q[i])) return false;
    }
    return true;
}

void print(int q[]) {
    cout << "print started " << endl;
    static int numSolutions = 0;
    cout << "Solution #" << ++numSolutions << ": ";
    for(int i = 0; i < 8; i++) cout << q[i];
    cout << "\n";
}
void backtrack(int& col){
    col--;
    if(col == -1) exit(0);
}
int main() {
    int q[8] = {}, c = 0;
    q[0] = 0;
    c = 0;
    while (c >= 0) {
        c++;
        if(c == 8){
            print(q);
            backtrack(c);
        }
        else q[c] = -1;
        while (c >= 0) {
            q[c]++;
            if(q[c] == 8){
                backtrack(c);
                continue;
            }
            if(ok(q, c)){
                break;
            }
        }
    }
    return 0;
}

