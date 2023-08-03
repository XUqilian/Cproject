#include<stdio.h>
//求最大公约数，最小公约数，最小公倍数和指定范围内的最大公倍数

int main()//求两个数的最大公约数，当然求多个的话可以把6 7 8 9 11改一下就行了
//最小公约数肯定是1，如果不能是一就得改一下，详情11
//当然，指定范围内也是改11
{
    int a,b,max,min,temp,casual;//casual：临时的
    scanf("%d %d",&a,&b);//输入两个数
    if(a==1||b==1){casual=1;goto out;}//俩竖代表位上的或者“||”，一竖代表逻辑上的或者“|”
    if(a>b){min=b;}else{min=b;}
    for(temp=2;temp<=min;temp++){//最小公约数改这个：(temp=min;temp>1;temp--)
        if(0==a%temp)if(0==b%temp){casual=temp;}
    }
    out:
    printf("%d",casual);
    return 0;
}

#include<stdio.h>
//教材版，辗转相除法计算最大公约数
int main()
{
    int a,b;
    int temp;
    scanf("%d %d",&a,&b);
    while(b!=0){
        temp=a%b;
        a=b;
        b=temp;
    }
    printf("%d",a);
    return 0;
}

int main()//求最小公倍数
//最大改28
{
    int a,b,max,min,temp,casual;//casual：临时的
    scanf("%d %d",&a,&b);//输入两个数
    if(a>b){max=a;}else{max=b;}
    if(a==1||b==1){casual=max;goto out;}//这儿调换了一行，就是为了借上面判断，少一点代码
    int limit=a*b;//limit:极限
    for(temp=limit;temp>=max;temp--){//最大公倍数改这个:(temp=max;temp<=limit;temp++)
        if(0==temp%a)if(0==temp%b){casual=temp;}
    }
    out:
    printf("%d",casual);
    return 0;
}
