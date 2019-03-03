//
//  8Queens1d.cpp
//  8 Queens
//  One dimensional version of the 8 queens 2d array using a single array
//  Created by Errol Roberts on 2/26/19.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int count = 0;
    int q[8] = {0}, c = 0;
    q[0] = 0; //queen placement
    
nc:c++;
    if(c == 8) goto print;
    q[c] = -1; //same as row = -1;
    
nr:q[c]++;
    if (q[c] == 8) goto backtrack;
    
    for(int i = 0; i < c; i++){
        if(q[i] == q[c]) goto nr; //row check
    }
    
    for(int i = 0; i < c; i++){
        if(q[i] == q[c] || (c - i) == abs(q[c] - q[i])) goto nr; //up and down diagonal check
    }
    goto nc; //goto next column
    
backtrack:c--;
    if(c == -1) return 0;
    goto nr;
    
print:for(int i = 0; i < 8; i++) cout << q[i] << " "; //prints single array list of queen placement
    
    cout << endl << ++count << " solution(s) found" << endl;
    goto backtrack;
}
