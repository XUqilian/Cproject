#ifndef TRYCATCH_H
#define TRYCATCH_H

#include<iostream>
// #include<excption>
#include<stdexcept>
using std::cout;
using std::cin;
using std::endl;
using std::logic_error;

class erone : public logic_error 
{
    public:
        erone(): logic_error("argment error: the parameters are opp0site numbers."){}

};

class ertwo : public logic_error
{
    public:
        ertwo(): logic_error("argment error: there are partmeters <= 0."){}

};

#endif