#ifndef __AND_H__
#define __AND_H__

#include "connector.h"

using namespace std;

class And : public Connector 
{
	protected: 
		Rshell *left;
		Rshell *right;
		int and_id = 2; 
		
	public:
		And() : Connector() {}
		And(Rshell *l, Rshell *r, int and_id) : Connector()
		{
			this->and_id = and_id;
			left = l;
			right = r;
		}
		int exec();
};

#endif
