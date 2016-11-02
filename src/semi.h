#ifndef __SEMI_H__
#define __SEMI_H__

class Semi : public Rshell
{
	protected: 
		Rshell *left;
		Rshell *right;

	public:
		Semi() : Rshell {}
		Semi(Rshell *l, Rshell *r) : Rshell
		{
			left = l;
			right = r;
		}
		int exec();
};

#endif
