#include <iostream>
#include <string>
using namespace std;

int main(){
    string name[] = {"A","B","C","D","E"};
    int count[91] = {};
    
    for(int i = 0; i < 5; i++){
        cout << name[i] << endl;
    }
    return 0;
}
