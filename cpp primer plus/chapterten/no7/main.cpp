#include "head.h"

int main()
{
    plorg a;
    plorg b{"name",34};
    a.set(33);
    a.display();
    b.display();
    return 0;
}