#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <stack>

#include "rshell.h"
#include "and.h"
#include "semi.h"
#include "or.h"
#include "cmd.h"
#include "connector.h"

using namespace std;

struct node{
    Rshell *value;
    Rshell *left;
    Rshell *right;
};

void __parse_arg (string &cmdline, vector<string> cmds) {
	string tmp = cmdline;	
	while(cmdline != ""){
		cout << "GOT HERE!" << endl;	
		size_t _and = cmdline.find("&&");
		size_t _or = cmdline.find("||");
		cout << "and = " << _and << ", or = " << _or << endl;
		if(_and != string::npos && _and < _or && _or != string::npos){
			cout << "1" << endl;
			tmp = cmdline.substr(0, _and);
			cmds.push_back(tmp);
			tmp = cmdline.substr(_and, _and + 2);
			cmds.push_back(tmp);
			cmdline = cmdline.substr(_and + 2, cmdline.size());
		}
		else if (_or != string::npos && _or < _and && _and != string::npos){
			cout << "2" << endl;
			tmp = cmdline.substr(0, _or);
			cmds.push_back(tmp);
			tmp = cmdline.substr(_or, _or + 2);
			cmds.push_back(tmp);
			cmdline = cmdline.substr(_or + 2, cmdline.size());
		}
		else if(_or == string::npos || _and == string::npos){
			if(_and <  _or && _and != string::npos){
				cout << "3" << endl;
				tmp = cmdline.substr(0, _and);
				cmds.push_back(tmp);
				tmp = cmdline.substr(_and, _and + 2);
				cmds.push_back(tmp);
				cmdline = cmdline.substr(_and + 2, cmdline.size());
	
			}
			else if (_or <  _and && _or != string::npos){
				cout << "4" << endl;
				tmp = cmdline.substr(0, _or);
				cmds.push_back(tmp);
				tmp = cmdline.substr(_or, _or + 2);
				cmds.push_back(tmp);
				cmdline = cmdline.substr(_or + 2, cmdline.size());
			}
			else{
				cout << "6" << endl;
				cmds.push_back(cmdline);
				cmdline = "";
			}
		}
		else {
			cout << "5" << endl;
			cmds.push_back(cmdline);
			cmdline = "";	
		} 
	}
	cout << "FINISHED THIS THING" << endl;

}

	//convert strings to rshell classes
	//return: rshell ptr
	//parameter: vector<strings>
/*
Rshell* populate(vector<string> node_vector, vector<Rshell*> theonethatleft,  int cur_pos) {

    if(node_vector.size() == 1){
	char * first;
	vector<char *> one;
	one.push_back(first);
	strcpy(one.at(0), node_vector.at(0).c_str());
	Cmd* base = new Cmd(one);
    	return base;
    }
    vector<char *> a;
    char* aw = new char();
    vector<char *> b;
    char* bw = new char();
    
    if(node_vector.size() != 1){
        strcpy(aw, node_vector.at(0).c_str());
        int sizer = theonethatleft.size();
        for(int i = 2; i < sizer; i=i+2){
            if(theonethatleft.at(i)->symb == 1){
                Semi *contr_semi = new Semi(theonethatleft.at(i-2), theonethatleft.at(i-1));
           	theonethatleft.at(i) = contr_semi;
	    }
            else if(theonethatleft.at(i)->symb == 2){
                And *contr_and = new And(theonethatleft.at(i-2), theonethatleft.at(i-1));
           	theonethatleft.at(i) = contr_and;
	    }
            else if(theonethatleft.at(i)->symb == 3){
                Or *contr_or = new Or(theonethatleft.at(i-2), theonethatleft.at(i-1));
            	theonethatleft.at(i) = contr_or;
	    }
            theonethatleft.erase(theonethatleft.begin()+i-2);
            theonethatleft.erase(theonethatleft.begin()+i-1);
            sizer -= 2;
        }
    }
	else if (node_vector.at(cur_pos) == ";") {
	//left and right: check curpos -1 in the vector
	//if cur_pos -1 is Command: call Command constructor
	//else populate(vector<string>, cur_pos-1)
        strcpy(aw, node_vector.at(cur_pos - 1).c_str());
        a.push_back(aw);
        Cmd* aa = new Cmd(a);
        
        strcpy(bw, node_vector.at(cur_pos + 1).c_str());
        b.push_back(bw);
        Cmd* bb = new Cmd(b);
        
		Semi* contr_semi = new Semi(aa, bb);
        theonethatleft.push_back(contr_semi);
        node_vector.erase(node_vector.begin()+cur_pos+1);
        node_vector.erase(node_vector.begin()+cur_pos-1);
        cur_pos--;
	}
	else if (node_vector.at(cur_pos)== "||") {
        strcpy(aw, node_vector.at(cur_pos - 1).c_str());
        a.push_back(aw);
        Cmd* aa = new Cmd(a);
        
        strcpy(bw, node_vector.at(cur_pos + 1).c_str());
        b.push_back(bw);
        Cmd* bb = new Cmd(b);
        
		Or* contr_or = new Or(aa, bb);
        theonethatleft.push_back(contr_or);
        node_vector.erase(node_vector.begin()+cur_pos+1);
        node_vector.erase(node_vector.begin()+cur_pos-1);
        cur_pos--;
	}
	else if (node_vector.at(cur_pos) == "&&") {
        strcpy(aw, node_vector.at(cur_pos - 1).c_str());
        a.push_back(aw);
        Cmd* aa = new Cmd(a);
        
        strcpy(bw, node_vector.at(cur_pos + 1).c_str());
        b.push_back(bw);
        Cmd* bb = new Cmd(b);
        
		And* contr_and = new And(aa, bb);
        theonethatleft.push_back(contr_and);
        node_vector.erase(node_vector.begin()+cur_pos+1);
        node_vector.erase(node_vector.begin()+cur_pos-1);
        cur_pos--;
	}
	else { //command
        strcpy(aw, node_vector.at(cur_pos).c_str());
        a.push_back(aw);
        
		Cmd* cmd_node = new Cmd(a);
        theonethatleft.push_back(cmd_node);
	}
    return populate(node_vector,theonethatleft, cur_pos+1);   
}
*/



