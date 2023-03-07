#include <iostream>
#include "List.h"

int main()
{
    setlocale(LC_ALL, "Rus");

    List <int> ls;
    
    int Case = menu();
    bool state = false;

    logic(ls, Case, state);

    return 0;
}
