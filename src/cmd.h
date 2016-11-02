#ifndef __CMD_H__
#define __CMD_H__

#include <vector>
#include "rshell.h"

using namespace std;

class Cmd : public Rshell
{
	private:
		void parse(vector<char *> &);

	protected:
		vector<char *> the_command;
	
	public:
		Cmd(): Rshell() { }
		Cmd(vector<char *> a) : Rshell() 
		{
			the_command = a;
		}
		void exec();
};

#endif
