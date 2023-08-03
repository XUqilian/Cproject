#include<iostream>
#include<initializer_list>      //也可以用于类初始化

using namespace std;

double sum(initializer_list<double> ls)
{
    double result;
    for(double x : ls)
        result += x;
    return result;
}
double averge(const initializer_list<double> ls)
{
    double avg;
    int i = ls.size();// int i = 0;

    for(double x : ls)
    {
        // i++;
        avg += x;
    }
    return avg/i;
}

int main(void)
{
    cout << "sum({1.0,2.0,3,4.0,5}):" << sum({1.0,2.0,3,4.0,5}) << "\naverge({1.0,2.0,3,4.0,5}):" << averge({1.0,2.0,3,4.0,5}) << endl;
    initializer_list<double> ar = {1.0,2.0,3,4.0,5};
    cout << "initializer_list<double> ar = {1.0,2.0,3,4.0,5}" << endl;
    cout << "sum({1.0,2.0,3,4.0,5}):" << sum(ar) << "\naverge({1.0,2.0,3,4.0,5}):" << averge(ar) << endl; 
    


    return 0;
}