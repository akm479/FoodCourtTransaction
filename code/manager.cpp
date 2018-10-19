#include<bits/stdc++.h>
using namespace std;
#include "employee.h"
#include "manager.h"     
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <string>
manager:: manager(){
type=M;

}

void manager::push_back_manager_data(){

}

void manager::remove_receptionist(){

        vector<string>text_name;vector<string>text_username;vector<string>text_password;vector<int> salary;
         ifstream input;
         input.open("receptionist.txt");
         while(!input.eof()){
            string a,b,c;
            int s;

            input>>a>>b>>c>>s;
		if(a.size()==0)break;
                text_name.push_back(a);
                text_username.push_back(b);
                text_password.push_back(c);
                salary.push_back(s);
                 
         }


         bool flag=false;  string a;
         while(!flag){
                system("clear");
             cout<<"Enter the username of the receptionist to be deleted ";
             cin>>ws;
             getline(cin,a);
             cin.clear();
             bool condition=true;
             for(int i=0;i<a.size();i++){
                            if(a[i]==' '){
                                condition=false;
                                break;
                            }
             }
             if(condition){
                flag=true;
             }

            else{
                system("clear");
                cout<<"username should not contain spaces "<<endl;
                for(int i=0;i<1000000000;i++){

                }system("clear");

                continue;
            }
         }
         bool found = false;
        for(int i=0;i<text_username.size();i++){
                if(text_username[i]==a){
                    found=true;
                }
        }
        if(found){
        ofstream output;
        output.open("receptionist.txt");
        for(int i=0;i<text_name.size();i++){
                if(a!=text_username[i] && i!=text_name.size()-1)
                output<<text_name[i]<<" "<<text_username[i]<<" "<<text_password[i]<<" "<<salary[i]<<endl;
                else {
                    if(a!=text_username[i] && i==text_name.size()-1)
                        output<<text_name[i]<<" "<<text_username[i]<<" "<<text_password[i]<<" "<<salary[i];
                }
        }
        output.close();
        system("clear");
        cout<<"Receptionist removed "<<endl;
        for(int i=0;i<1000000000;i++){

        }system("clear");
        }
        else {
                system("clear");
            cout<<"The username does not exists "<<endl;
        for(int i=0;i<1000000000;i++){

        }system("clear");
        }

}

void manager::show_receptionist(){
    cout<<"The list of receptionists is loading, Please Wait...."<<endl;
for(int i=0;i<2000000000;i++){

}
system("clear");

cout<<setw(15);cout<<endl;
cout<<"NAME";cout<<setw(15);
cout<<"Username";cout<<setw(15);
cout<<"Password";cout<<setw(20);
cout<<"total income(Rs)";cout<<setw(15);
cout<<endl;cout<<endl;
cout<<setw(15);cout<<"----------------------------------------------------------------------";cout<<endl;
ifstream input;
input.open("receptionist.txt");
while(!input.eof()){
        string a,b,c;int d;
    input>>a>>b>>c>>d;
cout<<setw(15);
   if(a.size()==0)break;
    cout<<a;cout<<setw(15);
    cout<<b;cout<<setw(15);
    cout<<c;cout<<setw(15);
    cout<<d;cout<<setw(15);
    cout<<endl;
 


}
cout<<setw(15);cout<<"----------------------------------------------------------------------";
input.close();
cin.ignore();
}

void manager::add_receptionist(){
    bool flag=false;
    while(!flag){
        system("clear");
        string a,b,c;

        cout<<"Enter the name of the receptionist to be hired (all characters should be in capital letters) ";
        cin>>ws;
        getline(cin,a);
        cin.clear();

        bool condition1=true;
                    for(int i=0;i<a.size();i++){
                        if(a[i]<65 || a[i]>90 || a[i]==' '){
                            condition1=false;
                            break;
                        }
                    }
        if(!condition1){
            flag=false;
        }
        else{

            cout<<"Enter the username for the account of the receptionist(should not contain spaces ) ";
            cin>>ws;
            getline(cin,b);
            cin.clear();
          bool condition2=true;
                    for(int i=0;i<b.size();i++){
                        if(b[i]==' '){
                            condition2=false;
                            break;
                        }
                    }
            if(!condition2){
                flag=false;
            }
            else{
                cout<<"Enter the password for the account of the receptionist(should not contain spaces) ";

               c =  getpass("Enter Password",true);
              bool condition3=true;
                        for(int i=0;i<c.size();i++){
                            if(c[i]==' '){
                                condition3=false;
                                break;
                            }
                        }
                if(!condition3){
                    flag=false;
                }
                else flag=true;

            }
        }

        cin.clear();
        vector<string>text_name;vector<string>text_username;vector<string>text_password;vector<int> salary;
         ifstream input;
         input.open("receptionist.txt");
         while(true){
            string n,u,p;
            int s=-1;
       
            input>>n>>u>>p>>s;
     		if( n.size()==0 ) break;
                text_name.push_back(n);
                text_username.push_back(u);
                text_password.push_back(p);
                salary.push_back(s);
		


         } bool condition = true;
            for(int i=0;i<text_name.size();i++){
                if(b==text_username[i]){
                    condition=false;
                }
            }
            if(condition && flag){


                text_name.push_back(a);
                text_username.push_back(b);
                text_password.push_back(c);
                salary.push_back(0);

            input.close();

        ofstream output;
        output.open("receptionist.txt");
        for(int i=0;i<text_name.size();i++){
                if(i==text_name.size()-1){
                     output<<text_name[i]<<" "<<text_username[i]<<" "<<text_password[i]<<" "<<salary[i];
                }

            else output<<text_name[i]<<" "<<text_username[i]<<" "<<text_password[i]<<" "<<salary[i]<<'\n';
        }
        output.close();
         

  system("clear");
    cout<<"Congrats you have just hired a receptionist..."<<endl;
    for(int i=0;i<1000000000;i++){
    }
system("clear");
    }
    else{
            flag=false;system("clear");
        cout<<"You have entered a existing username or the name,password entered is not in correct form,please enter again..."<<endl;
        for(int i=0;i<2000000000;i++){

        }system("clear");

    }
    }
}
