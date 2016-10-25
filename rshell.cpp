#include <cstring>
#include "rshell.h"

using namespace std;

void rshell::run() 
{
	while(true)
	{
		cin << cmd;
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
