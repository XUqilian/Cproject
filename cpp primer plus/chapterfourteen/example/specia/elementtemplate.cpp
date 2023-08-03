#include<iostream>

using std::cout;
using std::endl;

template<class T>
class A
{
    private:
        template<class TT>
        class B
        {
            private:
                TT valtt;
            public:
                B(TT val):valtt(val){}
                TT show()const
                {
                    cout << valtt << endl;
                    return valtt;
                }
                
                void test();   
        };
    private:
        B<T> b;
        B<int> temp;

    public:
        // template<class TT>
        // void B<TT>::test(){}  // in here is ok

        A(T t, int i):b(t),temp(i){}
        void show()const{
            cout << b.show() << "\t" << temp.show() << endl;
        }

        template<class TTT>   // this is template function. because need return random type
        TTT operation( TTT j, T k)const{return ( b.show() + temp.show() ) * j / k ;}

};

// template<class TT>
// void B<TT>::test(){}  // in here is not ok. because it is private

int main(void)
{
    A<double> a(3.3,3);
    a.show();
    cout << "this can according to input first type set return type\n" 
    << "now input is double\n" <<a.operation(12.3,1.1) << endl;
    cout << "now input is int\n" <<a.operation(12,1.1) << endl;
    return 0;
}