//五人分鱼
#include<stdio.h>

int main()
{
    int n;//总鱼数
    int cnt=0;//计数
    for(n=6;cnt<5;n+=5)
    {
        cnt=0;
        int t=n;
        while(t%5==1){
            t=t-(t/5)-1;
            cnt++;
        }
    
    }
    printf("%d",n);
    int i;
    for(n;cnt>0;cnt--){
        i=n/5;
        printf("NO.%d:%d\n",cnt,i);
        n=n-i-1;
    }

}