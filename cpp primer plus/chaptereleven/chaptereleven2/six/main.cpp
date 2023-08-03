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
    Stone ary[6]
    {
        Stone(12.3),
        Stone(23.4),
        Stone(34.5)
    };

    //a = b;  now cant do it bucause "explicit"
    a = double(b); //use duoble 
    c = (int) b;    //use int
    Stone d(2 ,45);

    cout << "b:" << b << "\ndouble a:" << a  << "\nint c:" << c <<endl;

    if( d > b) cout << "d > b";
    else cout << "d < b ";

    Stone max = ary[0],min = ary[0];
    for(int i = 6 ; i ; --i )
    {
        if(ary[i].empty()) continue;
        else 
        {
            double a;
            cout << "enter the pounts:";
            cin >> a;
            ary[i] = ((Stone)a);
            cout << endl;
        }
    }

    for(int i = 0 ; i < 6 ; i++)
    {
        cout << i << endl;
        cout << ary[i] << endl;

        if(max < ary[i])                
        {
            max = ary[i];
            cout << "x:" << ary[i] << endl;
        }
        if(min > ary[i])                
        {
            min = ary[i];
            cout <<"m:" << ary[i] << endl;
        }
        cout << ary[i] << endl;
        cout << max << endl;
        cout << min << endl;
    }

    cout << "max in array:" << max <<"\nmin in array:" << min << endl;
    
    return 0;
}