//输出文件
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    if (argc < 3) //判定需求文件足够
    {
        printf("程序需要两个文件");
        exit(EXIT_SUCCESS);
    }
    FILE *f1, *f2;                                                  //文件指针
    if (!(f1 = fopen(argv[2], "r") || !(f2 = fopen(argv[3], "r")))) //判断文件是否能打开
    {
        printf("无法打开文件");
        exit(EXIT_SUCCESS);
    }
    for (int i = 1, j = 1; i || j;)
    {
        char temp[sizeof(f1) < sizeof(f1) ? sizeof(f2) : sizeof(f1)];
        if (i)
        {
            if (fgets(temp, sizeof(f1), f1))
            {
                fputs(temp, stdout);
            }
            else
                i = 0;
        }
        if (j)
        {
            if (fgets(temp, sizeof(f2), f2))
            {
                fputs(temp, stdout);
            }
            else
                j = 0;
        }
    }

    for (int i = 1, j = 1; i || j;)
    {
        char temp[sizeof(f1) + sizeof(f2)];
        char temp1[sizeof(f1)];
        char temp2[sizeof(f2)];
        if (i)
        {
            if (!fgets(temp1, sizeof(f1), f1))
                i = 0;
        }
        if (j)
        {
            if (!fgets(temp2, sizeof(f2), f2))
                j = 0;
        }
        if (i && j)
        {
            strcat(temp, temp1);
            strcat(temp, temp2);
        }
        else if (i)
            strcat(temp, temp1);
        else if (j)
            strcat(temp, temp1);

        fputs(temp, stdout);
    }
    fclose(f1);
    fclose(f2);

    return 0;
}