#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        string outcome;
        string name;
        cout << "Enter the race outcome, up to 6 winners \nwith an equal number of racers on each team: ";
        cin >> outcome;
        for(int i = 0; i < outcome.length(); i++){
            outcome[i] = toupper(outcome[i]);
        }
        if(outcome == "DONE") exit (0);
        if(outcome.length() > 6 || outcome.length() < 6){
            cout << "Error! \n You entered an incorrect amount of winners!" << endl;
            continue;
        }
        int numTeams = 0;
        int scores['Z'+1] = {};
        int counts['Z'+1] = {};
        for (int i = 0; i < outcome.length(); ++i) {
            if(counts[outcome[i]] == 0){
                name += outcome[i];
                numTeams++;
            }
            counts[outcome[i]]++;
            scores[outcome[i]] += i + 1;
        }
        
        int average = counts[name[0]];
        int check2 = 0;
        int check3 = 0;
        char winner = name[0];
        
        for(int i = 0; i < name.length(); i++){
            if (counts[name[i]] > average || counts[name[i]] < average){
                cout << endl << "Error! \nYou entered too many racers on a single team!" << endl << endl;
                check3 = i;
                break;
                //check2 = i;
            }
            if(check2 != i) break;
        }
        
        if(check2 != check3) continue;
        
        cout << endl << numTeams << " Teams participated." << endl;
        cout << endl <<"Team  Score  Runners" << endl;
        
        sort(name.begin(), name.end());
        int check = 0;
        double temp = (double)scores[name[0]] / (double)counts[name[0]];
        
        for(int i = 0; i < name.length(); i++){
            if(temp > ((double)scores[name[i]] / (double)counts[name[i]])){
                winner = name[i];
                temp = ((double)scores[name[i]] / (double)counts[name[i]]);
            }
            
            cout << name[i] << "     " << (double)scores[name[i]] / (double)counts[name[i]] << "      " << counts[name[i]] << endl;
            check++;
        }
        cout << endl << "The winning team score is " << temp << ", which was scored by team " << winner << "." << endl << endl;
    }
    return 0;
}
