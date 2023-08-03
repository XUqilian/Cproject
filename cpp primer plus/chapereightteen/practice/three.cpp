#include<iostream>

using namespace std;

template<class T>
long double sum(initializer_list<T> t)
{
    long double count;
    for(auto x : t)
        count += x;
    return count;
}

long double sump(){return 0;}

template<typename T,typename... Args>
long double sump(T t, Args... args)
// auto sump(T t, Args... args) ->decltype(t)  //auto根据decltype推导出应该的类型
{
    return (long double)t+sump(args...);
}

int main(void)
{

    return 0;
}