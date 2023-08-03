#include"head.h"

void Worker::set()
{
    if(!name.length())
    {
        printf("enter name:");
        cin >> name;
        while(getchar() != '\n');
    }
    if(!id)
    {
        printf("enter id:");
        scanf("%d",&id);
        while(getchar() != '\n');
    }
    printf("\n");
    // cin >> name;
    // cin >> id;
}

void Worker::show()const
{
    // cout << "name:" << name << "\nid:" << id << endl;
    // printf(this->name); //error : multiple  fedinetion  重复定义
    printf(name.c_str());
    printf("\nid:%d\n",id);
}


void Singer::set()
{
    // Worker::set();   // 可以由 operator >>  进行整合输入
    printf("enter panache:");
    scanf("%d",&panache);
    while(getchar() != '\n');
    printf("\n");
}

void Singer::show()const
{
    printf("panache:%d\n",panache);
}

istream & operator >> (istream & is , Waiter & t)
{
    t.Worker::set();   // 可以由 operator >>  进行整合输入
    t.set();  
    return is;
}

ostream & operator<<(ostream & os,const Singer & t)
{
    t.Worker::show();
    return os << "panache:" << t.panache << endl;
}


void Waiter::set()
{
    printf("enter voice:");
    scanf("%d",&voice);
    while(getchar() != '\n');
    printf("\n");
}

void Waiter::show()const
{
    printf("voice:%d\n",voice);
}

istream & operator >> (istream & is , Singer & t)
{
    t.Worker::set();
    t.set();
    return is;
}

ostream & operator<<(ostream &os ,const Waiter &t) 
{
    t.Worker::show();
    return os << "voice:" << t.voice << endl;
}


void Wsw::set()
{
    // Worker::set();
    // Singer::set();
    // Waiter::set();
    // ......
}

void Wsw::show()const 
{
    // Worker::show();
    // Singer::show();
    // Waiter::show();
    // ......
}

istream & operator >> (istream & is , Wsw & t)
{
    // t.set();  // 有待商榷 虚函数子类会自动调用父类吗? 
    // 虚函数会根据调用对象的不同调用不同对象类型的虚函数  当前t是Wsw 自会调用自己的set函数
    t.Worker::set();  //所以使用域解析运算符进行限定使用
    t.Waiter::set();
    t.Singer::set();
    t.set();
    // 设置为protected 就不是直接在set内使用 而是加域解析使用
    return is;
}

ostream & operator<<(ostream & os , const Wsw & t)
{
    t.Worker::show();
    t.Singer::show();
    t.Waiter::show();

    // t.show(); //...... this class no element
    return os;
}