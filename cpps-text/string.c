//string.h
#include<stdio.h>

//copy
char *m_strcpy(char *str1,const char*str2)
{
    int ch;
    do{
        int i=0;
        ch=getc(str2);
        str1[i]=(char)ch;
        i++;
    }while(ch!='\0');//限制越界可以用i<n来限制
    return str1;//这个地方可以改善一下
}

//cat
char *m_strcat(char *str1,const char*str2)
{
    int i=0;
    int j=0;
    int ch;
    for(i;(ch=getc(str1))&&(ch!='\0');i++);
    do{
        ch=str2[j];
        str1[i+j]=str2[j];
        j++;
    }while(ch!='\0');
    return str1;
}

//cmp
int m_strcmp(const char *str1,const char*str2)
{
    int sum1=0,sum2=0;
    int ch;
    while((ch=getc(str1))&&(ch!='\0')) sum1+=ch;
    while((ch=getc(str2))&&(ch!='\0')) sum2+=ch;
    return sum1-sum2;
}

//len
char *m_strlen(const char*str1)
{
    int sum1=0;
    int ch;
    while((ch=getc(str1))&&(ch!='\0')) sum1++;
    return sum1;
}

//chr
char *m_strchr(char chr,const char*str1)
{
    int sum1=0;
    int*re=NULL;
    int ch;
    while((ch=getc(str1))&&(ch!='\0'))
    {
        if(ch==chr){
            re=&(str1[sum1]);
            break;
        }
        sum1++;
    }

    return re; 
}

//str
char *m_strstr(const char *str1,const char*str2)
{
    char*result=NULL;
    int judge=0;
    int sum1=0,sum2=0,sum3=0;
    int ch;
    while((ch=getc(str2))&&(ch!='\0')) sum1++;
    while((ch=getc(str2))&&(ch!='\0')) sum2+=ch;
    char*st=str1[0],*ed=str1[sum1];
    while((st!=ed)&&(ch=getc(st))) sum3+=ch;
    while(*ed!='\0'){
        int i=0;
        if(sum3==sum2){
            for(i;i<sum2;i++){
                if(*(st+i)!=str2[i])
                {
                    break;   
                }                
            }
            if(i==sum2){
                result=st;
            } 
        }
        ed++;
        sum3+=(*ed)-(*st);
        st++;
    }

    return result;
}