#include<iostream>
#include<cstdlib>
#include<ctime>

using std::cout;
using std::endl;

class A
{
    private:
        int a;
    public:
        A(int i) : a(i) {}
        virtual void show()const{cout << "show in A , a:" << a << endl;}
};

class B : public A
{
    public:
        B(int i) : A(i){}
        virtual void show(){cout << "show in B " << endl;}
        virtual void dis(){cout << "dis in B" << endl;}
};

class C : public B
{
    public:
        C(int i ) : B(i){}
        virtual void show(){cout << "show in C " << endl;}
        virtual void dis(){cout << "dis in C" << endl;}
};


A * rcls()
{
    A * ap;
    srand(time(NULL));

    switch(rand() % 3)
    {
        case(0):
            ap = new A(rand() % 100);
        case(1):
            ap = new B(rand() % 150);
        case(2):
            ap = new C(rand() % 300);
    }
    return ap;
}

int main(void)
{
    A * ap , * temp;

    for(int i = 0 ; i < 3 ; i++)
    {
        temp = rcls();

        temp->show();

        if(ap = dynamic_cast<B*>(temp)) // dybanic_cast <type * > (point)  判断指针是否是指定类型的 是则返回该指针 不是则返回NULL
        {
            ((B*)ap)->dis();
            cout << typeid(ap).name() << endl;
        }    
 
        if(typeid(C) == typeid(temp))   //typeid() 返回参数类型标志是什么 类似于sizeof
            ((C*)temp)->dis();    


        delete temp;
        ap = NULL;
    }

    return 0;
}