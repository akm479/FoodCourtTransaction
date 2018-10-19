#include<bits/stdc++.h>
#include "employee.h"
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int employee::getch() {
    int ch;
    struct termios t_old, t_new;

    tcgetattr(STDIN_FILENO, &t_old);
    t_new = t_old;
    t_new.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t_new);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &t_old);
    return ch;
}





string employee::getpass(const char *prompt, bool show_asterisk=true)
{
  const char BACKSPACE=127;
  const char RETURN=10;

  string password;
  unsigned char ch=0;

  cout <<prompt<<endl;

  while((ch=getch())!=RETURN)
    {
       if(ch==BACKSPACE)
         {
            if(password.length()!=0)
              {
                 if(show_asterisk)
                 cout <<"\b \b";
                 password.resize(password.length()-1);
              }
         }
       else
         {
             password+=ch;
             if(show_asterisk)
                 cout <<'*';
         }
    }
  cout <<endl;
  return password;
}
void employee::change_details(string a,string b,string c){

    if(type == R){
            ifstream input;
            name = a;
            username = b;
            password = c;
            vector<string> text_name;vector<string>text_username;vector<string>text_password;vector<int>salary;
            input.open("receptionist.txt");
            while(!input.eof()){
                string n,u,p;
                int s;
                input>>n>>u>>p>>s;
		if(n.size()==0)break;
                text_name.push_back(n);
                text_username.push_back(u);
                text_password.push_back(p);
                salary.push_back(s);
            }
            input.close();
            string entry;
        while(entry[0]!='9'){
            system("clear");
            cout<<"1. Change name \n";
            cout<<"2. Change password \n";
            cout<<"9. Exit \n";
            cout<<"Enter any of the above numbers to continue ";
            cin>>ws;
            getline(cin,entry);
            if(entry[0]=='1' && entry.size()==1){
                    bool flag =false;
                while(!flag){
                        system("clear");
                    string s;
                    cout<<"Enter new name(all characters should be capital and there should be no space): ";
                   cin>>ws;
                   getline(cin,s);

                    bool condition=true;
                    for(int i=0;i<s.size();i++){
                        if(s[i]<65 || s[i]>90 || s[i]==' '){
                            condition=false;
                            break;
                        }
                    }
                    if(condition){
                        flag=true;
                        name = s;
                        for(int i=0;i<text_name.size();i++){
                            if(username==text_username[i]){
                                text_name[i]=s;
                                break;
                            }
                        }
                        ofstream output;



                            output.open("receptionist.txt");
                            for(int i=0;i<text_name.size();i++){
                                if(i!=text_name.size()-1)
                            output<<text_name[i]<<" "<<text_username[i]<<" "<<text_password[i]<<" "<<salary[i]<<'\n';
                            else output<<text_name[i]<<" "<<text_username[i]<<" "<<text_password[i]<<" "<<salary[i];
                            }
                            output.close();
                        cout<<"Changes have been made...."<<endl;
                        for(int i=0;i<1000000000;i++){

                        }
  			system("clear");
                    }
                    else{
                            
                        cout<<"Enter name in prescribed format "<<endl;
                        for(int i=0;i<1000000000;i++){

                        }
			  system("clear");
                    }
                }
                continue;
            }
            if(entry[0]=='2' && entry.size()==1){
                bool flag =false;
                while(!flag){
                    system("clear");
                    string s;
                    
                    s =  getpass("Enter new Password",true);
                    bool condition=true;
                    for(int i=0;i<s.size();i++){
                        if(s[i]==' '){
                            condition=false;
                            break;
                        }
                    }
                    if(condition){
                        flag=true;
                        password = s;
                        for(int i=0;i<text_name.size();i++){
                            if(username==text_username[i]){
                                text_password[i]=s;
                                break;
                            }
                        }

                        ofstream output;

                        output.open("receptionist.txt");
                        for(int i=0;i<text_name.size();i++){
                            if(i!=text_name.size()-1)
                            output<<text_name[i]<<" "<<text_username[i]<<" "<<text_password[i]<<" "<<salary[i]<<'\n';
                            else output<<text_name[i]<<" "<<text_username[i]<<" "<<text_password[i]<<" "<<salary[i];
                        }
                        output.close();
                        cout<<"Changes have been made...."<<endl;
                        for(int i=0;i<1000000000;i++){

                        }  system("clear");
                    }
                    else{
                              
                        cout<<"Password should not contain spaces... "<<endl;
                        for(int i=0;i<1000000000;i++){

                        }  system("clear");
                    }
                }
                continue;
            }
         if(entry[0]!='9'){
             cin.clear();


         }
         if(entry[0]=='9' && entry.size()!=1){
            cin.clear();
            entry.clear();
         }
        }

    }
    else{
            ifstream input;
            name = a;
            username = b;
            password = c;
            vector<string> text_name;vector<string>text_username;vector<string>text_password;
            input.open("manager.txt");
            while(!input.eof()){
                string n,u,p;

                input>>n>>u>>p;
		if(n.size()==0){
			break;		
		}
                text_name.push_back(n);
                text_username.push_back(u);
                text_password.push_back(p);

            }
            input.close();
            string entry;
        while(entry[0]!='9'){
            system("clear");
            cout<<"1. Change name \n";
            cout<<"2. Change password \n";
            cout<<"9. Exit \n";
            cout<<"Enter any of the above numbers to continue ";
            cin>>ws;
            getline(cin,entry);
            if(entry[0]=='1' && entry.size()==1){
                    bool flag =false;
                while(!flag){
                        system("clear");
                    string s;
                    cout<<"Enter new name(all characters should be capital): ";
                    cin>>ws;
                    getline(cin,s);
                    bool condition=true;
                    for(int i=0;i<s.size();i++){
                        if(s[i]<65 || s[i]>90 || s[i]==' '){
                            condition=false;
                            break;
                        }
                    }
                    if(condition){
                        flag=true;
                        name = s;
                        for(int i=0;i<text_name.size();i++){
                            if(username==text_username[i]){
                                text_name[i]=s;
                                break;
                            }
                        }
                        ofstream output;


                            output.open("manager.txt");
                            for(int i=0;i<text_name.size();i++){
                               if(i!=text_name.size()-1)
                            output<<text_name[i]<<" "<<text_username[i]<<" "<<text_password[i]<<'\n';
                            else output<<text_name[i]<<" "<<text_username[i]<<" "<<text_password[i];
                            }
                            output.close();
                        cout<<"Changes have been made...."<<endl;
                        for(int i=0;i<1000000000;i++){

                        }  system("clear");
                    }
                    else{
                            system("clear");
                        cout<<"Enter name in prescribed format "<<endl;
                        for(int i=0;i<1000000000;i++){

                        }  system("clear");
                    }
                }
                continue;
            }
            if(entry[0]=='2' && entry.size()==1){
                bool flag =false;
                while(!flag){
                    system("clear");
                    string s;
                   s =  getpass("Enter new Password",true);
                    bool condition=true;
                    for(int i=0;i<s.size();i++){
                        if(s[i]==' '){
                            condition=false;
                            break;
                        }
                    }
                    if(condition){
                        flag=true;
                        password = s;
                        for(int i=0;i<text_name.size();i++){
                            if(username==text_username[i]){
                                text_password[i]=s;
                                break;
                            }
                        }
                        ofstream output;


                        output.open("manager.txt");
                        for(int i=0;i<text_name.size();i++){
                            if(i!=text_name.size()-1)
                            output<<text_name[i]<<" "<<text_username[i]<<" "<<text_password[i]<<'\n';
                            else output<<text_name[i]<<" "<<text_username[i]<<" "<<text_password[i];
                        }
                        output.close();
                        cout<<"Changes have been made...."<<endl;
                        for(int i=0;i<1000000000;i++){

                        }system("clear");
                    }
                    else{
                            system("clear");
                        cout<<"Password should not contain spaces... "<<endl;
                        for(int i=0;i<1000000000;i++){

                        }system("clear");
                    }
                }
                continue;
            }
        if(entry[0]!='9'){
             cin.clear();


        }
        if(entry[0]=='9' && entry.size()!=1){
            cin.clear();
            entry.clear();
        }
        }
    }

}
