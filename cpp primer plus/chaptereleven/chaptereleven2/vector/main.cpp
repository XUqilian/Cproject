#include"head.h"
#include<cstdlib>
#include<ctime>
using namespace Vtr;
using std::cin;


int main(void)
{
    // Vector a(4.3,2.6);
    // Vector b(25,45,Vector::vec);
    // cout<< a << endl;
    // cout<< b << endl;
    // a=2*b;
    // cout << a << endl;

    double pmag , step;

    cout << "do you want person move mag:";
    cin >> pmag;
    cout << "do you want person move step:";
    cin >> step;
    cout << endl;

    srand(time(0));

    Vector person;
    int psteps=0;

    while(person.valmag() < pmag)
    {
        //person = person + Vector(2,rand()%360,Vector::vec);
        person = Vector(step,rand()%360,Vector::vec) + person ;
        // Vector stp(2,rand()%360,Vector::vec);
        // person = person + stp;
        psteps++;
    }

    cout << "steps:"<<psteps<<" pmag:"<<person.valmag()<<endl;


    return 0;
}