#include <cstring>
#include <cstdlib>
#include "rshell.h"

using namespace std;

void rshell::run() 
{
	if (quit() == true)
	{
		exit(0);
	}


	while(quit() == false)
	{
		getline(cin, cmd);
		char *cmd_arr = new char[cmd.size()];
 
		char connector[] = "&&, ;, ||";
		char* token = strtok(cmd_arr, connector);
		while (token != NULL) 
		{
			token = strtok(NULL, connector);
		}
	}

}

bool rshell::quit()
{
	is_exit = false;
	if (cmd.compare("exit"))
	{
		is_exit = true;
		return is_exit;
	}
	return is_exit;
}
