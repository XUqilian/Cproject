#include<string>
#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;
using std::cin;

//******************************************************************
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


//***************************************************************************

template<class T>
class Stack
{
    private:
        T  arr[]; // 栈位置指针
        const int cnt; // 栈大小
        int top; // 栈顶
    public:
        explicit Stack(int s = 5);
        ~Stack() { delete[]arr; };
        bool push();
        bool push(const T &);
        bool pop();
        bool isfull()const;
        bool isempty()const;
 
};
/*
template<class T>           // 函数需要模板限定
Stack<T>::Stack(int s )     //还需要添加类型限定
:cnt(s)   // const 初始化固定大小
{
    arr = new T[cnt];
    top = 0;
}

template<class T>
bool Stack<T>::push(const T & t)  // 特殊类型就需要使用该函数 传递指针类
{
    if(!isfull())
    {
        arr[top] = t;
        top++ ; 
        cout << t << " is push!" << endl;
        return true;
    }else{
        cout << "stack is full" << endl;
        return false;
    }
}

template<class T>
bool Stack<T>::pop()
{
    if(!isempty())
    {
        // arr[top] = 0;
        top--;
        cout << arr[top] << " is pop" << endl;
        return true;
    }else{
        cout << "stack is empty" << endl;
        return false; 
    } 
}

template<class T>
bool Stack<T>::isfull()const
{
    // if(arr[cnt-1])return true;
    if(top == cnt)return true;
    else return false;
}
template<class T>
bool Stack<T>::isempty()const
{
    if(0 == top)return true;
    else return false;
}
*/

template<> class Stack<Worker * >
{
    private:
        int top; // 栈顶
        const int cnt; // 栈大小
        Worker* arr[]; // 栈位置指针
    public:
        explicit Stack(int s = 5);
        ~Stack() { delete[]arr; };
        bool push();
        bool push(const Worker* &);
        bool pop();
        bool isfull()const;
        bool isempty()const;
 
};


int main(void)
{
    Stack<Worker*> sw;

    return 0;
}