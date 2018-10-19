#ifndef _application_H_
#define _application_H_
#include "finance.h"
#include "stock.h"
class application
{
stock s;
finance f;
public:
    void start();
    void manager_page();
    void receptionist_page();
   
};

#endif
