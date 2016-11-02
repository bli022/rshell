#ifndef __OR_H__
#define __OR_H__

#include "connector.h"

using namespace std;

class Or : public Connector
{
	protected: 
		Rshell *left;
		Rshell *right;

	public:
		Or() : Connector() { }
		Or(Rshell *l, Rshell *r) : Connector()
		{
			left = l;
			right = r;
		}
		int exec();
};

#endif
