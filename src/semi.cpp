#include <cstdio>
#include "semi.h"

using namespace std;

int Semi::exec() 
{	
	// if left child can't execute
	int status_lhs = left->exec();
	if (status_lhs < 0)
	{
		perror("ERROR: could not execute. \n");
	}

	//error checking for right child
	int status_rhs = right->exec();
	if (status_rhs < 0)
	{
		perror("ERROR: could not execute. \n");
	}

	return 0;
}
