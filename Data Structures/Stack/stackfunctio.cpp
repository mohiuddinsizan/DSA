#include<iostream>
using namespace std;

template <typename T>
class Stack
{
    T *A;
    int capacity;
    int i=-1;

public:
    Stack(int chunkSize)
    {
        A= new T[chunkSize];
        capacity = chunkSize;
    }
    void push(T t)
    {
        i++;
        if(i>=capacity)
        {
            //int l = capacity;
            int newcapacity=capacity*2;
            T * A2 = new T[newcapacity];
            for(int a=0; a<capacity; a++)
            {
                A2[a]=A[a];
            }
            delete [] A;
            A=A2;
        }
        A[i]=t;
    }
    void print()
    {
        for(int j=0; j<=i; j++)
        {
            cout<<A[j]<<" ";
        }
        cout<<endl;
    }
    T pop()
    {
        if(i<0)
        {
            cout<<"stack is empty ! "<<endl;
            return -1;
        }

        int x=A[i];
        i--;
        return x;
    }
    int length()
    {

        return i+1;
    }
    T topValue()
    {
        return A[i];
    }
    bool isEmpty()
    {
        if(i>=0)
        {
            return false;
        }
        else if(i<0)
        {
            return true;
        }
    }
    void clear()
    {
        i=-1;
        //delete[] A;
    }
    void print2()
    {
        for(int j=i; j>=0; j--)
        {
            cout<<A[j]<<" ";
        }
        cout<<endl;
    }
    ~Stack()
    {
        delete[] A;
    }

};
