#include "head.h"

Person::Person(const std::string &ln, const char *fn)
{
    lname = ln;

    for (int i = 0; fn[i] != '\0'; i++)
    {
        fname[i] = fn[i];
    }
}
// the following methods display lname and fname

void Person::Show() const
{
    std::cout << lname << ' ' << fname << std::endl;
}
// firstname lastname format

void Person::FormalShow() const
{
    std::cout << lname << ',' << fname << std::endl;
}
// lastname,firstname format
