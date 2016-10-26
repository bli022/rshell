#include <iostream>
#include <string>
#include <cstring>

#include "rshell.h"


using namespace std;

int main() 
{
	string user_input;
	string quit = "exit";

	cout << "$ ";
	getline(cin, user_input);
	
	while(user_input.compare(quit) != 0)
	{
		char *cmd_arr = new char[user_input.size()];
		char *token = strtok(cmd_arr, "&;|");

		while (token != NULL) 
		{
		//	cout << token << endl;
			token = strtok(NULL, "&;|");
		}
	
		cout << "$ ";
		getline(cin, user_input);
	}


	return 0;
}
