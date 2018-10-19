#include "employee.h"
#ifndef _receptionist_H_
#define _receptionist_H_


class receptionist : public employee
{
int total_income;
public:
    receptionist();
    void push_back_receptionist_data();
    void view_salary(int total_salary);
    void add_salary(int add);
};

#endif

