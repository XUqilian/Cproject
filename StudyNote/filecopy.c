#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define Aa ('z' - 'Z')

int main()
{
    char file[20]; //文件名
    printf("请输入文件名(文件名长限制在20个字符以内)(enter结束输入)");
    fgets(file, 20, stdin);   //获取文件名
    while (getchar() != '\n') //清理输入流
        continue;
    FILE *f1;                     //文件指针
    if (!(f1 = fopen(file, "r"))) //只读打开文件
    {
        printf("无法打开文件");
        exit(EXIT_SUCCESS);
    }
    int later;
    fseek(f1, 0l, SEEK_END); //定位文件末尾
    later = ftell(f1);       //获取文件大小
    rewind(f1);              //返回文件开始处
    char temp[later];        //拷贝数组
    int ch;
    int i = 0;
    while ((ch = getc(f1)) && (ch != EOF)) //获取文件字符
    {
        if ((97 < ch) && (ch < 122)) //判断小写字母，小写在97-122之间
        {
            ch -= Aa;
        }
        temp[i] = (char)ch;
        i++;
    }
    fclose(f1);                   //关闭文件
    if (!(f1 = fopen(file, "w"))) //只写打开文件
    {
        printf("无法打开文件");
        exit(EXIT_SUCCESS);
    }
    fread(temp, sizeof(char), later, f1); //二进制写入
    fclose(f1);                           //关闭文件

    return 0;
}