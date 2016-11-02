#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <vector>
#include <cstring>

#include "cmd.h"

using namespace std;

void Cmd::parse(vector<char *> &token_vector)
{
	int i = 0;
	
	//takes first command from vector<char *> to be parsed further
	char *first = token_vector.at(0);
	char *token = strtok(first, " ");
	while (token != NULL) 
	{
		token_vector[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
}

void Cmd::exec()
{
	
	//Parse single cmd

	pid_t pid = fork();
	int status;	
	
	
	
	//child	
	if (pid == 0)
	{
	
		//FIXME:: execvp parameter types dont match
		if (const char* a, const char []            //execvp(cmd[0], cmd) < 0 
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
