#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

#include "cmd.h"

using namespace std;

void Cmd::exec()
{
	pid_t pid = fork();
	int status;	

	
	//child	
	if (pid == 0)
	{
	/*
		//FIXME:: execvp parameter types dont match
		if (const char* a, const char b              //execvp(cmd[0], cmd) < 0*/ 
		{
			perror("*** ERROR: Failed when trying to execute command in child. \n");
		}
	}


	//parent process
	else if (pid > 0)
	{
		//wait
		while (waitpid(pid, &status, 0) != pid) 
		{
			if (pid == 0) {
				return;
			}

			else if (pid == -1) 
			{
				perror("*** ERRROR: Failed when trying to execute. \n");
			}
		}
	}

	//fork() failed
	else 
	{
		perror("Error: Couldn't execute command because fork() failed. \n");
		return;
	}
}
