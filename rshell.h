#ifndef __RSHELL_H__
#define __RSHELL_H__

#include <iostream>

using namespace std;

class rshell
{
	protected:
		string cmd;
	public:
		rshell() { }
		virtual void print() = 0;
};

#endif
