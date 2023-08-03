#include <iostream>
#include<string>
#include<array>

const int Numb = 4;

using std::cout;
using std::cin;
using std::endl;
using std::array;
using std::string;

void show(const array<double,Numb> aa, const int n);
int change(array<double,Numb> *pa,const int n);

array<string,Numb> seasons={"a","b","c","d"};


int main(void)
{
    array<double,Numb> price;


    change(&price,Numb);    //需要传入 array 实例的指针才能改变其内容
    show(price,Numb);    //这里传入的是 array 类型的一个实例,可将其视为变量,以赋值方式传入
    return 0;
}


void show(const array<double,Numb> aa, const int n)
{
    for(int i=n;i--;)
        cout<<"#"<<i+1<<":"<<aa[i]<<endl;
}

int change(array<double,Numb> *pa,const int n)
{
    for(int i=n;i--;)
    {
        cout<<"enter "<<seasons[i]<<"price:";
        cin>>(*pa)[i];   //***这里尤为重要,因为传入的是 array 的实例指针,所以要先解引用得到实例再对其中实例操作
    }
    return 0;
}
