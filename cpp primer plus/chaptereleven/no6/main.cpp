#include "head.h"
//#include<iostream>

int main()
{
    ston a[6]={12.3,23.4,34.5};
    for(int i=3;i<6;i++)
    {
        scanf("%f",&a[i]);
    }
    
    ston* max=&a[0];
    ston* min=&a[0];
    for(int i=1;i<6;i++)
    {
        if (*max<a[i]) max=&a[i];
        if(*min>a[i]) min=&a[i];
    }

    ston t(11,0);
    int count=0;
    for(int i=0;i<6;i++)
    {
        if(a[i]>=t)
        {
            count++;
        }
    }
    
}
