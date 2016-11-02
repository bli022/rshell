#ifndef __SEMI_H__
#define __SEMI_H__

#include "semi.h"
#include "connector.h"

using namespace std;

class Semi : public Connector
{
	protected: 
		Rshell *left;
		Rshell *right;

	public:
		Semi() : Connector() {}
		Semi(Rshell *l, Rshell *r) : Connector()
		{
			left = l;
			right = r;
		}
		int exec();
};

#endif
