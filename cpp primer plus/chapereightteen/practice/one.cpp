#include<iostream>

using namespace std;

template<class T>
T avage_list(initializer_list<T> lists)
{   
    T count;
    for(auto x : lists)
        count += x;
    return count / lists.size();
}

int main(void)
{
    auto q = avage_list({15.4,10.7,9.0});
    cout << q << endl;

    cout << avage_list({20  , 30 , 19 , 17 , 45 , 38}) << endl;

    auto ad = avage_list<double>({'A',70,65.33});
    cout << ad << endl;

    return 0;
}