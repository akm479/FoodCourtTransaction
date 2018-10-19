#include <bits/stdc++.h>
using namespace std;
#ifndef _finance_H_
#define _finance_H_


class finance
{
vector<int> cost;
int profit;
vector<int>item_id;
vector<int>item_count;
vector<int>item_selling_price;

 public:
     finance();
     void push_back_finance_data();
     void show_profit();
     void add_sale(vector<int>&price,vector<int>&id,vector<int>&type);
     int get_cost();
     void add_cost(int new_cost);
     void delete_cost();
     void show_report();

};

#endif

