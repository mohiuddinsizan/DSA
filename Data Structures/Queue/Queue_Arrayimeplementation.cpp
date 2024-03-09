#include<iostream>
#include"Array.cpp"
using namespace std;


template<typename T>

class QF
{
    List<T> Queue;

public:

    void enqueue(T p)
    {
        Queue.Insert(p);
    }
    void print()
    {
        Queue.display();
    }

    T dequeue()
    {
        return Queue.remove();
    }

    int length()
    {
        return Queue.lengt_h();
    }

    T front()
    {
        if(Queue.lengt_h() == 0)
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return Queue.getValue();
    }
    T back()
    {
        if(Queue.lengt_h() == 0)
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return Queue.getLastValue();
    }

    bool Is_empty()
    {
        if(Queue.lengt_h()==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void clear()
    {
        Queue.Clear();
    }
};
