#include "application.h"
#include "receptionist.h"
#include "employee.h"
#include "manager.h"
#include<bits/stdc++.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
 
void application::start(){
    string entry;


    while(entry[0]!='9'){
            system("clear");

        cout<<"1. Login as Receptionist \n";
        cout<<"2. Login as Manager \n";
        cout<<"9. Exit \n";
        cout<<"Enter the above shown numbers to proceed ";
        cin>>ws;
        getline(cin,entry);

        if(entry[0]=='1' && entry.size()==1){
            receptionist_page();
            continue;
        }
        if(entry[0]=='2' && entry.size()==1){
            manager_page();
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
void application::manager_page(){
    system("clear");
    bool flag = true;
           string username;string password;
           string name;

           manager m;
    while(flag){

        bool condition=false;

        string correct_username;string correct_password;

        cout<<"Enter username\n";
        cin>>ws;
        cin.clear();
        getline(cin,username);
        password =  m.getpass("Enter Password",true);


        ifstream input;
        input.open("manager.txt");

        while(!input.eof()){
            input>>name>>correct_username>>correct_password;
            if(correct_password==password && correct_username==username){
                condition=true;
                break;
            }
        }

        if(condition){
            flag =false;
            system("clear");
        }
        else {
            system("clear");
        }
        input.close();
    }
    string entry;
    while(entry[0]!='9'){
            system("clear");
        cout<<"0. View profit \n";
        cout<<"1. Add receptionist \n";
        cout<<"2. Remove receptionist \n";
        cout<<"3. Show receptionist list \n";
        cout<<"4. View report \n";
        cout<<"5. View menu \n";
        cout<<"6. View stock \n";
        cout<<"7. Change details \n";
        cout<<"8. Update Stock \n";
        cout<<"9. Logout \n";
        cout<<"Enter the above shown numbers to proceed ";
        cin>>ws;
        getline(cin,entry);
        if(entry[0]=='1' && entry.size()==1){
            system("clear");
            m.add_receptionist();
            continue;
        }
        if(entry[0]=='2' && entry.size()==1){
            system("clear");
            m.remove_receptionist();
            continue;
        }
        if(entry[0]=='3' && entry.size()==1){
             system("clear");
            m.show_receptionist();
            continue;
        }
        if(entry[0]=='4' && entry.size()==1){
                f.show_report();
            continue;
        }
        if(entry[0]=='5' && entry.size()==1){
            s.show_menu();
                continue;
        }
        if(entry[0]=='6' && entry.size()==1){
                s.show_stock();
            continue;
        }
        if(entry[0]=='7' && entry.size()==1){
            m.change_details(name,username,password);
            continue;
        }
        if(entry[0]=='8' && entry.size()==1){
            bool flag=false;
            int add=s.update_stock(flag);
            if(flag){
                f.add_cost(add);
            }
            continue;
        }
        if(entry[0]=='0' && entry.size()==1){
            f.show_profit();
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
void application::receptionist_page(){
    system("clear");

  receptionist r;int total_salary=0;
          string username;string password;

          string name;
  bool flag = true;
    while(flag){

        bool condition=false;
        int total_income;

        string correct_username;string correct_password;

        cout<<"Enter username\n";
        cin>>ws;
        cin.clear();
        getline(cin,username);
    	 password =  r.getpass("Enter Password",true);
        ifstream input;
        input.open("receptionist.txt");

        while(!input.eof()){
            input>>name>>correct_username>>correct_password>>total_income;
            if(correct_password==password && correct_username==username){

                condition=true;
                total_salary=total_income;
                break;
            }

        }
        if(condition){
            flag = false;
            system("clear");
        }
        else {
            system("clear");
        }
        input.close();
    }
    string entry;
    while(entry[0]!='9'){
            system("clear");
        cout<<"1. Take order \n";
        cout<<"2. View menu \n";
        cout<<"3. View salary\n";
        cout<<"4. Change details \n";
        cout<<"9. Logout \n";
        cout<<"Enter the above shown numbers to proceed ";
        cin>>ws;
        getline(cin,entry);
        if(entry[0]=='1' && entry.size()==1){
           int add = s.take_order();
                r.add_salary(add);
                total_salary+=add;
                ifstream input;
                input.open("receptionist.txt");

                vector<string> r_name;vector<string> r_username;vector<string> r_password;vector<int> salary;
                while(!input.eof()){
                    string a,b,c;int d;
                    input>>a>>b>>c>>d;
		     if(a.size()==0)break;
                    r_name.push_back(a);
                    r_username.push_back(b);
                    r_password.push_back(c);
                    salary.push_back(d);
                    
                }
                ofstream output;
                output.open("receptionist.txt");
                for(int i=0;i<r_name.size();i++){
                    if(username==r_username[i]){salary[i]+=add;}
                    if(i!=r_name.size()-1)
                    output<<r_name[i]<<" "<<r_username[i]<<" "<<r_password[i]<<" "<<salary[i]<<endl;
                    else output<<r_name[i]<<" "<<r_username[i]<<" "<<r_password[i]<<" "<<salary[i];
                }
                continue;
        }
        if(entry[0]=='2' && entry.size()==1){
                s.show_menu();
                continue;
        }
        if(entry[0]=='3' && entry.size()==1){
            system("clear");
            r.view_salary(total_salary);
            continue;
        }
        if(entry[0]=='4' && entry.size()==1){
            system("clear");
            r.change_details(name,username,password);
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
