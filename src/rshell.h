#ifndef __RSHELL_H__
#define __RSHELL_H__

#include <iostream>

using namespace std;

class Rshell
{
	public:
		Rshell() { }
		virtual void exec() = 0;
};

#endif
