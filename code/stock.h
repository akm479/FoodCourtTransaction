#include "menu.h"
#include <bits/stdc++.h>
using namespace std;
#ifndef _stock_H_
#define _stock_H_


class stock : public menu
{
 vector<int> quantity;

 public:
    stock();
     void push_back_stock_data(string new_item,int new_type,int new_price,int new_quantity);
     void show_stock();
     int update_stock(bool &flag);
     int take_order();
     void name_comparison(vector<int>&order,vector<string>&stock_name,vector<int>&stock_type,vector<int>&stock_price,vector<vector<int>>&v);
     void confirm_order(vector<int>&order);
     int lcs(string s,string s1,int m,int n);

};

#endif
