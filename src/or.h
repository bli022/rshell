#ifndef __OR_H__
#define __OR_H__

#include "connector.h"
#include "rshell.h"

using namespace std;

class Or : public Connector
{
	protected:
		Rshell *left;
		Rshell *right;

	public:
		int symb;
		Or() : Connector() {/*symb = 3;*/ }
		Or(Rshell *l, Rshell *r) : Connector()
		{
			symb = 3;
			left = l;
			right = r;
		}
		int exec();
};

#endif
