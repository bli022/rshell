#ifndef __SEMI_H__
#define __SEMI_H__

#include "semi.h"
#include "connector.h"

class Semi : public Connector
{
	protected: 
		Rshell *left;
		Rshell *right;		

	public:
		Semi() : Connector() {}
		Semi(Rshell *l, Rshell *r) : Connector()
		{
			symb = 1;
			left = l;
			right = r;
		}
		int exec();
};

#endif
