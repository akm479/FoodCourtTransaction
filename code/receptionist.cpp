#include<bits/stdc++.h>
using namespace std;
#include "receptionist.h"

receptionist :: receptionist(){
type = R;
}

void receptionist :: push_back_receptionist_data(){

}

void receptionist :: view_salary(int total_salary){
    cout<<"Total amount that you have earned is : Rs "<<total_salary<<endl;
       cin.ignore();

}

void receptionist :: add_salary(int add){
total_income+=add;
}
