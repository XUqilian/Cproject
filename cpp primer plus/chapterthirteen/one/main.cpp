#include"head.h"

void bravo(const Cd & t)
{
    t.report();
}

int main(void)
{
    // create
    
    Cd c1("bwatles","capitol",14,35.5); //warning:have type constant string to char*
    // assign
    
    Clsc c2 = Clsc("piano sonata in b flat,fantasia in e","alfred brendel",2,57.17,"philipe");
    
    Cd * pcd = &c1;
    // obj call fun
    
    c1.report();
    
    c2.report();
    
    pcd->report();
    

    pcd = &c2;
    
    //use virtual
    pcd->report();

    bravo(c1);
    
    // use virtual  Clsc to Cd  virtual Cd to Clsc 
    bravo(c2);

    Clsc cp;
    //use assgin
    cp = c2;
    
    cp.report();
    

    return 0;
}