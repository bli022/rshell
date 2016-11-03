#ifndef __OR_H__
#define __OR_H__

#include "connector.h"

using namespace std;

class Or : public Connector
{
	protected:
		int or_id = 3; 
		Rshell *left;
		Rshell *right;

	public:
		Or() : Connector() { }
		Or(Rshell *l, Rshell *r, int or_id) : Connector()
		{
			this->or_id = or_id;
			left = l;
			right = r;
		}
		int exec();
};

#endif