vector<string> parse_arg(string &allArg){
    vector<string> cmds;
    string cmdline = allArg;
    string temp = "";
    string tempsymb = "";
  //  int find_semi = 0;
  //  int find_or = 0;
  //  int find_and = 0;
    while(cmdline != ""){
//        find_semi = cmdline.find(";");
//        find_or = cmdline.find("||");
//        find_and = cmdline.find("&&");
        
	cout << cmdline << endl;
        if(cmdline.find(";") == string::npos && cmdline.find("||") == string::npos && cmdline.find("&&") == string::npos){
            	temp = cmdline;
            	tempsymb = "";
            	cmdline = "";
	   	cmds.push_back(temp);
        }
        else{
		size_t found_semi = cmdline.find(";");
		if (found_semi != string::npos) {
			string first = cmdline.substr(0,found_semi);
			__parse_arg(first, cmds);
			cmds.push_back(";");
			string second = cmdline.substr(found_semi + 1, cmdline.size());
			//__parse_arg(second, cmds);	
			cmdline = second;
		}
		else {
			__parse_arg(cmdline, cmds);
		}

        }
    }
 //   vector<Rshell *> leaves;
  //  Rshell * bob = populate(cmds, leaves, 0);
  //  bob->exec();
   // cmds.pop_back();
    //change cmds into a vector of rshell *
    return cmds;
    
}    
    
    
    //populate my tree
   /* for(int i = 0; !cmds.empty(); i++){
        string curr = cmds.at(i);
        if( curr == ";" || curr == "||" || curr == "&&"){
            Connector *contr(
        }
    }*/
	
int main() 
{
	string user_input;
	string quit = "exit";
	//char *cmd_arr[64]r
	stack<string> infix;
	stack<string> tree;
	size_t  pos;
	vector<string> cmds;

	//keeps looping until user types in keyword: exit	
	while (true)	
	{
		cout << "$ ";
		getline(cin, user_input);

		if (user_input.find('#') != string::npos)
		{
       	    		pos = user_input.find('#');
			user_input = user_input.substr(0,pos);
		}

		if (user_input.compare(quit) == 0)
		{
			exit(0);
		}
		
		else 
		{
			cmds = parse_arg(user_input);
		}
		
		for (unsigned int i = 0; i < cmds.size(); ++i) 
		{
			if (cmds.at(i) != ";" || cmds.at(i) != "&&" || cmds.at(i) != "||") 
			{
				infix.push(cmds.at(i));
			}

			else 
			{
				if (infix.size() == 2) 
				{
					Cmd *leaf_left = new Cmd(infix.top().c_str());
					infix.pop();
					Cmd *leaf_right = new Cmd(infix.top().c_str());
					infix.pop();
					
					//construct the type of connector and assign its children and push to tree stack
					if (cmds.at(i) == ";") 
					{
						//instantiate semi
						Semi *semi_connector = new Semi(leaf_left, leaf_right);
					}
					
					else if (cmds.at(i) == "&&") 
					{
						//instantiate and
						And *and_connector = new And(leaf_left, leaf_right);
					}
					
					else
					{
						//instantiate or
						Or *or_connector = new Or(leaf_left, leaf_right);



					}

				}
				
				else {
					infix.push(cmds.at(i + 1));
					tree.push(cmds.at(i));
					tree.push(infix.top());
					infix.pop();
					tree.push(infix.top());
					infix.pop();
				}
			}
	}
	

	return 0;
}
