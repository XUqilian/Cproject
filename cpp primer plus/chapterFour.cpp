#include<iostream>
#include<string>
#include<vector>
#include<array>

using namespace std;

int four_one(void)
{
    string firstname,lastname;
    char letter;//字母
    int age;
    cout<<"what is you first name?";
    cin>>firstname;
    
    cout<<"\nwhat is you last name?";
    cin>>lastname;
    cout<<"\nwhat letter garde do you deserve?";
    cin>>letter;
    cout<<"\nwhat is you age?";
    cin>>age;

    cout<<"name:"<<lastname<<"'"<<firstname<<endl;
    cout<<"garde:"<<letter<<endl;
    cout<<"age:"<<age<<endl;
    
    return 0;

}

int four_two(void)
{
    string name;
    string dessert;//甜点
    cout<<"enter you name:";
    cin>>name;
    cout<<"\nenter you favorite dessert:";
    cin>>dessert;

    cout<<"i have some "<<dessert<<"for you,"<<name<<endl;
    
    return 0;

}

int four_three(void)
{
    char firstname[20];
    string lastname;
    cout<<"enter you first name?";
    cin>>firstname;
    cout<<"\nenter you last name?";
    cin>>lastname;

    cout<<"here's the information in you sigle string:"<<firstname+lastname<<endl;

    return 0;
}

int four_four(void)
{
    string firstname,name,lastname;
    cout<<"enter you first name?";
    cin>>firstname;
    cout<<"\nenter you last name?";
    cin>>lastname;
    name=firstname+','+lastname;
    cout<<name<<endl;

    return 0;
}

int four_five(void)
{
    struct candybar{
        char name[20];
        double weight;//重量
        int calorie;//卡路里
    };

    candybar snack{
        "mocha munch",2.3,350
    };

    cout<<"snack.name:"<<snack.name<<endl;
    cout<<"snack.calorie:"<<snack.calorie<<endl;
    cout<<"snack.calorie:"<<snack.calorie<<endl;

    return 0;
}

int four_six(void)
{
    struct candybar{
        char name[20];
        double weight;//重量
        int calorie;//卡路里
    };

    candybar cdb_ary[3]={0};    

    return 0;
}

int four_seven(void)
{
    struct pizza{
        char name[20];
        double diameter;//直径
        double weight;//重量
    };
    
    pizza first;

    cout<<"enter the pizza name:";
    cin.getline(first.name,20);
    cout<<"\nenter the pizza dismeter:";
    cin>>first.diameter;
    cout<<"\nenter the pizza weight:";
    cin>>first.weight;

    cout<<"first.name:"<<first.name<<endl;
    cout<<"first.diameter:"<<first.diameter<<endl;
    cout<<"first.weight:"<<first.weight<<endl;
    
    return 0;

}

int four_eight(void)
{
    struct pizza{
        char name[20];
        double diameter;//直径
        double weight;//重量
    };

    pizza* p_pizza=new pizza;

    cout<<"\nenter the pizza dismeter:";
    cin>>p_pizza->diameter;
    cout<<"enter the pizza name:";
    cin.getline(p_pizza->name,20);
    cout<<"\nenter the pizza weight:";
    cin>>p_pizza->weight;

    delete p_pizza;

    return 0;
}

int four_nine(void)
{
    struct candybar{
        char name[20];
        double weight;//重量
        int calorie;//卡路里
    };

    vector<candybar> vcr_cdb;
    
    return 0;
}

int four_ten(void)
{
    array<double,3> runtime;
    cout<<"\nenter you first run 40 meter with time:";
    cin>>runtime[0];
    cout<<"\nenter you last run 40 meter with time:";
    cin>>runtime[1];
    cout<<"\nenter you third time run 40 meter with time:";
    cin>>runtime[2];

    cout<<"\nyou garde average for run 40 meter time:"
    <<(runtime[0]+runtime[1]+runtime[2])/3<<endl;

    return 0;
}

int main()
{
    return 0;
}