#include<iostream>
#include<cstring>

using std::cout;
using std::endl;

class Frab
{
    private:
        char ar[20];
    public:
        Frab(const char * s = "c++"){strncpy(ar,s,19);}   // have to add explicit
        Frab(const Frab &);
        ~Frab(){}
        virtual void tell(){cout << ar << endl;}
};

Frab::Frab(const Frab & t)
{
    strncpy(ar,t.ar,20);
    ar[19] = '\0';
}

class Glo
{
    private:
        int a;
        Frab b;
    public:
        Glo(int i = 0 , const char * j = "c++"):a(i),b(j){}
        Glo(int i , const Frab & t ):a(i),b(t){};   
        // 浅拷贝虽然可以用,但数据会有安全隐患 t的原对象更改时会影响本类对象
        ~Glo(){}
        virtual void tell(){ b.tell(); cout << a << endl; }
};

// Glo::Glo(int i , const Frab & t)
// {
//     a = i;
//     // 不创建深度复制构造函数根本不能用 要不然会出现内存错误
//     // 默认复制只会 ar = t; 这只获取了地址 将 ar 指向 t 的内存位置
// }

class Glt:private Frab
{
    private:
        int a;
    public:
        Glt(int i = 0 , const char * s = "c++"):a(i),Frab(s){}
        Glt(int i , const Frab & t):a(i),Frab(t){};
        virtual void tell(){ Frab::tell();cout << a << endl;}
};

// Glt::Glt(int i , const Frab & t)
// {
//     a = i;

// }



