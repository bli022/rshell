#ifndef __AND_H__
#define __AND_H__

#include "rshell.h"

using namespace std;

class And : public Rshell
{
	protected: 
		Rshell *left;
		Rshell *right;

	public:
		And() : Rshell() {}
		And(Rshell *l, Rshell *r) : Rshell()
		{
			left = l;
			right = r;
		}
		int exec();
};

#endif
