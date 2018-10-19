
#ifndef _manager_H_
#define _manager_H_

class manager : public employee
{

public:
    manager();
    void push_back_manager_data();
    void add_receptionist();
    void show_receptionist();
    void remove_receptionist();
};

#endif
