#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__

#include "rshell.h"

using namespace std;

class connector : public Rshell
{
	protected:
        
	
	public:
		connector(): Rshell() { }
		connector(char *a) : Rshell() 
		{
			
		}
		void exec();
};

#endif
