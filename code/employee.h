
#include<bits/stdc++.h>
using namespace std;
#ifndef _employee_H_
#define _employee_H_

class employee
{

string name;
string username;
string password;
public:
    enum Empl_type{M,R};
     Empl_type type;
    void change_details(string a,string b,string c);
	 int getch();
   string getpass(const char *prompt, bool show_asterisk);
};

#endif

