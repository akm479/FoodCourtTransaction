#include"stock.h"
#include "menu.h"
#include "billing.h"
#include<bits/stdc++.h>
using namespace std;


 stock :: stock(){
    ifstream input;
    input.open("menu.txt");
    while(!input.eof()){
        string a;int b,c,d ;
        input>>a>>b>>c>>d ;
	if(a.size()==0)break;
        setter(a,b,c);         
        quantity.push_back(d);
        
    }


}
int stock::lcs(string X,string Y,int m,int n){

   int L[m+1][n+1];
   int i, j;


   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;

       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;

       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }


   return L[m][n];

}





void stock::push_back_stock_data(string new_item,int new_type,int new_price,int new_quantity){
ofstream output;
output.open("menu.txt");
vector<string>stock_name = get_name();
vector<int>stock_type = get_type();
vector<int>stock_price = get_price();

for(int i=0;i<stock_name.size();i++){
    if(i!=stock_name.size()-1)
        output<<stock_name[i]<<" "<<stock_type[i]<<" "<<stock_price[i]<<" "<<quantity[i]<<endl;
    else  output<<stock_name[i]<<" "<<stock_type[i]<<" "<<stock_price[i]<<" "<<quantity[i];
}

}

int stock::update_stock(bool& choice){
  label: system("clear");
    cout<<"Press Y if you want to add item and press N to delete item ";
    string option;
    cin>>ws;
    getline(cin,option);cin.clear();
string new_cost;long long int new_new_type=0;long long int new_new_price=0;long long int new_new_cost=0;
    if(option[0]=='Y' && option.size()==1){
            choice=true;
            string new_item;
        bool flag=false;
      while(!flag){
        system("clear");
        cout<<"Enter the name of the item to be added ";

        cin>>ws;
        getline(cin,new_item);
        ifstream input;bool match=false;
        input.open("menu.txt");
        while(!input.eof()){
            string a;int b,c,d;
            input>>a>>b>>c>>d;
            if(a==new_item){
                match=true;
            }
        }
        bool condition=true;
        for(int i=0;i<new_item.size();i++){
            if(new_item[i]==' '){condition=false;}
        }

        if(condition){
                flag=true;

        }
        else{
            system("clear");

                cout<<"Item name should not contain spaces "<<endl;
                for(int i=0;i<1000000000;i++){

                }  system("clear");
        }
        if(match){
            flag=false;
            system("clear");
            cout<<"Item already exists "<<endl;
            for(int i=0;i<1000000000;i++){

            }  system("clear");
        }

      }
    string new_type;
        while(true){
      label2:system("clear");
        cout<<"Enter the type of the item (either 0 or 1) ";
        cin>>ws;
       getline(cin,new_type);

            if(new_type[0]=='0' || new_type[0]=='1'){
                    if(  new_type.size()==1){

                    stringstream geek(new_type);
                geek>>new_new_type; break;}

                else{
                     goto label2;
                 cin.clear();
                }
            }
            else{
                    goto label2;
                 cin.clear();

            }
        }
 string new_price;
        while(true){
        label3:system("clear");
        cout<<"Enter the selling price of the item ";
            cin>>ws;
       getline(cin,new_price);bool condition = true;
        for(int i=0;i<new_price.size();i++){
            if(new_price[i]<48 || new_price[i]>57){
                condition = false;
            }
        }
        if(condition){
            if(new_price.size()>18){
                cout<<"Out of bound "<<endl;
                for(int i=0;i<1000000000;i++){

                }  system("clear");
                goto label3;
            }
            stringstream geek(new_price);
            geek>>new_new_price;

            if(new_new_price>0){

                    break;
            }
        }
            else{
                  cout<<"Price should be positive integer "<<endl;
                    for(int i=0;i<1000000000;i++){}  system("clear");
                goto label3;
                cin.ignore();
                cin.clear();
            }
        }
        long long int new_new_quantity=0;
        string new_quantity;
        while(true){
       label4: system("clear");
        cout<<"Enter the quantity of the item ";
        cin>>ws;
        getline(cin,new_quantity);
        bool condition = true;
        for(int i=0;i<new_quantity.size();i++){
            if(new_quantity[i]<48 ||new_quantity[i]>57 ){
                condition = false;
            }
        }
        if(condition){
            if(new_quantity.size()>18){
                    cout<<"Out of bound "<<endl;
                    for(int i=0;i<1000000000;i++){

                    }  system("clear");
                goto label4;
            }
            stringstream geek(new_quantity);
            geek>>new_new_quantity;


            if(new_new_quantity>0){break;}
            else{
                if(new_new_quantity<=0){
                    cout<<"quantity can't be less than 1 "<<endl;
                    for(int i=0;i<1000000000;i++){

                    }  system("clear");
                }}
                }
                else{
                        goto label4;
                    cin.ignore();
                    cin.clear();
                }

        }

        while(true){
       label5: system("clear");
        cout<<"Enter the cost of the item ";
        cin>>ws;
        getline(cin,new_cost);
        bool condition = true;
        for(int i=0;i<new_cost.size();i++){
            if(new_cost[i]<48 || new_cost[i]>57){
                condition = false;
            }
        }
        if(condition){
            if(new_cost.size()>18){
                    cout<<"Out of bound "<<endl;
                    for(int i=0;i<1000000000;i++){

                    }  system("clear");
                goto label5;
            }
         stringstream geek(new_cost);
         geek>>new_new_cost;

            if(new_new_price>new_new_cost){break;}
            else{
                if(new_new_price<new_new_cost){
                    cout<<"price can't be less than cost ,enter right cost "<<endl;
                    for(int i=0;i<1000000000;i++){

                    }  system("clear");
                }
                }
                }

                else{
                        goto label5;
                    cin.ignore();
                    cin.clear();
                }
            }

        setter(new_item,new_new_type,new_new_price);
        quantity.push_back(new_new_quantity);
        push_back_stock_data(new_item,new_new_type,new_new_price,new_new_quantity);

    }
    else{
        if(option[0]=='N' && option.size()==1){

          string delete_id;
        while(true){
              t:system("clear");
              bool flag=true;
            cout<<"Enter the ID of the item to be deleted or e to exit ";

            cin>>ws;
            getline(cin,delete_id);
            for(int i=0;i<delete_id.size();i++){
                if(delete_id[i]<48 || delete_id[i]>57){
                    if(delete_id[i]!=101){
                        flag=false;
                        break;
                    }
                }
            }
            if(!flag){
                cin.clear();
                delete_id.clear();
            }
            else{
                bool flag1=true;
                for(int i=0;i<delete_id.size();i++){
                    if(delete_id[i]<48 || delete_id[i]>57){
                        flag1=false;
                        break;
                    }
                }
                if(!flag1){
                    if(delete_id[0]=='e' && delete_id.size()==1){
                        cin.clear();
                        delete_id.clear();break;
                    }
                }
                else{
                        if(delete_id.size()>18){
                            cout<<"Out of bound "<<endl;
                            for(int i=0;i<1000000000;i++){

                            }  system("clear");
                            goto t;
                        }
                    stringstream geek(delete_id);
                    long long int x=0;
                    geek>>x;
                    if(x>-1){
                        vector<string> a = get_name();
                        vector<int> b = get_type();
                        vector<int> c = get_price();
                        if(x<a.size())
                        quantity[x]=0;
                        else {
                                cout<<"Out of bound id... "<<endl;
                                for(int i=0;i<1000000000;i++){

                                }  system("clear");
                                goto t;
                        }

                        ofstream output;
                        output.open("menu.txt");
                        for(int i=0;i<a.size();i++){
                            if(i!=a.size()-1){
                                output<<a[i]<<" "<<b[i]<<" "<<c[i]<<" "<<quantity[i]<<endl;
                            }
                            else output<<a[i]<<" "<<b[i]<<" "<<c[i]<<" "<<quantity[i];
                        }



                        break;
                    }
                    else{
                            goto t;

                        cin.clear();
                    }
                }
            }
          }
        }
        else goto label;
    }

return new_new_cost;
}

