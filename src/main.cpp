#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <algorithm>

#include "rshell.h"
#include "and.h"
#include "semi.h"
#include "or.h"
#include "cmd.h"


using namespace std;

struct node{
    Rshell *value;
    Rshell *left;
    Rshell *right;
}


void parse_arg(string &allArg){
    //stringstream ss(allArg);
    //char par_arg[BUFSIZ];
   /* while(ss >> par_arg){
       //FIXME parse by semi, and then or 
        char * cur_par = new char[BUFSIZ];

        unsigned i = 0;
        for(i = 0; par_arg[i] != '\0'; ++i){
            cur_par[i] = par_arg[i];
        }
        cur_par[i] = '\0';
        *args++ = cur_par;
    }
    *args = 0; */
    
    vector<string> cmds;
    string cmdline = allArg;
    string temp = "";
    string tempsymb = "";
    int mini = 0;
    int find_semi = 0;
    int find_or = 0;
    int find_and = 0;
    while(cmdline != ""){
        find_semi = cmdline.find(";");
        find_or = cmdline.find("||");
        find_and = cmdline.find("&&");
        
        if(cmdline.find(";") == string::npos && cmdline.find("||") == string::npos && cmdline.find("&&") == string::npos){
            temp = cmdline;
            tempsymb = "";
            cmdline = "";
        }
        else{
            mini = min(find_semi,min(find_or,find_and));
            if(mini == find_or || mini == find_and){
                temp = cmdline.substr(0,mini);
                tempsymb = cmdline.substr(mini, mini+2);
                cmdline = cmdline.substr(mini+2);
            }
            else{
                temp = cmdline.substr(0,mini);
                tempsymb = cmdline.substr(mini, mini+1);
                cmdline = cmdline.substr(mini+1);
            }
        }
        cmds.push_back(temp);
        cmds.push_back(tempsymb);
    }
    cmds.pop_back();
    
    
    
    //populate my tree
    for(int i = 0; !cmds.empty(); i++){
        string curr = cmds.at(i);
        if( curr == ";" || curr == "||" || curr == "&&"){
            Connector *contr(
        }
    }
    
}

int main() 
{
	string user_input;
	string quit = "exit";
	//char *cmd_arr[64];
	bool run = true;
	size_t  pos;

	//keeps looping until user types in keyword: exit	
	while (run)	
	{
		cout << "$ ";
		getline(cin, user_input);
		
		if (user_input.find('#') != 0)
		{
            pos = user_input.find('#');
			user_input = user_input.substr(0, pos+1);
		}

		if (user_input.compare(quit) == 0)
		{ 
			cout << "in exit statement" << endl;
			exit(0);
		}
		
		else 
		{
			parse_arg(user_input);
		}

	}
	

	return 0;
}
