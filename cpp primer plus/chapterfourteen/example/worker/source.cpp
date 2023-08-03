#include"head.h"

void Worker::set()
{
    printf("enter name:");
    cin >> name;
    while(getchar() != '\n');
    printf("enter id:");
    scanf("%d",&id);
    while(getchar() != '\n');
    printf("\n");
    // cin >> name;
    // cin >> id;
}

void Worker::show()const
{
    // cout << "name:" << name << "\nid:" << id << endl;
    // printf(this->name); //error : multiple  fedinetion  重复定义
    printf(name.c_str());
    printf("\nid:%d\n",id);
}



void Singer::set()
{
    Worker::set();
    printf("enter panache:");
    scanf("%d",&panache);
    while(getchar() != '\n');
    printf("\n");
}

ostream & operator<<(ostream & os,const Singer & t)
{
    t.show();
    return os << "panache:" << t.panache << endl;
}


void Waiter::set()
{
    Worker::set();
    printf("enter voice:");
    scanf("%d",&voice);
    while(getchar() != '\n');
    printf("\n");
}

ostream & operator<<(ostream &os ,const Waiter &t) 
{
    t.show();
    return os << "voice:" << t.voice << endl;
}


