#include <bits/stdc++.h>
#ifndef _menu_H_
#define _menu_H_
using namespace std;

class menu
{
vector<string> name;
vector<int> type;
vector<int> price;

 public:
  void setter (string a,int b,int c);
  void show_menu();
  vector<string> get_name();
  vector<int> get_type();
  vector<int> get_price();

};

#endif

