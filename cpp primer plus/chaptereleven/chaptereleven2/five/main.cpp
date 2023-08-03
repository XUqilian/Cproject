#include"head.h"


int main(void)
{   

    //Stone a = 123.6;  you cant do it for "explicit" 
    
    // a = Stone(211.3);
    // a = Stone(985); //frist int to double ,next double to Stone
    //now you cant do it because of the unknow , maybe you must declared operator "="

    double a;
    int c;
    
    Stone b(123.3);

    //a = b;  now cant do it bucause "explicit"
    a = double(b); //use duoble 
    c = (int) b;    //use int

    cout << "b:" << b << "\ndouble a:" << a  << "\nint c:" << c <<endl;

    
    return 0;
}