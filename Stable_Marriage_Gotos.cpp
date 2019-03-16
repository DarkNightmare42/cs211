#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int count = 0;
    int q[8] = {0}, c = 0;
    q[0] = 0; //queen placement
    int mp[3][3] = {{0,2,1},
                    {0,2,1},
                    {1,2,0}};
    int wp[3][3] = {{2,1,0},
                    {0,1,2},
                    {2,0,1}};
    int nm = c;
    int nw = q[c];
    
    
nc:c++;
    if(c == 3) goto print;
    q[c] = -1; //same as row = -1;
    
nr:q[c]++;
    if (q[c] == 3) goto backtrack;
    
    for(int i = 0; i < c; i++){
        if(q[c] == q[i]) goto nr;
        if((mp[nm][q[i]] < mp[nm][nw] && wp[q[i]][nm] < wp[q[i]][i])
           || (mp[i][nw] < mp[i][q[i]] && wp[nw][i] < wp[nw][nm])) goto nr;
    }
    goto nc; //goto next column
    
backtrack:c--;
    if(c == -1) return 0;
    goto nr;
    
print:
	static int solution = 0;
    cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
    for (int i = 0; i < 3; ++i) cout << i << "\t" << q[i] << "\n";
    cout << "\n";
goto backtrack;
}
