#include <iostream>
#include "head.h"

int main()
{
    Savers temp1; // default constructor
    Savers temp2{"11111111"};
    Savers temp3 = Savers("22222222");
    Savers temp4{"333333","333333",333};
    Savers temp5 = Savers("4444","4444");    

    temp1.deposit(1000);
    temp1.display();
    temp1.remove(200);
    temp1.display();

    return 0;
}
