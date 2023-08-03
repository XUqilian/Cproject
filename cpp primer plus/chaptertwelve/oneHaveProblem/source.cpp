#include"head.h"

Cow::Cow()
{
    name[0] = '\0';
    weight = 0;
    hobby = NULL;
}

Cow::Cow(const char * nm,const char * ho,double wt)
{
    weight = wt;
    // int i = 0;
    // {    //printf("%s,%s,%d,%d\t",nm,ho,wt,weight);    //将 double 传给 int 会让其输出变成 0  类型与格式化字符不同输出是未定义的      
    //     do{
    //         name[i] = nm[i];
    //         // printf("%c\t",nm[i]);
    //         // name[i] = nm[i++];     //在这里实现出现了问题 i 在这里先进行了递增 使之变成 name[1] = nm[1]
    //         // printf("%d:%c\t",i,name[i]);    
    //     }while(nm[++i]!='\0' && i < 19);
    //     name[i] = '\0';
    // }     // 傻逼行为 忘了还有 strncpy() 函数

    strncpy(name,nm,20);
    name[19] = '\0';

    // i = 0;
    // while(ho[i]) i++;
    hobby = new char[strlen(ho) + 1];
    strcpy(hobby,ho);

}

Cow::Cow(const Cow &c){
    printf("call copyfun!\n");
    strcpy(name,c.name);

    // delete []hobby; // delete hobby; // free(hobby); 
    // 当对 NULL 释放时出现了未知错误中断了程序 即便是使用 free
    // warning: Critical error detected c0000374
    // 不用倒是没啥问题 可能是这版本的并不支持 delete NULL 吧 
    
    // int i = 0;
    // while(c.hobby[i]) i++;
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby,c.hobby);

    weight = c.weight;
}

Cow & Cow::operator=(const Cow &c)
{
    printf("call assignment fun!\n");

    if(this == &c)    //*this 是对象 没有重载==时 是无法进行判断相等的
        return *this;

    strcpy(name,c.name);
    weight = c.weight;

    delete []hobby;
    hobby = NULL;
    
    // int i = 0 ;
    // while(c.hobby[i++]);
    hobby = new char[strlen(c.hobby)];

    strcpy(hobby,c.hobby);
    return *this;
}

void Cow::show()const
{
    printf("call showfun!\n");
    cout << "name:" << name << "\thobby:" << hobby << "\tweight:" << weight << endl;
}