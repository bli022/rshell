#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <algorithm>

#include "rshell.h"
#include "and.h"
#include "semi.h"
#include "or.h"
#include "cmd.h"


using namespace std;

struct node{
    Rshell *value;
    Rshell *left;
    Rshell *right;
};


void parse_arg(string &allArg){
    //stringstream ss(allArg);
    //char par_arg[BUFSIZ];
   /* while(ss >> par_arg){
       //FIXME parse by semi, and then or 
        char * cur_par = new char[BUFSIZ];

        unsigned i = 0;
        for(i = 0; par_arg[i] != '\0'; ++i){
            cur_par[i] = par_arg[i];
        }
        cur_par[i] = '\0';
        *args++ = cur_par;
    }
    *args = 0; */
    
    vector<string> cmds;
    string cmdline = allArg;
    string temp = "";
    string tempsymb = "";
    int mini = 0;
    int find_semi = 0;
    int find_or = 0;
    int find_and = 0;
    while(cmdline != ""){
        find_semi = cmdline.find(";");
        find_or = cmdline.find("||");
        find_and = cmdline.find("&&");
        
        if(cmdline.find(";") == string::npos && cmdline.find("||") == string::npos && cmdline.find("&&") == string::npos){
            temp = cmdline;
            tempsymb = "";
            cmdline = "";
        }
        else{
            mini = min(find_semi,min(find_or,find_and));
            if(mini == find_or || mini == find_and){
                temp = cmdline.substr(0,mini);
                tempsymb = cmdline.substr(mini, mini+2);
                cmdline = cmdline.substr(mini+2);
            }
            else{
                temp = cmdline.substr(0,mini);
                tempsymb = cmdline.substr(mini, mini+1);
                cmdline = cmdline.substr(mini+1);
            }
        }
        cmds.push_back(temp);
        cmds.push_back(tempsymb);
    }
   // cmds.pop_back();
    //change cmds into a vector of rshell *
    
    
}    
    
    
    //populate my tree
   /* for(int i = 0; !cmds.empty(); i++){
        string curr = cmds.at(i);
        if( curr == ";" || curr == "||" || curr == "&&"){
            Connector *contr(
        }
    }*/
	
	//convert strings to rshell classes
	//return: rshell ptr
	//parameter: vector<strings>
Rshell* populate(vector<string> node_vector, vector<Rshell*> theonethatleft,  int cur_pos) {
    
    if(node_vector.size() == 1){
        char* aw; 
        strcpy(aw, node_vector.at(0));
        int sizer = theonethatleft.size();
        for(int i = 2; i < sizer; i=i+2){
            theonethatleft.at(i)->left = theonethatleft.at(i-2);
            theonethatleft.at(i)->right = theonethatleft.at(i-1);
            theonethatleft.erase(theonethatleft.begin()+i-2);
            theonethatleft.erase(theonethatleft.begin()+i-1);
            sizer -= 2;
        }
    }
	else if (node_vector.at(cur_pos) == ";") {
	//left and right: check curpos -1 in the vector
	//if cur_pos -1 is Command: call Command constructor
	//else populate(vector<string>, cur_pos-1)
        vector<char *> a;
        char* aw; 
        strcpy(aw, node_vector.at(cur_pos - 1).c_str());
        a.push_back(aw);
        Cmd* aa = new Cmd(a);
        
        vector<char *> b;
        char* bw;
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
        vector<char *> a;
        char* aw; 
        strcpy(aw, node_vector.at(cur_pos - 1).c_str());
        a.push_back(aw);
        Cmd* aa = new Cmd(a);
        
        vector<char *> b;
        char* bw;
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
        vector<char *> a;
        char* aw; 
        strcpy(aw, node_vector.at(cur_pos - 1).c_str());
        a.push_back(aw);
        Cmd* aa = new Cmd(a);
        
        vector<char *> b;
        char* bw;
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
        vector<char *> a;
        char* aw; 
        strcpy(aw, node_vector.at(cur_pos).c_str());
        a.push_back(aw);
        
		Cmd* cmd_node = new Cmd(a);
        theonethatleft.push_back(cmd_node);
	}
    populate(node_vector,theonethatleft, cur_pos+1);
}

int main() 
{
	string user_input;
	string quit = "exit";
	//char *cmd_arr[64];
	bool run = true;
	size_t  pos;

	//keeps looping until user types in keyword: exit	
	while (run)	
	{
		cout << "$ ";
		getline(cin, user_input);
		
		if (user_input.find('#') != 0)
		{
            pos = user_input.find('#');
			user_input = user_input.substr(0, pos+1);
		}

		if (user_input.compare(quit) == 0)
		{ 
			cout << "in exit statement" << endl;
			exit(0);
		}
		
		else 
		{
			parse_arg(user_input);
		}

	}
	

	return 0;
}
