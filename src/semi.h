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
		int semi_id = 1;		

	public:
		Semi() : Connector() {}
		Semi(Rshell *l, Rshell *r, int semi_id) : Connector()
		{
			this->semi_id = semi_id;
			left = l;
			right = r;
		}
		int exec();
};

#endif
