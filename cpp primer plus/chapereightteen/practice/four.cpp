#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>

using namespace std;

int main(void)
{
    auto lamb = [](int x){cout << x << ' ';};
    
    list<int> one(5,2);
    int stuff[5] = {1,2,4,8,6};
    list<int> two;
    two.insert(two.begin(),stuff,stuff+5);
    int more[6] = {6,4,2,4,6,5};
    list<int> three(two);
    three.insert(three.end(),more,more+6);
    
    for_each(one.begin(),one.end(),lamb);
    for_each(two.begin(),two.end(),lamb);
    for_each(three.begin(),three.end(),lamb);
    three.remove(2);
    for_each(three.begin(),three.end(),lamb);
    three.splice(three.begin(),one);
    for_each(three.begin(),three.end(),lamb);
    for_each(one.begin(),one.end(),lamb);
    three.unique();
    for_each(three.begin(),three.end(),lamb);
    return 0;
}