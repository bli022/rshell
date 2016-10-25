#include <cstring>
#include "rshell.h"

using namespace std;

rshell::rshell(string &a)
{
	cmd = a;
}

void rshell::run() 
{
	while(true)
	{
		cin << cmd;
	}

}
