#include"head.h"


Port::Port(const char* br,const char* st,int b)
{
    brand = new char[strlen(br)+1];
    strcpy(brand,br);
    strncpy(style , st , 20);
    style[19] = '\0';
    bottles = b;
}

Port::Port(const Port &t)
{
    // delete []brand;  // 并未定义无参数的构造函数 所以用不上 而且不同环境不一定会调用默认构造函数
    brand = NULL;

    brand = new char[strlen(t.brand)+1];
    strcpy(brand,t.brand);

    strncpy(style , t.style , 20);

    style[19] = '\0';
    bottles = t.bottles;

}


Port & Port::operator=(const Port & t)
{
    if(this == &t) return *this;

    delete []brand;
    brand = NULL;
    brand = new char[strlen(t.brand)+1];
    strcpy(brand,t.brand);
    strncpy(style , t.style , 20);
    style[19] = '\0';
    bottles = t.bottles;

    return *this;
}

Port & Port::operator+=(int b)
{
    bottles += b;
    return *this;
}

Port & Port::operator-=(int b)
{
    bottles -= b;
    return *this;
}


////////////////////////////////////////////////////////////////////////


Vport::Vport()
:Port()
{
    name = new char;
    name[0] = '\0';
}

Vport::Vport(const char* br,const char* st,int b,const char* nn, int y)
:Port(br,st,b)
{
    name = new char[strlen(nn)+1];
    strcpy(name,nn);
    year = y;
}

Vport::Vport(const Vport & t)
:Port(t)
{
    // delete []name;
    name = NULL;
    
    name = new char[strlen(t.name)+1];
    strcpy(name,t.name);

    year = t.year;
}

Vport & Vport::operator=(const Vport& t)
{
    if(this == &t) return *this;

    Port::operator=(t);

    delete []name;
    name = NULL;

    name = new char[strlen(t.name)+1];
    strcpy(name,t.name);

    year = t.year;

    return *this;
}
