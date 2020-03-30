//单词计数
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int cnt=0;
    char i;
    while((i=getchar()) && (i!=EOF))//从输入流读取字符并且
    {
        //if(!isalpha(i)) cnt++;
        if (isalpha(i))
        {
            cnt++;
            while(i=getchar() && i!=EOF){
                if(!isalpha(i)) break;

            }
            if(i==EOF){
                printf("%d",cnt);
                exit(1);
             }
        }
    }
    printf("%d",cnt);
    if(i==EOF) exit(1);
    return 0;
}