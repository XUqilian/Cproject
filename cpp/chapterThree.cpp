#include <iostream>

using namespace std;

int three_one(void)
{
    const int constant = 12;
    float height;
    cout << "enter you height:";
    cin >> height;
    cout << "\nyou height is:" << height * constant << endl;
    return 0;
}

int three_two(void)
{
    float pounts; //英磅
    float foot;   //英尺
    float inch;   //英寸

    cout << "please enter your height in foot and inch.\n"
         << "what is your foot:";
    cin >> foot;
    cout << "\nwhat is your inch:";
    cin >> inch;
    cout << "enter you weight in pounts:";
    cin >> pounts;

    cout << "you bmi is:" << (pounts / 2.2) / ((((foot * 12) + inch) * (0.0254 / 1))) * (((foot * 12) + inch) * (0.0254 / 1))
         << "." << endl;

    return 0;
}

int three_three(void)
{
    int degrees;
    int minutes;
    int seconds;

    cout << "enter a latitude in degrees,minutes,and seconds" << endl;
    cout << "enter the degrees:";
    cin >> degrees;
    cout << "\nenter the minutes:";
    cin >> minutes;
    cout << "enter the seconds:";
    cin >> seconds;

    cout << degrees << "degrees," << minutes << "minutes," << seconds << "seconds="
         << degrees + (minutes / 60) + (seconds / 3600) << "degrees." << endl;

    return 0;
}

int three_four(void)
{
    long long secondes;
    cout << "enter seconds:";
    cin >> secondes;
    cout << secondes << "have " << (((secondes / 60) / 60) / 60) << "days,"
         << ((secondes / 60) / 60) << "hours,"
         << (secondes / 60) << "minutes,"
         << secondes % 60 << "secondes.";
    return 0;
}

int three_five(void)
{
    long cnumber;
    long wnumber;
    cout << "enter population for china:";
    cin >> cnumber;
    cout << "enter population for word's:";
    cin >> wnumber;
    cout << "the population of the china is"
         << ((double)cnumber / (double)wnumber) * 100 << "% of the word population.";
    return 0;
}

int three_six(void)
{
    int mile;   //英里
    int gallon; //加仑
    cout << "enter car mile number:";
    cin >> mile;
    cout << "\nenter car gallon number:";
    cin >> gallon;
    cout << "car ever mile need gasoline gallon:" << gallon / mile << endl;
    cout << "\nand car ever kilometer need gasoline kilogram:"
         << (gallon * 3.875) / (mile * (100 / 62.14)) << endl;
    return 0;
}

int three_seven(void)
{
    int kilogram;  //千克
    int kilometer; //千米
    cout << "enter car kilometer number:";
    cin >> kilometer;
    cout << "\nenter car kilogram number:";
    cin >> kilogram;
    cout << "car ever mile need gasoline gallon:" << kilogram / kilometer << endl;
    cout << "\nand car ever kilometer need gasoline kilogram:"
         << (kilogram / 3.875) / (kilometer * (62.14 / 100)) << endl;
    return 0;
}

int main()
{
    return 0;
}