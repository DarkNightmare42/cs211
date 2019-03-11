//
//  main.cpp
//  8NumbersInACross
//
//  Created by Errol Roberts on 3/9/19.
//  Copyright © 2019 Errol Roberts. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

bool ok(int cross[], int current){
    static int adjacent_table[8][5] = {{-1}, {0, -1}, {0, 1, -1},{0, 2, -1}, {1, 2, -1}, {1, 2, 3, 4, -1}, {2, 3, 5, -1}, {4, 5, 6, -1}};
    int i = 0;
    int neighborbox = adjacent_table[cross[i]][i];
    
    while(neighborbox != -1){
        if(current == neighborbox) return false;
        if(abs(current - neighborbox) == 1) return false;
        i++;
    }
    return true;
}

void print(int cross[]){
    static int count = 0;
    for(int i = 0; i < 8; i++){
        count++;
        cout << "Solution number " << count << " is :" << cross[i] << endl;
    }
}

void backtrack(int current){
    current--;
    if(current == -1) exit(0);
}

int main(){
    int current = 0, cross[8] = {};
   // int set[8] = {1, 2, 3, 4, 5, 6, 7, 8};
   // int i = 0;
    cross[0] = 0;
    cross[current] = 0;
    
    while(current >= 0){
        current++;
        if(current == 8){
            print(cross);
            backtrack(current);
        }
        else cross[current] = 0;
        while(current >= 0){
            cross[current]++;
            if(cross[current] == 9){
                backtrack(current);
                continue;
            }
            if(ok(cross, current)){
                break;
            }
        }
    }
}
