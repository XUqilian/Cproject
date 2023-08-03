#include "xcpp.h"

void errcin(void)
{
    if(std::cin.fail())
    {
        std::cin.clear();
        while(std::cin.get()!='\n');
    }
    
}