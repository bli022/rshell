#ifndef __CMD_H__
#define __CMD_H__

#include "rshell.h"

using namespace std;

class Cmd : public Rshell
{
	private:
		void parse(vector<char *> &);

	protected:
		char* cmd;
	
	public:
		Cmd(): Rshell() { }
		Cmd(char *a) : Rshell() 
		{
			cmd = a;
		}
		void exec();
};

#endif
