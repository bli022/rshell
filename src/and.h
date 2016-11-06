#ifndef __AND_H__
#define __AND_H__

#include "connector.h"

class And : public Connector 
{
	protected: 
		Rshell *left;
		Rshell *right; 
		
	public:
		And() : Connector() {}
		And(Rshell *l, Rshell *r) : Connector()
		{
			symb = 2;
			left = l;
			right = r;
		}
		int exec();
};

#endif
