#include"classer.h"


Sales::Sales(int a,int * ar , int b)
{
    years = a;
    for(int i = 0 ; i < mont ; i++ )
    {
        if(i < b)
            sal[i] = ar[i];
        else sal[i] = 0;
    }

}

int& Sales::operator[](int i)
{
    if(i < 0 || i >= mont)
        throw(ersales(i));
    else 
        return sal[i];
}

int & Talet::operator[](int i)
{
    if(i < 0 || i >= mont)
        throw(ertalet("error" , i));
    else
        return Sales::operator[](i);
}
