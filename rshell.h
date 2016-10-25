#ifndef __RSHELL_H__
#define __RSHELL_H__

using namespace std;

class rshell
{
	protected:
		string cmd;
	public:
		void exit();
		virtual void print();
};
