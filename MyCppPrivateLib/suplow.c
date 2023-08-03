#include "xcpp.h"

int low(char *strl)
{
    int i = 0;
    while(strl[i])
    {
        if(strl[i] <= 'z' && strl[i] >= 'a')    
            strl[i] -= 32;
        i++;
    }
}

int sup(char *strl)
{
    int i = 0;
    while(strl[i])
    {
        if(strl[i] <= 'Z' && strl[i] >= 'A')    
            strl[i] += 32;
        i++;
    }
}