#include "head.h"
#include <string.h>

void golf::setgolf(char *name, int hc)
{
    strncpy(fname, name, Len);
    handicp = hc;
}

int golf::setgolf()
{
    fgets(fname,Len,stdin);
    scanf("\t%d", handicp);
    return handicp;
}

void golf::sethandicp(int hc)
{
    scanf("\t%d", handicp);
}

void golf::showgolf() const
{
    puts(fname);
    printf("\t%d", handicp);
}
