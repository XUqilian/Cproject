#include<iostream>

using std::cout;
using std::endl;
using std::cin;

template<class T , int n = 0> class Qucue
{
    private:
        T que[n];
        const int cnt = n;  //队列大小
        int top = 0;    // 队列顶
    public:
        Qucue(){}

        void push(T &);
        void pop();
        bool isempty(){return 0 == top;}
        bool isfull(){return n == top;}
};

template<class T,int n>
void Qucue<T,n>::push(T & t)
{
    if(isfull())
    {
        cout << "qucue is full!" << endl;
        return;
    }
    else
    {
        que[top] = t;
        cout << t << " is push." << endl;
        top++;
    }
}

template<class T,int n>
void Qucue<T,n>::pop()
{
    if(isempty())
    {
        cout << "qucue is empty!" << endl;
        return;
    }
    else
    {
        int i = 0;
        cout << que[i] << " is pop. " << endl;
        for(; i < top ; i++)
        {
            que[i] = que[i+1];
        }
        top--;
    }
}


int main(void)
{
    Qucue<int ,5> fiveint;
    fiveint.pop();
    int t;
    while(cin >> t && t > 0)
        fiveint.push(t);
    while(!fiveint.isempty())
        fiveint.pop();

    return 0;
}