#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__

#include "rshell.h"

class Connector : public Rshell
{
	protected:
	public:
		int symb;
		Connector() : Rshell() 
		{
			symb = 0;
		}
		virtual int exec() = 0;
};

#endif
