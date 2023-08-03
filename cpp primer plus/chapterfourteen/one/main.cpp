#include<iostream>
#include<string>
#include<valarray>
using std::valarray;
using std::string;
using std::cout;
using std::endl;
using std::cin;

class Pair
{
    // private:
        valarray<int> arro;     // 年份
        valarray<int> arrt;     // 产量
    public:
        // Pair(){}
        Pair(int , const int * , const int *);
        explicit Pair(int);

        int elecnt()const { return arrt.size();}
        int count()const{ return arrt.sum(); };  
        int num()const {return arro.size();}
        void set();
        void show()const;
};

Pair::Pair(int t, const int * a, const int * b)
{
    arro.resize(t);
    arrt.resize(t);
    for(int i = 0 ; i < t ; i++)
    {
        arro[i] = a[i];
        arrt[i] = b[i];
    }
}

Pair::Pair(int t)
{
    arro.resize(t);
    arrt.resize(t);
}
    
void Pair::set()
{
    for(int i = 0 ; i < arro.size() ; i++)
    {
        cout << "enter years:";
        cin >> arro[i];
        cout << "\nenter num:";
        cin >> arrt[i];
        cout << endl;
    }
}

void Pair::show()const
{
    for(int i = 0 ; i < arro.size() ; i++)
    {
        cout << "years:" << arro[i] << "num:" << arrt[i] << endl;
    }
}


class Wine{
    private:
        string name;     // 名称
        Pair tandn;
    public:
        // Wine(){}
        Wine(const char * str ,int t):tandn(t),name(str){}
        Wine(const char * str, int t, const int * ara, const int * arb):name(str),tandn(t,ara,arb){}
        
        void get();
        string & lab(){return name;};
        int sum(){return tandn.count();}
        void show()const ;
};

void Wine::get()
{
    tandn.set();
}

void Wine::show()const 
{
    cout << name << endl;
    tandn.show();
}

class Winee:private Pair , private string
{
    public:
        Winee(const char * str ,int t):Pair(t),string(str){}
        Winee(const char * str, int t, const int * ara, const int * arb):string(str),Pair(t,ara,arb){}
        
        void get();
        string & lab(){return (string &)*this;};
        int sum(){return Pair::count();}
        void show()const ;
};

void Winee::get()
{
    Pair::set();
}

void Winee::show()const
{
    cout << (string &)*this << endl;
    Pair::show();
}

int main(void)
{
    char lab[50];
    cin.getline(lab,50);

    int yrs;
    cin >> yrs;

    Wine hold(lab ,yrs);
    hold.get();
    hold.show();
    int y[3] = {1993,1995,1998};
    int b[3] = {48,60,72};
    Wine more("hello" ,3, y ,b);
    more.show();
    cout << more.lab() << more.sum() << endl;
    cout << "********************************************************************" << endl;
    Winee holde(lab ,yrs);
    holde.get();
    holde.show();
    // int y[3] = {1993,1995,1998};
    // int b[3] = {48,60,72};
    Winee moree("hello" ,3, y ,b);
    moree.show();
    cout << moree.lab() << moree.sum() << endl;
    return 0;
}