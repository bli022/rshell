#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <stdio.h>

#include "rshell.h"

using namespace std;

int main() 
{
	string user_input;
	string quit = "exit";

	cout << "$ ";
	getline(cin, user_input);
	
	while(user_input.compare(quit) != 0)
	{	//FIX ME: parses fine. need to correctly put string into array
		char *cmd_arr = new char[user_input.size() + 1];
		const char d[4] = "&;|";
		char *token = strtok(cmd_arr, d);
		

		while (token != NULL) 
		{
			printf(" %s\n", token);
			token = strtok(NULL, d);
		}
	
		cout << "$ ";
		getline(cin, user_input);
	}


	return 0;
}
