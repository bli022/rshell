README

I. File list
------------
SRC Branch
|and.cpp   |				AND execution, hosts children
|and.h     |			AND header
|cmd.cpp   |				Execute program file, holds commands of shell
	cmd.h				cmd header
	connector.cpp		Mother class of AND, OR, and SEMI
	connector.h			connector header
	main.cpp			Driver file
	or.cpp				OR execution, hosts children
	or.h				OR header
	rshell.cpp			Abstract Base Class, virtual void exec()
	rshell.h			rshell header
	semi.cpp			SEMI-colon execution, hosts children
	semi.h				SEMI header

II. Design
-----------

Our objective was to create a shell that takes in commands and outputs correctly for what commands were given.
Our main file runs the start of the program into the parsing of the command lines. We parse through to get a 
list of commands and arguments. These commands and arguments are organized in a LinkedList type style with classes
having children built into them. Ex: we have a vector of Rshell (our parent class) that then holds both commands
and connectors. These connectors also host one of three things: semicolons, ANDs or ORs. In the end it somewhat 
looks like a tree to iterate through. We then give this tree to our cmd.cpp. The cmd takes the tree, parses it
a little more and runs executions on it. These executions determine what exactly is going to happen with each command. 
Then they output to the computer each command.

III. Bugs
-----------

