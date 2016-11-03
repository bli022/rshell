#ifndef __AND_H__
#define __AND_H__

#include "connector.h"

using namespace std;

class And : public Connector 
{
	protected: 
		Rshell *left;
		Rshell *right;
		int symb; 
		
	public:
		And() : Connector() {/*symb = 2;*/}
		And(Rshell *l, Rshell *r) : Connector()
		{
			symb = 2;
			left = l;
			right = r;
		}
		int exec();
};

#endif
