#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <cstdlib>


#include "rshell.h"


using namespace std;

int main() 
{
	string user_input;
	string quit = "exit";


	cout << '$';
	getline(cin,user_input);

	char *cmd_arr = new char[user_input.size()];
	char *token = strtok(cmd_arr, "&;|");
	
	while (token != NULL) 
	{
		if (user_input.compare(quit) != 0)
		{
			token = strtok(NULL, "&;|");
		}
		else
		{
			exit(0);
		}	
	}




	return 0;
}
