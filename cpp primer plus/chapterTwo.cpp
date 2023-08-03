#include <iostream>
#include <cstdio>

using namespace std;

int two_one(void)
{
    printf("my name is qilian!\n");
    printf("my address is china!");

    cout << "my name is qilian!" << endl;
    cout << "my address is china!" << endl;

    return 0;
}

int two_two(void)
{
    long distance;
    scanf("%d", &distance);

    cin >> distance;

    return distance;
}

inline void two_three_o(void) { printf("three blind mice\n"); /*cout<<"three blind mice"<<endl;*/ }
inline void two_three_t(void) { printf("see how they run\n"); /*cout<<"see how they run"<<endl;*/ }
int two_three(void)
{
    two_three_o();
    two_three_o();
    two_three_t();
    two_three_t();
    return 0;
}

int two_four(void)
{
    int age = 0;
    printf("tell me your age:");
    scanf("%d", &age);
    printf("you've lived  %d mounth in your life.", age * 12);

    cout << "tell me your age:";
    cin >> age;
    cout << "you've lived " << age * 12 << " mounth in your life." << endl;

    return 0;
}

int two_five(void)
{
    float celsius = 0;
    printf("please enter the current celsius in now:");
    scanf("%f", &celsius);
    printf("the current fahrenheit is %f", (celsius * 1.8) + 32);

    cout << "please enter the current celsius in now:";
    cin >> celsius;
    cout << "the current fahrenheit is " << (celsius * 1.8) + 32 << endl;

    return 0;
}

int two_six(void)
{
    double distance;
    printf("enter the number of light years:");
    scanf("%f", distance);
    printf("\n%f light years = %f astronomcal units.", distance, distance * 63240);

    cout << "enter the number of light years:";
    cin >> distance;
    cout << "\n"
         << distance << " light years = " << distance * 63240 << "astronomcal units.";

    return 0;
}

int two_seven(int time, int minutes)
{
    printf("enter the number of hours:%d\n\
    enter the number of minutes:%d\n\
    time:%d:%d",
           time, minutes, time, minutes);

    cout << "enter the number of hours:" << time << "\nenter the number of minutes:" << minutes << "\ntime:" << time << ":" << minutes << endl;

    return 0;
}

int main(void)
{
    return 0;
}