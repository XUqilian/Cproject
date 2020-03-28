//round 循环
//嵌套循环
#include<stdio.h>

void a(void);
void b(void);
void c(void);

int main()
{
    a();
    b();
    c();
    return 0;
}
void a()
{
    int temp='F';
    int cnt=('F')-('A');
    for(int i=1;i<cnt+2;i++)
    {
        for(int j=0;j<i;j++){
            printf("%c",'F'-j);

        }
        printf("\n");
    }
}

void b()
{
    int cnt=5;
    int count=0;
    for(int i=0;i<cnt;i++){
        for(int j=1;j<=i+1;j++){
            printf("%c",'A'+count);
            count++;
        }
        printf("\n");
    }
}

void c()
{
    char a;
    int  star;
    scanf("%c",&a);
    star=(int)a;
    int cnt=star-'A'+1;
    int j;
    for(int i=1;i<=cnt;i++){
        
        for(j=0;j<i;j++){
            if(j==0){
                printf("%*c",cnt-i+1,'A'+j);
            }else 
                printf("%c",'A'+j);
        }
        j=j-2;
        for( j;j>=0;j--){
            printf("%c",'A'+j);
        }
        printf("\n");
    }

}