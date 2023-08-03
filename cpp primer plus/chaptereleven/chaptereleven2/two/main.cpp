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
    int psteps = 0;
    int avpsteps = 0;
    int cnt;

    cout << "do you want person move mag:";
    cin >> pmag;
    cout << "\ndo you want person move step:";
    cin >> step;
    cout << "\nhow much time do you want to loop:";
    cin >> cnt;
    cout << endl;

    srand(time(NULL));

    Vector person;
    int ct = cnt;

    while(ct--)
    {
            
        while(person.valmag() < pmag)
        {
            //person = person + Vector(2,rand()%360,Vector::vec);
            person = Vector(step,rand()%360,Vector::vec) + person ;
            // Vector stp(2,rand()%360,Vector::vec);
            // person = person + stp;
            psteps++;
        }
        cout << "steps:"<<psteps<<" pmag:"<<person.valmag()<<endl;        

        avpsteps += psteps;
        psteps = 0;

        person = Vector(0,0);

    }
    cout << "times:" << cnt << "\tavpsteps:" << avpsteps/cnt << endl; 





    return 0;
}