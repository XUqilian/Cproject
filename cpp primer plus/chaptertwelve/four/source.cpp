#include "head.h"

// Item * pitem;
// int size;
// int top;

Stack::Stack(int n)
{
    size = n;
    pitem = new Item[n];
    top = 0 ;
}

Stack::Stack(const Stack &st)
{
    delete[] pitem;
    top = st.top;
    size = st.size;
    pitem =new Item[size];
    for(int i = 0 ; i < top ; i++)
        pitem[i] = st.pitem[i];
    
}

Stack::~Stack()
{
    delete [] pitem;
}

bool Stack::isempty()const
{
    return top == size;
}

bool Stack::isfull()const
{
    return top == 0;
}

bool Stack::push(const Item &it)
{
    if(!isfull())
    {
        top++;
        pitem[top] = it;
        return true;
    }
    return false;
}

bool Stack::pop(Item & it)
{
    if(!isfull())
    {
        it = pitem[top];
        top--;
        return true;
    }
    return false;
}

Stack & Stack::operator=(const Stack & st)
{
    if(this == &st) return *this;
    delete[] pitem;
    top = st.top;
    size = st.size;
    pitem =new Item[size];
    for(int i = 0 ; i < top ; i++)
        pitem[i] = st.pitem[i];
    return *this;
}
