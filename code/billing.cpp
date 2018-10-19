#include "billing.h"


#include <bits/stdc++.h>
using namespace std;

billing::billing(vector<int>&order,vector<string>&stock_name,vector<int>&stock_type,vector<int>&stock_price){
    for(int i=0;i<order.size();i++){
        bill_name.push_back(stock_name[order[i]]);
        bill_type.push_back(stock_type[order[i]]);
        bill_price.push_back(stock_price[order[i]]);
    }
}

void billing::show_bill(){
    if(bill_name.size()==0){
        cout<<"You have not buy anything visit again "<<endl;
    for(int i=0;i<1000000000;i++){

    }
	system("CLS");
    }
    else{cout<<"                       ";
    cout<<"Your BILL";
        cout<<endl;cout<<endl;
    cout<<setw(15);

    cout<<"Name";cout<<setw(15);
    cout<<"Type";cout<<setw(15);
    cout<<"Price(Rs)";cout<<setw(15);
    cout<<endl;
    long long int sum=0;
for(int i=0;i<bill_name.size();i++){

    cout<<bill_name[i];cout<<setw(15);
cout<<bill_type[i];cout<<setw(15);
cout<<bill_price[i];cout<<setw(15);
sum+=bill_price[i];
cout<<endl;
}
cout<<setw(15);
cout<<"--------------------------------------------------------------";
cout<<endl;
cout<<setw(15);
cout<<"Total amount";
cout<<setw(30);
cout<<sum<<"/-";
cin.ignore();
    }
}
