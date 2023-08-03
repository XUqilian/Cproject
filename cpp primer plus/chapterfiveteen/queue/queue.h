#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>

using std::cout;
using std::endl;

template<class T>
class Queue{
    private:
        class Node{
            public:
                T ele;
                Node * next;
                Node(const T & t) : ele(t), next(NULL) {}
        };
    private:
        const int len;  // lenght for queue
        Node * head;
        Node * temp;
        int size = 0;     //  element for queue
    public:
        Queue(int num = 3):len(num),head(NULL),temp(NULL){}
        ~Queue(){}

        bool isfull(){ return size == len; }
        bool isempty(){ return 0 == size; }
        void push(const T &);
        void pop();

};


// template<class T>
// void Queue<T>::push(const T & t)
// {
//     if(!isfull())
//     {
//         Node * tt = new Node(t);
//         // tt->ele = t;
//         // tt->next = NULL;
        
//         if(head == NULL)
//             head = tt;
//         else temp->next = tt;
//         temp = tt;
//         size++;
//     }
// }

template<class T>
void Queue<T>::push(const T & t)
{
    if(!isfull())
    {       
        Node * tt = new Node(t);
        if(head == NULL){
            head = new Node(t);
            temp = head;
        }else{
            temp->next = new Node(t);
            temp = temp->next;
        }
        size++;
    }
}

template<class T>
void Queue<T>::pop()
{
    if(!isempty())
    {   
        Node * t;
        t = head;
        head = head->next;
        cout << t->ele << " is pop." << endl;
        delete t;
        size--;
    }
}

#endif