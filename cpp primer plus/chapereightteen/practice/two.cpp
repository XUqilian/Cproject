#include<iostream>

using namespace std;

class Cpmv{
    public:
        struct info
        {
            string qcode;
            string zcode;
        };
    private:
        info * pstt;
    public:
        Cpmv(){ pstt = new info;}
        Cpmv(const string s1,const string s2);
        Cpmv(const Cpmv & t);
        Cpmv(Cpmv && t);
        ~Cpmv(){ delete pstt;}
        Cpmv & operator = (const Cpmv & t);
        Cpmv & operator = (Cpmv && t);
        Cpmv operator + (const Cpmv & t) const ;
        void dis();
};

// 是不是用new分配内存更好一些 
// 移动构造和赋值 存在问题呀  已存在的对象会被剥夺访问权导致无法使用

Cpmv::Cpmv(const string s1,const string s2)
{
    pstt = new info{s1,s2};     // code 待验证
}

Cpmv::Cpmv(const Cpmv & t)
{
    if(this != &t)
        pstt = new info{t.pstt->qcode , t.pstt->zcode};
}

Cpmv::Cpmv(Cpmv && t)
{
    pstt = t.pstt;
    t.pstt = nullptr;
}

Cpmv & Cpmv::operator = (const Cpmv & t)
{   
    if(this != &t)
        pstt = new info{t.pstt->qcode , t.pstt->zcode};
    return *this;
}

Cpmv & Cpmv::operator = (Cpmv && t)
{
    if(this != &t)
    {
        pstt = t.pstt;
        t.pstt = nullptr;
    }
    return *this;
}

Cpmv Cpmv::operator+(const Cpmv & t)const
{   
    // if need return type is Cpmv& 
    // Cpmv cp(pstt->qcode + (t.pstt)->qcode , pstt->zcode + (t.pstt)->zcode);
    // return cp;
    return Cpmv(pstt->qcode + (t.pstt)->qcode , pstt->zcode + (t.pstt)->zcode);
}


int main(void)
{

    return 0;
}