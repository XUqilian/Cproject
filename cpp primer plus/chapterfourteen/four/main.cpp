#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using std::cout;
using std::endl;
using std::string;

class Person
{
    private:
        string name;    //名字
    public:
        Person(const char* t ) :name(t){}
        virtual void show()const{cout << name << endl;}
};

class Guns : virtual public Person
{
    private:
        int num;    //刻痕a
        double times;   //拔枪时间
    public:
        Guns(const char* t , int n ):Person(t),num(n){}
        
        double drow(){return times;}
        virtual void show() const{cout << "num:" << num << "\ttimes:" << times << endl;}
};

class Poker : virtual public Person
{
    public:
        Poker(const char* t):Person(t){}
        int drow();
        virtual void show(){ Person::show();}
};

int Poker::drow()
{
    srand(time(NULL));
    return (rand() % 52) + 1;
}

class Badd : public Guns, public Poker
{
    public:
        Badd(const char* t,int n,double s):Person(t),Guns(t,n),Poker(t){}
        double Gdrow(){ return Guns::drow();}
        int Pdrow(){ return Poker::drow();}
        void show(){Person::show(); Guns::show();}
};


int main(void)
{
    Badd temp((const char*)"tom",10,1.0);
    cout << "tempdrow:" << temp.Gdrow() << "\ttempdrow:" << temp.Pdrow() << endl;
    temp.show();
    return 0;
}

// 5#
// 没有内存分配,使用默认即可
// 子类内可重新定义新内容
// 防止多重继承出现多个不同基类或者基类数据相互影响
// 可有
// 子类隐式向上转换都可以达到输出基类内容的效果
// 输出相同的四个 利用对象直接调用 自会调用对象类型的函数 而指针调用会调用指针所指向对象的相应函数
