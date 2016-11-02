#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__

#include "rshell.h"

using namespace std;

class Connector : public Rshell
{
	protected:
        
	
	public:
		Connector(): Rshell() { }
		Connector(char *a) : Rshell() 
		{
			
		}
		int exec();
};

#endif