void stock::show_stock(){
        system("clear");
    ifstream input;
    input.open("menu.txt");

 cout<<endl;
    cout<<setw(15);
          cout<<"                       ";
    cout<<"THAR OASIS RESTAURANT STOCK";cout<<setw(15);cout<<endl;cout<<endl;



        cout<<endl;cout<<endl;
    cout<<setw(15);

    cout<<"Name";cout<<setw(15);
    cout<<"Type";cout<<setw(15);
    cout<<"Price(Rs)";cout<<setw(15);
    cout<<"Quantity";cout<<setw(15);
    cout<<endl;
    cout<<setw(15);cout<<"--------------------------------------------------------------------------";cout<<endl;
cout<<setw(15);
    while(!input.eof()){
           string a;int b,c,d ;
        input>>a>>b>>c>>d ;
	if(a.size()==0)break;
        cout<<a;cout<<setw(15);
        cout<<b;cout<<setw(15);
        cout<<c;cout<<setw(15);
        cout<<d;cout<<setw(15);
        cout<<endl;
    }
     cout<<setw(15);cout<<"--------------------------------------------------------------------------";cout<<endl;
cin.ignore();

}
int stock::take_order(){
    vector<string> stock_name = get_name();
    vector<int> stock_type = get_type();
    vector<int> stock_price = get_price();
    label:
        system("clear");
    cout<<"Press Y to place order with name or N to place order with ID ";
    string choice;
    cin>>ws;
    getline(cin,choice);

    vector<int> order;
    if(choice[0]=='N' && choice.size()==1){


        long long int entry=0;
        while(entry!=-1){
             r:system("clear");
            cout<<"Enter the id of the item or press -1 to exit ";
            string s;
            cin>>ws;
            getline(cin,s);
            bool flag = true;

            for(int i=0;i<s.size();i++){
                if(s[i]<48 || s[i]>57 ){
                        if( s[i]!=45){flag=false;break;}}
            }
            if(!flag){
            //    int lk;cin>>lk;
                goto r;
                cin.clear();
            }
            if(s.size()>18){
                cout<<"Out of bound "<<endl;
                for(int i=0;i<1000000000;i++){

                }system("clear");
                goto r;
            }
            stringstream geek(s);

            geek>>entry;

            if(entry>-1){
                if(stock_name.size()<=entry){
                    cout<<"The entered id doesn't exist "<<endl;
                    for(int i=0;i<1000000000;i++){}
			system("clear");
                }
                else{
                  if(quantity[entry]>0){
                        quantity[entry]--;
                    
                    cout<<"Order has been taken "<<endl;
                    for(int i=0;i<1000000000;i++){

                    }system("clear");
                    order.push_back(entry);
                    continue;
                  }
                  else{
                    cout<<"Entered item is not in stock "<<endl;
                    for(int i=0;i<1000000000;i++){

                    }system("clear");
                  }
                }
            }
            else {
                    if(entry!=-1){
                        cin.clear();
                        cin.ignore();

                    }

            }
        }

    }
    else{
            if(choice[0]=='Y' && choice.size()==1){


               long long int entry=0;

               while(entry!=-1){
                    label1: system("clear");
                     cout<<"Enter the name of the item or press -1 to exit ";
                     string s;
                     cin>>ws;
                     getline(cin,s);bool flag=true;
                        for(int i=0;i<s.size();i++){
                            if(s[i]>=65 && s[i]<=90 || s[i]>=90 && s[i]<=122){
                                flag=false;break;
                            }
                        }
                        if(flag){
                                bool flag1=true;
                                for(int i=0;i<s.size();i++){
                                    if(s[i]<48 || s[i]>57){
                                        if(s[i]!=45)
                                        flag1=false;
                                    }
                                }
                                if(!flag1){
                                cin.clear();
                                s.clear();
                           goto label1; }
                           else{
                            stringstream geek(s);
                            geek>>entry;
                           }

                        }
                        else{




                         ifstream input;
                         input.open("menu.txt");
                         int id=0;bool flag=true;
                         vector<vector<int>> v(stock_name.size(),vector<int>(2));
                         while(!input.eof()){
                            string a;int b,c,d;
                            input>>a>>b>>c>>d;
				if(a.size()==0)break;
                            v[id][1]=id;
                            v[id][0]=lcs(a,s,a.size(),s.size());

                            if(a==s){
                                flag=false;
                                if(quantity[id]<=0){
                                    system("clear");
                                    cout<<"Entered item is out of stock "<<endl;
                                    for(int i=0;i<1000000000;i++){

                                    }system("clear");
                                }
                                else{
                                    quantity[id]--;
                                    order.push_back(id);
                                   
                                    cout<<"Order has been taken"<<endl;
                                    for(int i=0;i<1000000000;i++){

                                    }system("clear");
                                }
                            }
                            id++;
                         }
                         if(flag){
                                name_comparison(order,stock_name,stock_type,stock_price,v);
                         }



                     }
               }

            }
            else {
                 goto label;


            }
    }
    confirm_order(order);




    ///*******************updating stock

    ofstream op;
    op.open("menu.txt");
    for(int i=0;i<stock_name.size();i++){
            if(i!=stock_name.size()-1)
        op<<stock_name[i]<<" "<<stock_type[i]<<" "<<stock_price[i]<<" "<<quantity[i]<<endl;
        else op<<stock_name[i]<<" "<<stock_type[i]<<" "<<stock_price[i]<<" "<<quantity[i];
    }
    op.close();
   ///*************************************
    int salary=0;
    ///***********updating finance
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
    vector<string>finance_name;vector<int> finance_id;vector<int> finance_count;vector<int> finance_price;
    input.open(y.c_str());

    while(!input.eof()){
        string a;int b,c,d;
        input>>a>>b>>c>>d;
        if(a.empty()){

        }
        else{
            finance_name.push_back(a);
            finance_id.push_back(b);
            finance_count.push_back(c);
            finance_price.push_back(d);
        }
        if(input.eof())break;
    }



    for(int i=0;i<order.size();i++){
            bool condition=false;int y=0;bool flag1=true;
        for(int j=0;j<finance_id.size();j++){
            if(order[i]==finance_id[j]){
                flag1=false;y=j;
                if(finance_price[j]==stock_price[order[i]]){
                             finance_count[j]++;
                             salary+=stock_price[order[i]];condition=true;
                             break;
                }



            }

        }
        if(!condition && !flag1){


                    finance_name.push_back(finance_name[y]);
                    finance_id.push_back(order[i]);
                    finance_count.push_back(1);
                    finance_price.push_back(stock_price[order[i]]);
                    salary+=stock_price[order[i]];
        }
        else {
            if(!condition && flag1){
                    finance_name.push_back(stock_name[order[i]]);
                    finance_id.push_back(order[i]);
                    finance_count.push_back(1);
                    finance_price.push_back(stock_price[order[i]]);

                    salary+=stock_price[order[i]];

            }
        }
    }


 /*   for(int i=0;i<order.size();i++){
            bool flag=true;
       for(int j=0;j<stock_name.size();j++){
           if(finance_price[order[i]]==stock_price[j]&&finance_name[order[i]]==stock_name[j]){
                 finance_count[order[i]]++;
                 salary+=stock_price[j];
           }
           else{
            if(finance_name[order[i]]==stock_name[j]&&finance_price[order[i]]!=stock_price[j]){
                finance_name.push_back(stock_name[j]);
                finance_id.push_back(j);
                finance_count.push_back(1);
                finance_price.push_back(finance_price[order[i]]);
                salary+=finance_price[order[i]];
            }
            else {
                if(finance_name[order[i]]!=stock_name[j]){
                        flag=false;

                }
            }
           }

       }
       if(!flag){
                    finance_name.push_back(finance_name[order[i]]);
                    finance_id.push_back(order[i]);
                    finance_count.push_back(1);
                    finance_price.push_back(finance_price[order[i]]);
                    salary+=finance_price[order[i]];
       }
    }
*/

    ofstream output;
    output.open(y.c_str());
    for(int i=0;i<finance_count.size();i++){
        if(i!=finance_count.size()-1){
            output<<finance_name[i]<<" "<<finance_id[i]<<" "<<finance_count[i]<<" "<<finance_price[i]<<endl;
        }
        else output<<finance_name[i]<<" "<<finance_id[i]<<" "<<finance_count[i]<<" "<<finance_price[i];
    }


    ///***************************8
    billing bill(order,stock_name,stock_type,stock_price);
    system("clear");
    bill.show_bill();

    return salary*10/100;
}
void stock::name_comparison(vector<int>&order,vector<string>&stock_name,vector<int>&stock_type,vector<int>&stock_price,vector<vector<int>>&v){
                    label:system("clear");
                        cout<<"The item that you have entered is not present in the menu but we have find some items close to it and they are \n \n";
                          sort(v.begin(), v.end());

                           cout<<v[stock_name.size()-1][1]<<" "<<stock_name[v[stock_name.size()-1][1]]<<endl;
                            cout<<v[stock_name.size()-2][1]<<" "<<stock_name[v[stock_name.size()-2][1]]<<endl;
                            cout<<v[stock_name.size()-3][1]<<" "<<stock_name[v[stock_name.size()-3][1]]<<endl;
                            cout<<"Enter the above id's to select product   ";
                            long long int option=0;
                            string s;
                            cin>>ws;
                            getline(cin,s);
                            bool flag=true;
                            for(int i=0;i<s.size();i++){
                                if(s[i]<48 || s[i]>57){
                                    flag=false;

                                    break;
                                }
                            }
                            if(!flag){
                                goto label;
                            }
                            if(s.size()>18){
                                cout<<"Out of bound "<<endl;
                                for(int i=0;i<1000000000;i++){

                                }system("clear");
                                goto label;
                            }
                            stringstream geek(s);
                            geek >> option;
                            if(option==v[stock_name.size()-1][1] && option<quantity.size()){

                              if(quantity[option]>0){
                                    quantity[option]--;
                                order.push_back(v[stock_name.size()-1][1]);
                                }
                              else {cout<<"Eneterd item is out of stock "<<endl;
                                     for(int i=0;i<1000000000;i++){}}system("clear");
                            }
                            else{
                                    if(option==v[stock_name.size()-2][1] && option<quantity.size()){

                                        if(quantity[option]>0){
                                                   quantity[option]--;
                                            order.push_back(v[stock_name.size()-2][1]);
                                            }
                                        else {cout<<"Entered item is out of stock "<<endl;
                                        for(int i=0;i<1000000000;i++){}system("clear");}
                                    }
                                    else{
                                        if(option==v[stock_name.size()-3][1] && option<quantity.size()  ){

                                            if(quantity[option]>0){
                                                       quantity[option]--;
                                                order.push_back(v[stock_name.size()-3][1]);
                                                }
                                            else {cout<<"Entered item is out of stock "<<endl;
                                              for(int i=0;i<1000000000;i++){}system("clear");}
                                        }
                                        else {
                                           goto label;
                                        }
                                    }
                            }

}

