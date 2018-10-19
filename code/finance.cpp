#include <bits/stdc++.h>
using namespace std;
#include "finance.h"

finance :: finance(){
    ifstream input1;
    input1.open("cost.txt");
    while(!input1.eof()){
       int a;
       input1>>a;
       cost.push_back(a);
    }
    ifstream input;
        time_t t =  time(0);
      tm* now =  localtime(&t);
      int  year =  (now->tm_year + 1900);
      int month = (now->tm_mon + 1);
     stringstream ss;
    ss << year;
    string y=ss.str();

    stringstream ss1;
    ss1 << month;
    string m=ss1.str();

     y=m+"-"+y+".txt";
    input.open(y.c_str());
    if(input.good()){

     while(!input.eof()){
        string a;int c,d,e;
        input>>a>>c>>d>>e;

		if(a.size()==0)break;
        item_id.push_back(c);
        item_count.push_back(d);
        item_selling_price.push_back(e);
    }

    }
    else{
        ofstream output;
        output.open(y.c_str());
        output.close();
    }

}

void finance::push_back_finance_data(){

}
void finance::show_profit(){
    system("clear");
   ifstream input1;
    input1.open("cost.txt");
    while(!input1.eof()){
       int a;
       input1>>a;
       cost.push_back(a);
    }
     time_t t =  time(0);
      tm* now =  localtime(&t);
      int  year =  (now->tm_year + 1900);
      int month = (now->tm_mon + 1);
     stringstream ss;
    ss << year;
    string y=ss.str();

    stringstream ss1;
    ss1 << month;
    string m=ss1.str();

     y=m+"-"+y+".txt";
    ifstream input;

    input.open(y.c_str());int local_profit=0;
     while(!input.eof()){
        string a;int c,d,e=0;
        input>>a>>c>>d>>e;
	if(a.size()==0)break;
       local_profit+=(e-cost[c])*d;
      /*  item_id.push_back(c);
        item_count.push_back(d);
        item_selling_price.push_back(e);*/
    }
    profit = local_profit;

cout<<"The total profit earned is: Rs "<<profit<<endl;
cin.ignore();
}
void finance::add_sale(vector<int>&price,vector<int>&id,vector<int>&){

}
int finance::get_cost(){

}


void finance::add_cost(int new_cost){
 

cost.push_back(new_cost);
ofstream output;
output.open("cost.txt",ios::app);
output<<new_cost<<endl;

}




void finance::delete_cost(){

}
void finance::show_report(){
    system("clear");
        time_t t =  time(0);
      tm* now =  localtime(&t);
      int date = (now->tm_mday);
      int  year =  (now->tm_year + 1900);
      int month = (now->tm_mon + 1);
     stringstream ss;
    ss << year;
    string y=ss.str();

    stringstream ss1;
    ss1 << month;
    string m=ss1.str();

     y=m+"-"+y+".txt";
    ifstream input;
    input.open(y.c_str());
    cout<<endl;
    cout<<setw(15);
          cout<<"                       ";
    cout<<"THAR OASIS RESTAURANT ";cout<<setw(15);cout<<endl;cout<<endl;cout<<"                       ";

    cout<<"MONTHLY REPORT ("<<date<<"/"<<month<<"/"<<year<<")";cout<<endl;

        cout<<endl;cout<<endl;
    cout<<setw(15);

    cout<<"Name";cout<<setw(15);
    cout<<"Type";cout<<setw(15);
    cout<<"Quantity";cout<<setw(15);
    cout<<"Price(Rs)";cout<<setw(15);
    cout<<endl;
    cout<<setw(15);cout<<"--------------------------------------------------------------------------";cout<<endl;

    while(!input.eof()){
        string a;int b,c,d=0;
        input>>a>>b>>c>>d;
        cout<<setw(15);
	if(a.size()==0)break;
        cout<<a;cout<<setw(15);
        cout<<b;cout<<setw(15);
        cout<<c;cout<<setw(15);
         cout<<d;cout<<setw(15);cout<<endl;

    }
 cout<<setw(15);cout<<"--------------------------------------------------------------------------";cout<<endl;

cin.ignore();
}

