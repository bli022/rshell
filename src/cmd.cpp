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

int Cmd::exec()
{
		
	//Parse single cmd
	parse(the_command);

	pid_t pid = fork();
	int status = 0;	
	
	
	
	//child	
	if (pid == 0)
	{
		//do execvp
		char **command = &the_command.at(0);
		int exec_stat = execvp(the_command.at(0), command);

	
		if (exec_stat < 0) 
		{ 
			perror("*** ERROR: Failed when trying to execute command in child. \n");
		}
		
	}


	//parent process
	else if (pid > 0)
	{
		//wait
		while (waitpid(pid, &status, 0) != pid) 
		{}
	}

	//fork() failed
	else 
	{
		perror("Error: Couldn't execute command because fork() failed. \n");
		return -1;
	}

return 0;

}
