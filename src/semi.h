#ifndef __SEMI_H__
#define __SEMI_H__

#include "rshell.h"
#include "connector.h"

using namespace std;

class Semi : public Connector
{
	protected: 
		Rshell *left;
		Rshell *right;

	public:
		int symb;
		Semi() : Connector() {symb = 1;}
		Semi(Rshell *l, Rshell *r) : Connector()
		{
			symb = 1;
			left = l;
			right = r;
		}
		int exec();
};

#endif
