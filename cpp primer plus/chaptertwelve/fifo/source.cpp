#include "head.h"

Fifo::~Fifo()
{
    while(front)
    {
        sttf *temp = front;
        front = front->next;
        delete temp;
    }
}

int Fifo::add()
{
    if(isfull())
    {
        cout << "fifo is full;" << endl;
        return 1;
    }

    sttf *temp = new sttf;
    temp->itm.set(rand()%LONG_MAX);

    if(NULL == front) 
    {
        real = front = temp;
    }
    else 
    {
        real->next = temp;
        real = temp;
    }
    cout << "this in:"<<temp->itm.valin() <<"\tthis out:" << temp->itm.valout()<<endl;
    num++;
    printf("%d\t",num);
    return 0;

}

int Fifo::del()
{

    if(isempty())
    {
        cout << "fifo is empty;" << endl;
        return 1;
    }    
    sttf *temp = front;
    front = front->next;
    delete temp;

    printf("\n%d is del.",num);
    num--;
    return 0;
}