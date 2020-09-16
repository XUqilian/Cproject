//单词计数
//添加了文件段

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int cnt=0;
    char i;
    int count=0;
    /*
    char file[15]={0,[14]='\0'};
    printf("需要检查的文件(文件名不要超过14字符)是：");
    fgets(file,14,stdin);
    FILE*f;
    if(f=fopen("*file",'r'))
    {
        while((i=getc(f))&&(i!=EOF))
        {}
    }
    */
    while((i=getchar()) && (i!=EOF))//从输入流读取字符并且
    {
        //if(!isalpha(i)) cnt++;
        if (isalpha(i))
        {
            cnt++;
            count++;
            while(i=getchar() && i!=EOF){
                if(!isalpha(i)){ break;}
                else count++;

            }
            if(i==EOF){
                printf("%d个单词，平均每个%d个字母",cnt,count/cnt);
                exit(1);
             }
        }
    }
    printf("%d个单词，平均每个%d个字母",cnt,count/cnt);
    if(i==EOF) exit(1);
    return 0;
}