#ifndef __AND_H__
#define __AND_H__

#include "connector.h"

using namespace std;

class And : public Connector 
{
	protected: 
		Rshell *left;
		Rshell *right;

	public:
		And() : Connector() {}
		And(Rshell *l, Rshell *r) : Connector()
		{
			left = l;
			right = r;
		}
		int exec();
};

#endif
