#include <unistd.h>
#include <cstdio>
#include "cmd.h"

using namespace std;

void Cmd::print()
{
	char *argv[3] = this->cmd;
	argv[3] = NULL;
	execvp(cmd, argv);


	//if (execvp(cmd, args) == -1)
	//{
		//perror("exec");
	//}
}
