//读取的ei数量
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int ei(const char *);

int main()
{
    char ch;
    char *  strt = NULL;
    char * stro = NULL;
    char *t = NULL;
    t = (char *)malloc(100 * sizeof(char));

    char *p[100];
    int j = 0, i = 0;
    p[j] = t;

    for (i = 0; (ch = getchar())&&(ch != '#'); i++)
    {

        t[i] = ch;

        if (i == 98)
        {
            j++;

            t[99] = '\0';
            stro = t;

            i = 0;
            //检查拼接
            if (strt)
            {
                strcat(strt, stro);
            }
            else
            {
                strt = stro;
            }
            //再次分配
            t = (char *)malloc(100 * sizeof(char));
            p[j] = t;
        }
    }
    t[i + 1] = '\0';
    stro = t;
    if (strt)//检查拼接
    {
        strcat(strt, stro);
    }
    else
    {
        strt = stro;
    }

    //检查
    int cnt = 0;
    cnt = ei(strt);
    printf("%d", cnt);

    while (j >= 0)
    {
        free(p[j]);
        j--;
    }
    return 0;
}

int ei(const char *str)
{
    int cnt = 0;
    char cho = 0, cht = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        cho = str[i];
        
        if (cht == 'e' && cho == 'i')
            cnt++;
        cht = cho;
        
    }

    return cnt;
}