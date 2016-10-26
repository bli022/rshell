#include <cstring>
#include "rshell.h"

using namespace std;

void rshell::run() 
{
	while(!exit())
	{
		char cmd_str[];
		getline(cin, cmd_str 
		char connector[] = "&&, ;, ||";
		char* cmd = strtok(cmd_str, connector);
		while (cmd != NULL) 
		{
			cmd = strtok(NULL, connector);
		}
	}

}

void rshell::exit()
{
	if (cmd == "exit")
	{
		if_exit = true;
		exit(0);
	}
}
