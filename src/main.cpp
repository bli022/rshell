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
				Cmd *command = new Cmd(token);
				command->exec();
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
