#include"classer.h"

int main(void)
{
    int sal[] = {10 ,20 ,30 ,40 , 50 ,60 ,70 ,80 ,90 , 100 , 110 , 120 };
    Sales a(12 , sal ,12);
    Sales b(12);
    
    Talet c("in the talet." , 12 , sal , 12);

    for(int i = 0 ; i  <12 ; i ++)
    {
        cout << a[i] << "\t" ;
        // if ( !(i % 5) ) cout << endl;
    }
    cout << "\n_________________________" << endl;
    for(int i = 0 ; i  <12 ; i ++)
    {
        cout << c[i] << "\t" ;
        // if ( !(i % 5) ) cout << endl;
    }
    cout << "\n_________________________" << endl;
    
    try{
        cout << a[12] << endl;
        // cout << c[12] << endl;
    }
    // catch(Talet::ertalet & et)  // 将子类置于前 防止父类覆盖子类的异常 父类可接收子类指针和引用
    // {
    //     cout << "1:" << et.what() << endl;
    //     cout << "2: the error code " << et.lab() << endl;
    //     cout << "3:" << et.bak() << endl;
    // }
    catch(Sales::ersales & es)
    {
        if(Talet::ertalet * et = dynamic_cast<Talet::ertalet *> (&es))
        {
            cout << "1:" << et->what() << endl;
            cout << "2: the error code " << et->lab() << endl;
            cout << "3:" << et->bak() << endl;
        }
        else
        {
            cout << "1:" << es.what() << endl;
            cout << "2: the error code " << es.lab() << endl;
        }
    }


    return 0;
}