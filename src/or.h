#ifndef __OR_H__
#define __OR_H__

#include "rshell.h"
#include "or.h"

using namespace std;

class Or : public Rshell
{
	protected: 
		Rshell *left;
		Rshell *right;

	public:
		Or() : Rshell() {}
		Or(Rshell *l, Rshell *r) : Rshell()
		{
			left = l;
			right = r;
		}
		int exec();
};

#endif
