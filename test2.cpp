#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

int main() {
   while (true) {
      string outcome;
      string name;
      cout << "Enter the race outcome, up to 6 winners \nwith an equal number of racers on each team: ";
      cin >> outcome;
      if(outcome == "done") exit (0);
      if(outcome.length() > 6 || outcome.length() < 6){
      	cout << "Error! \n You entered an incorrect amount of winners!" << endl; 
      	continue;
	  }
      // If the user entered "done", exit the program
      int numTeams = 0;       // The number of teams
      int scores['Z'+1] = {}; // scores[i] keeps track of the total score of team i
      int counts['Z'+1] = {}; // counts[i] keeps track of the number of runners on team i
      for (int i = 0; i < outcome.length(); ++i) { 
      if(counts[outcome[i]] == 0){
	  	name += outcome[i];
	  	numTeams++;
	  }
      counts[outcome[i]]++;
      scores[outcome[i]] += i + 1;
      }
      cout << "Number of teams :" << numTeams << endl;
      cout << "Team  Score  Runners" << endl;
      
      int average = 0; 
      sort(name.begin(), name.end());
      int winner = 0;
      for(int i = 0; i < name.length(); i++){
      	if (counts[outcome[i]] != 0){
      		average = counts[outcome[i]];
      		if (counts[name[i]] > average || counts[name[i]] < average){
      			cout << "Error! \nYou entered too many racers on a single team!" << endl;
      			break;
      		}
      		cout << name[i] << "     " << (double)scores[name[i]] / (double)counts[name[i]] << "     " << counts[name[i]] << endl;
      		if(winner > scores[name[i]]) winner = name[i];
		  }
	  }
	  cout << endl << "The winner is " << name[winner] << " who scored " << (double)scores[name[winner]] / (double)counts[name[winner]] << "." << endl;
      // If the teams do not all have the same number of runners,
         // Print an error message and ask for input again (go back to the beginning of the loop)
      // Print the number of teams
      // Print the number of runners on each team
      // For each letter from A-Z,
         // If that team participated,
            // Print the name of the team and its average score
            // Also keep track of which team(s) has the best score
      // Print the name of the winning team and its average score (if it's a tie, you may either pick one arbitrarily or print all of the winners)
   }
   return 0;
}
