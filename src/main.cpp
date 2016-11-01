#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <string.h>
#include <stdio.h>

#include "rshell.h"
#include "and.h"
#include "semi.h"
#include "or.h"
#include "cmd.h"


using namespace std;


void parse_arg(string &allArg, char * args[]){
    stringstream ss(allArg);
    char par_arg[BUFSIZ];
    while(ss >> par_arg){
        
        if(par_arg[0] == '<')
            iRedir = true;
        if(par_arg[0] == '>')
            oRedir = true;
        if(par_arg[0] == '|')
            ifPipe = true;
        if(par_arg[0] == '&')
            backgorund = true;
            continue;
        
        char * cur_par = new char[BUFSIZ];

        unsigned i = 0;
        for(i = 0; par_arg[i] != '\0'; ++i){
            cur_par[i] = par_arg[i];
        }
        cur_par[i] = '\0';
        *args++ = cur_par;
    }
    *args = 0;
    
}

int main() 
{
	string user_input;
	string quit = "exit";
	
	do
	{
		cout << "$ ";
		getline(cin, user_input);

		if (user_input.compare(quit) != 0)
		{
			//check for a comment in the string
			size_t pos = user_input.find('#');
			user_input = user_input.substr(0, pos - 0);
	
			//convert user_input to a character array
			char *cmd_arr = new char[user_input.length() + 1];
			copy(user_input.begin(), user_input.end(), cmd_arr);
			cmd_arr[user_input.size()] = '\0';
			//delimiters for strtok function
			const char d[4] = "&;|";
			char *token = strtok(cmd_arr, d);
		
			//loop until end of token
			while (token != NULL) 
			{
<<<<<<< Updated upstream
				//trying stuff
				Cmd *command = new Cmd(token);
				command->exec();
=======
				//Cmd *command = new Cmd(token);
				//command->print();
>>>>>>> Stashed changes
				//FIX ME: call && || and ; respectively when found
				printf(" %s\n", token);
				//int found = find(token, token + 2, '&');
				//if (found) { cout << "found &&" << endl;}
				token = strtok(NULL, d);
				cout << *token << endl;
			}
		}

		else
		{
			exit(0);
		}

	//loop until user wants to exit
	} while(user_input.compare(quit) != 0);
	

	return 0;
}
