#ifndef __RSHELL_H__
#define __RSHELL_H__

using namespace std;

class rshell
{
	protected:
		string cmd;
		bool if_exit = false;
	public:
		rshell() { }
		//rshell(string &);
		void run();
		void exit();
		virtual void print();
};
