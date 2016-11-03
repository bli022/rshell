#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__

#include "rshell.h"

using namespace std;

class Connector : public Rshell
{
	public:
       		int symb;
		Connector(): Rshell() { }
		int exec();
};

#endif
