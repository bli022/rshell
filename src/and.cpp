#include <cstdio>
#include "and.h"
#include "rshell.h"
#include "cmd.h"

using namespace std;

int And::exec()
{
	int status_lhs = this->left->exec();
	if (status_lhs < 0) 
	{
		perror("ERROR: failed to execute. \n");
		return -1;
	}
	
	// left sucessfully executed
	// trying to execute right
	else 
	{
		int status_rhs = this->right->exec();
		if (status_rhs < 0) 
		{
			perror("ERROR: failed to execute. \n");
			return -1;
		}
	return 0;
}
