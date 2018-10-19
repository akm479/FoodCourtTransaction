 #include <bits/stdc++.h>
using namespace std;
 #include "menu.h"

 void menu::show_menu(){
    system("clear");
    ifstream input;
    cout<<"               ";
    cout<<"THAR OASIS RESTAURANT MENU";
        cout<<endl;cout<<endl;
    cout<<setw(15);
    input.open("menu.txt");
    cout<<"Name";cout<<setw(15);
    cout<<"Type";cout<<setw(15);
    cout<<"Price(Rs)";cout<<setw(15);
    cout<<endl; cout<<setw(15);cout<<"--------------------------------------------------------------------------";cout<<endl;
    cout<<setw(15);
    while(!input.eof()){
        string a;int b,c,d ;
        input>>a>>b>>c>>d ;
	if(a.size()==0)break;
        cout<<a;cout<<setw(15);
        cout<<b;cout<<setw(15);
        cout<<c;cout<<setw(15);
        cout<<endl;
    }
     cout<<setw(15);cout<<"--------------------------------------------------------------------------";cout<<endl;
   cin.ignore();


 }
void menu::setter(string a,int b,int c){

    name.push_back(a);
    type.push_back(b);
    price.push_back(c);

}
vector<string> menu::get_name(){
return name;
}
vector<int> menu::get_type(){
return type;
}
vector<int> menu::get_price(){
return price;
}
