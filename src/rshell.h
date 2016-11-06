#ifndef __RSHELL_H__
#define __RSHELL_H__

#include <iostream>

using namespace std;

class Rshell
{
	protected:
	public:
		Rshell() {symb = 0; };
		virtual int exec() = 0;
		int symb;

};

#endif
