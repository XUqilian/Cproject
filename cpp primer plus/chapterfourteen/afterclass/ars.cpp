// #include"..\templateclass\head.h"

#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;
using std::cin;

template<class T,int n = 5> // 多参模板 非类型表达式参数 默认模板参数
class Array
{
    private:
        T arr[n];
    public:
        // Array();
        T & operator[](int);
};

template<class T,int n>
T & Array<T,n>::operator[](int i)  // 返回值类型是Array<T,n>
{
    return arr[i];
}

//////////////////////////////////////////////////////////////
class Worker
{
    private:
        // char * name;
        string name;
        int id;
    public:
        Worker():name(),id(){};
        Worker(const char *str, int idnum) : name(str) , id(idnum){};
        virtual ~Worker(){}

        virtual void set(); //
        void show() const;
};

void Worker::set()
{
    printf("enter name:");
    cin >> name;
    while(getchar() != '\n');
    printf("enter id:");
    scanf("%d",&id);
    while(getchar() != '\n');
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

/////////////////////////////////////////////////////////////////////
//******************************************************************/
template<class T>
class Stack
{
    private:
        T  arr[]; // 栈位置指针
        const int cnt; // 栈大小
        int top; // 栈顶
    public:
        T temp;  
    public:
        explicit Stack(int s = 5);
        ~Stack(){ delete[]arr; };
        // bool push();
        bool push(const T &);
        bool pop();
        bool isfull()const;
        bool isempty()const;
};
/*********************************************************************/
//实例化
//具体化如何处理类的成员变量  -> 重新定义 

// string 对象数组
Array<string> t;

// double 数组栈   
Stack<Array<double>> t;

// 指向worker指针的栈数组
Array<Stack<Worker*>> t;
