#include <iostream>

using namespace std;

int main(void)
{

    char buf[1024];

    int *p = new(buf) int();   //类似于强制类型转换,如果是类就会构造

    return 0;
}