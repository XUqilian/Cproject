#include"head.h"

int main(void)
{
    int z= 10;
    Fifo f(z);

    while(!f.isfull())
        f.add();

    while(!f.isempty())
        f.del();


    return 0;
}