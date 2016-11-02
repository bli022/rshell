#ifndef __CMD_H__
#define __CMD_H__

#include "rshell.h"

using namespace std;

class Cmd : public Rshell
{
	protected:
		char* cmd;
	
	public:
		Cmd(): Rshell() { }
		Cmd(char *a) : Rshell() 
		{
			cmd = a;
		}
		void parse();
		void exec();
};

#endif
