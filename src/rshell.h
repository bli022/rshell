#ifndef __RSHELL_H__
#define __RSHELL_H__

#include <iostream>

using namespace std;

class Rshell
{
	protected:
	public:
		int symb;
		Rshell() { };
		virtual int exec() = 0;
};

#endif
