//
//  main.cpp
//  Shortest_Path_Non_Recursive
//
//  Created by Errol Roberts on 5/4/19.
//  Copyright © 2019 Errol Roberts. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int NUM_ROWS = 5, NUM_COLS = 6;
string path[NUM_ROWS][NUM_COLS];

void calculateCosts() {
    static int weight[NUM_ROWS][NUM_COLS] = {{3,4,1,2,8,6},
        {6,1,8,2,7,4},
        {5,9,3,9,9,5},
        {8,4,1,3,2,6},
        {3,7,2,8,6,4}};
    static int cost[NUM_ROWS][NUM_COLS] = {{3},
        {6,},
        {5},
        {8},
        {3}};
 
    for(int i = 0; i < 5; i++) path[i][0] = to_string(i);
    
    int minCost = 0;
    for(int j = 1; j < 6; j++){
        for(int i = 0; i < 5; i++){
            int up = cost[(i - 1 + 5) % 5][(j - 1)];
            int left = cost[i][(j - 1)];
            int down = cost[(i + 1 + 5) % 5][(j - 1)];
        
            if(up < left && up < down){
                minCost = up;
                path[i][j] = path[(i - 1 + 5) % 5][j - 1] + to_string(i);
                
            }
            else if(left < up && left < down){
                minCost = left;
                path[i][j] = path[i][j - 1] + to_string(i);
            }
            else {
                minCost = down;
                path[i][j] = path[(i + 1 + 5) % 5][j - 1] + to_string(i);
            }
        
            cost[i][j] = weight[i][j] + minCost;
        }
    }
    
    
    int minRow = 0;
    int smallestCost = cost[0][5];
    
    for(int i = 1; i < 5; i++){
        if(cost[i][5] < smallestCost) minRow = i;
    }
 
    
    cout << "The length of the shortest path is " << cost[minRow][NUM_COLS-1];
    cout << ".\nThe rows of the path from left to right are " << path[minRow][NUM_COLS-1] << "." << endl;
}

int main() {
    calculateCosts();
    
    return 0;
}
