#include"head.h"

int main()
{
    Person one;
    Person two("smythecaraft");
    Person three("dimwiddy","sam");
    
    one.Show();
    std::cout<<std::endl;
    one.FormalShow();

    two.Show();
    std::cout<<std::endl;
    two.FormalShow();

    three.Show();
    std::cout<<std::endl;
    three.FormalShow();
    
    return 0;
}