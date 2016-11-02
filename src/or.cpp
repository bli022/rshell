#include <cstdio>
#include "or.h"

int Or::exec()
{
	int status_lhs = left->exec();
	
	//checks for error in left hand side
	if (status_lhs < 0)
	{
		perror("ERROR: failed to execute. \n");
		return -1;
	}

	int status_rhs = right->exec();
	if (status_rhs < 0) 
	{
		perror("ERROR: failed to execute. \n");
		return -1;
	}
	return 0;
}
