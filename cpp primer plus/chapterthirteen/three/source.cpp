#include"head.h"


Dma::Dma(const char* lab , const int ra)
{
    label = NULL;
    label = new char[strlen(lab) + 1];
    strcpy(label , lab);

    rataing = ra;
}

Dma::Dma(const Dma & t)
{
    label = NULL;
    label = new char[strlen(t.label) + 1];
    strcpy(label , t.label);

    rataing = t.rataing;
}

Dma::~Dma()
{
    delete [] label;
}

Dma & Dma::operator=(const Dma & t )
{
    if(this == &t) return *this;
    
    delete [] label;
    label = NULL;

    label = new char[strlen(t.label) + 1];
    strcpy(label , t.label);

    rataing = t.rataing;
    
    return *this;
}

void Dma::show()
{
    cout << "label:" << label << "\trataing:" << rataing << endl;
}

ostream & operator<<(ostream & op,const Dma & t)
{
    return op << "label:" << t.label << "\trataing:" << t.rataing << endl;
}




Lack::Lack(const char * lab, const char * col, int ra)
:Dma(lab , ra)
{
    strncpy(color , col , Coll);
}

Lack::Lack(const char * col,const Dma & t)
:Dma(t)
{
    strncpy(color , col , Coll);
}

Lack::~Lack()
{

}

void Lack::show()
{
    Dma::show();
    cout << "color:" << color << endl;
}

ostream & operator<<(ostream & op,const Lack & t)
{
    return op << (Dma &) t << "color:" << t.color << endl;
}




Has::Has(const char * lab, const char * sty,int ra)
:Dma(lab,ra)
{
    style = NULL;
    style = new char [strlen(sty) + 1];
    strcpy(style , sty);
}

Has::Has(const char * sty, const Dma & t)
:Dma(t)
{
    style = NULL;
    style = new char [strlen(sty) + 1];
    strcpy(style , sty);
}

Has::Has(const Has & t)
:Dma(t)
{
    // delete [] style;
    style = NULL;
    style = new char [strlen(t.style) + 1];
    strcpy(style , t.style);

}

void Has::show()
{
    Dma::show();
    cout << "color:" << style << endl;
}

Has::~Has()
{
    delete [] style;
}
