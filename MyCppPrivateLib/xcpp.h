#pragma once
#ifndef CPP_H
#define CPP_H

#include<iostream>

    void errcin(void);

    int xgets(char *array,int count);   //从输入流获取一段字符串并存入数组 当遇到换行 字符串结尾或最大获取值时 再结尾加上字符串结束标志 函数返回获取字符数量 包括结束字符
    int xclearin();         //清理输入流剩下的字符 遇到换行结束
    
    int low(char *strl);   //字符串所有字符小写
    int sup(char *strl);    //字符串所有字符大写
    
#endif

