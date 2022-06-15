#include <iostream>

using namespace std;

int main(void)
{

    char buf[1024];

    int *p = new(buf) int(); 

    return 0;
}