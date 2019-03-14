//
//  main.cpp
//  Stable_Marriage
//
//  Created by Errol Roberts on 3/14/19.
//  Copyright © 2019 Errol Roberts. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
bool ok(int q[], int col){
    int mp[3][3] = {{0,2,1},
                    {0,2,1},
                    {1,2,0}};
    int wp[3][3] = {{2,1,0},
                    {0,1,2},
                    {2,0,1}};
    int nm = col;
    int nw = q[col];
    
    for(int i = 0; i < col; i++){
        if(q[col] == q[i]) return false;
        if((mp[nm][q[i]] < mp[nm][nw] && wp[q[i]][nm] < wp[q[i]][i])
           || (mp[i][nw] < mp[i][q[i]] && wp[nw][i] < wp[nw][nm])) return false;
    }
    return true;
}

void print(int q[]) {
    static int solution = 0;
    cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
    for (int i = 0; i < 3; ++i)
        cout << i << "\t" << q[i] << "\n";
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
    
    while(true){
        while (c >= 0) {
            c++;
            if(c == 3){
                print(q);
                backtrack(c);
            }
            else q[c] = -1;
            while (c >= 0) {
                q[c]++;
                if(q[c] == 3){
                    backtrack(c);
                    continue;
                }
                if(ok(q, c)){
                    break;
                }
            }
        }
    }
    return 0;
}

