#ifndef __RSHELL_H__
#define __RSHELL_H__

#include <iostream>

using namespace std;

class rshell
{
	protected:
		string cmd;
		bool is_exit;
	public:
		rshell() { }
		void run();
		bool quit();
		virtual void print() = 0;
};

#endif