void stock::confirm_order(vector<int>&order){
 label:system("clear");
        string s;
    cout<<"Do you want to confirm the order press Y for YES and N for NO ";
    cin>>ws;

    getline(cin,s);

    if(s[0]=='N' && s.size()==1){


        string entry;
        while(entry[0]!='e'){
            label1:system("clear");
            cout<<"Enter the id of the item to be deleted or e to exit ";
            cin>>ws;
            getline(cin,entry);
            bool flag=true;
            for(int i=0;i<entry.size();i++){
                if(entry[i]<48 || entry[i]>57){
                    if(entry[i]!=101){
                        flag=false;break;
                    }
                }
            }
            if(!flag){

               cin.clear();
               entry.clear();

            }
            else{
                    bool flag1=true;
                for(int i=0;i<entry.size();i++){
                    if(entry[i]<48 || entry[i]>57){
                        flag1=false;
                        break;
                    }
                }
                if(!flag1){
                    if(entry[0]=='e' && entry.size()!=1){
                        cin.clear();
                        entry.clear();
                    }
                }
                else{
                if(entry.size()>18){
                    cout<<"Out of bound "<<endl;
                    for(int i=0;i<1000000000;i++){

                    }system("clear");
                    goto label1;
                }
                stringstream geek(entry);
                long long int x=0;
                geek>>x;
                if(x>-1){
                        bool flag2=false;
                    for(int i=0;i<order.size();i++){
                        if(order[i]==x){
                            flag2=true;
                        }
                    }
                    int y = count(order.begin(),order.end(),x);
                    if(y>1){
                        system("clear");
                        cout<<"You have bought more than once enter the quantity you want to delete ";
                        string s1;
                        cin>>ws;
                        getline(cin,s1);bool flag3=true;
                        for(int i=0;i<s1.size();i++){
                            if(s1[i]<48 || s1[i]>57){
                                flag3 = false;
                            }
                        }
                        if(!flag3){
                            cin.clear();
                            s1.clear();
                            goto label1;
                        }
                        else{
                            if(s1.size()>18){
                                    system("clear");
                                cout<<"Out of bound \n";
                                for(int i=0;i<1000000000;i++){

                                }system("clear");
                                goto label1;
                            }
                            else{
                                long long int t=0;
                                stringstream geek(s1);
                                geek>>t;
                                if(t>y){
                                    system("clear");
                                    cout<<"Out of bound \n";
                                        for(int i=0;i<1000000000;i++){

                                        }system("clear");
                                        goto label1;
                                }
                                else{

                                    for(int i=0;i<order.size();i++){
                                        if(t<=0)break;
                                        else{
                                            if(order[i]==x){order.erase(order.begin() + i);


                                                quantity[order[i]]+=1;t--;i--;
                                            }}
                                        }

                                }

                                }
                            }
                        continue;
                    }


                    if(flag2){
                            order.erase(std::remove(order.begin(), order.end(), x), order.end());
                            quantity[x]+=1;


                         cout<<"Item has been removed "<<endl;
                    }
                    else{
                        cout<<"Entered id doesnot exists "<<endl;
                    }
                    for(int i=0;i<1000000000;i++){

                    }system("clear");
                }
                else{
                    if(x!=-1){
                        goto label1;
                        cin.clear();

                    }
                }
                }
            }
        }

    }
    else{
        if(s[0]=='Y' && s.size()==1){

        }
        else
        goto label;
    }

}



