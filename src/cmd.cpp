#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

#include "cmd.h"

using namespace std;

void Cmd::print()
{
	pid_t pid = fork();
		
	//child	
	if (pid == 0)
	{
		//FIXME:: execvp parameter types dont match
		if (execvp(cmd[0], cmd) < 0) 
		{
			perror("*** ERROR: Failed when trying to execute command \n");
		}
	}


	//parent process
	else if (pid > 0)
	{
		//wait
		wait(0);
	}

	//fork() failed
	else 
	{
		perror("Error: Couldn't execute command \n");
		return;
	}
}
