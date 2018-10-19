#include <bits/stdc++.h>
using namespace std;
#ifndef _billing_H_
#define _billing_H_


class billing
{
vector<string> bill_name;
vector<int> bill_type;
vector<int> bill_price;

 public:
     billing(vector<int>&order,vector<string>&stock_name,vector<int>&stock_type,vector<int>&stock_price);
     void show_bill();

};

#endif

