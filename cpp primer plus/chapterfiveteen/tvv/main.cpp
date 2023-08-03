#include "tv.h"

int main(void)
{
    Tv tv;
    tv.show();
    tv.setsta();
    tv.chaup();
    tv.volup();
    tv.show();
    
    cout << "_____________________________________" << endl;
    Remote rt;
    rt.rchaup(tv);
    rt.rvolup(tv);
    rt.rsetcha(tv,55);
    tv.show();

    rt.rsetsta(tv);
    return 0;
}