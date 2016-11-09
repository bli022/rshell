#ifndef __CMD_H__
#define __CMD_H__

#include <vector>
#include "rshell.h"

class Cmd : public Rshell
{
	private:
		void parse(vector<char *> &);

	protected:
//		vector<char *> the_command;
		char *the_command;	

	public:
		int symb;
		Cmd(): Rshell() {symb = 0; }
		Cmd(char *a) : Rshell() 
		{
			symb = 0;
			the_command = a;
		}
		int exec();
};

#endif
