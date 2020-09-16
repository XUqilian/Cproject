//文件拷贝程序
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    if (argc < 3)//判定需求文件足够
    {
        printf("程序需要两个文件");
        exit(EXIT_SUCCESS);
    }
    FILE *f1, *f2;//文件指针
    if(!(f1=fopen(argv[2],"r") || !(f2=fopen(argv[3],"w"))))//判断文件是否能打开
    {
        printf("无法打开文件");
        exit(EXIT_SUCCESS);
    }
    int later;//数组大小
    fseek(f1,0l,SEEK_END);//定位到文件末
    later=ftell(f1);//获取文件大小
    rewind(f1);//返回文件开始处
    char temp[later];//创建数组
    fwrite(temp,sizeof(char),later,f1);//将文件内容拷贝至数组
    fread(temp,sizeof(char),later,f2);//将数组内容拷贝至文件

    fclose(f1);
    fclose(f2);

    return 0;
}