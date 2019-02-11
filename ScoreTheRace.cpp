#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main() {
   while (true) {
      string outcome;
      string name;
      cout << "Enter the race outcome, up to 6 winners \nwith an equal number of racers on each team: ";
      cin >> outcome;//input
      for(int i = 0; i < outcome.length(); i++){
      	outcome[i] = toupper(outcome[i]);//change to upper case to avoid unnecessary sensitivity issues
	  }
      if(outcome == "DONE") exit (0); //exit once done
      if(outcome.length() > 6 || outcome.length() < 6){
      	cout << "Error! \n You entered an incorrect amount of winners!" << endl; //number of runners per team check
      	continue;//if team members are not equal among teams, restart the loop
	  }
      int numTeams = 0;       
      int scores['Z'+1] = {}; 
      int counts['Z'+1] = {}; 
      for (int i = 0; i < outcome.length(); ++i) { 
      if(counts[outcome[i]] == 0){//team name listing and number of teams
	  	name += outcome[i];
	  	numTeams++;
	  }
      counts[outcome[i]]++;//score check
      scores[outcome[i]] += i + 1;//count number of runners as well
      }
      cout << endl << numTeams << " Teams participated." << endl;//number of teams participating
      cout << endl <<"Team  Score  Runners" << endl;//headline for the output
      
      int average = 0; 
      sort(name.begin(), name.end());
      int check = 0;
      int check2 = 0;
      char winner = name[0];
      double temp = (double)scores[name[0]] / (double)counts[name[0]];
      int check3 = 0;
      
      for(int i = 0; i < name.length(); i++){
        average = counts[outcome[i]];
      	if (counts[name[i]] > average || counts[name[i]] < average){
      		cout << endl << "Error! \nYou entered too many racers on a single team!" << endl << endl;//check number of racers on each team is equal
      		check3 = i;
      		break;
      		check2 = i;
      	}
      	if(check2 != i) continue;
      }
      
      if(check2 != check3) continue; //additional continue command to avoid unnecessary cout statements, restart the loop instead
      
      for(int i = 0; i < name.length(); i++){
      	if(temp > ((double)scores[name[i]] / (double)counts[name[i]])){//check and store winner and their score
      	    winner = name[i];
      	    temp = ((double)scores[name[i]] / (double)counts[name[i]]);
      	}
      	
      	cout << name[i] << "     " << (double)scores[name[i]] / (double)counts[name[i]] << "      " << counts[name[i]] << endl;
		check++;//cout name of teams and their scores
	  }
	  if(check == name.length()) cout << endl << "The winning team score is " << temp << ", which was scored by team " << winner << "." << endl << endl;
   }      //cout winning team and their score
   return 0;
}
