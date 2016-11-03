#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__

#include "rshell.h"

using namespace std;

class Connector : public Rshell
{
	protected:
       		int and_id = 2;
		int or_id = 3;
		int semi_id = 1;
	
	public:
		Connector(): Rshell() { }
		Connector(int id1, int id2, int id3, int id4) : Rshell() 
		{
			and_id = id1;
			or_id = id2;
			semi_id = id3;
		}
		int exec();
};

#endif
