#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <sstream>

#include "rshell.h"
#include "and.h"
#include "semi.h"
#include "or.h"
#include "cmd.h"


using namespace std;


void parse_arg(string &allArg, char *args[]){
    stringstream ss(allArg);
    char par_arg[BUFSIZ];
    while(ss >> par_arg){
       //FIXME parse by semi, and then or 
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
	char *cmd_arr[64];
	bool run = true;
	size_t  pos;

	//keeps looping until user types in keyword: exit	
	while (run)	
	{
		cout << "$ ";
		getline(cin, user_input);
		
		if (user_input.find('#') != 0)
		{
			user_input = user_input.substr(0, pos - 0);
		}

		if (user_input.compare(quit) == 0)
		{ 
			cout << "in exit statement" << endl;
			exit(0);
		}
		
		else 
		{
			parse_arg(user_input, cmd_arr);
		}

	}
	

	return 0;
}
