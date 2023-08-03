#ifndef HEAD_H
#define HEAD_H

#include<iostream>
#include<cstring>
using std::ostream;
using std::istream;
using std::endl;
using std::cin;
using std::cout;

class String{
    private:
        char * str;
        int slenght;
    public:
        String();
        String(const char *strl);
        String(const String & strl);
        ~String();

        String & operator=(const String & strl);

        inline int lenght(void)const {return slenght;}

        friend ostream& operator<<(ostream & os,const String & strl);
        friend istream& operator>>(istream & os, String & strl);

        inline int lenght(){return slenght;}
        const char operator[](int)const;
        bool operator>(const String &)const;
        bool operator<(const String &)const;
        bool operator==(const String &)const;

};

inline int xgets()
{
    return getchar();
}

int xgets(char *array,int count);
int xclearin();
#endif