#include <iostream>

using namespace std;
template<typename T>
class List
{
    T *arr;
    int size;
    int maxSize;
    int pos;
    int head;
    int tail;

public:
    List(int chunkSize=10)
    {
        maxSize = chunkSize;
        arr = (T*)malloc(sizeof(T)*maxSize);
        pos = 0;
        size =0;
        head= -1;
        tail=-1;
    }

    void Insert(T item)
    {
        //cout<<"insert called"<<endl;
        if(size==maxSize)
        {
            //cout<<"first if called"<<endl;
            maxSize=(maxSize*2);
            T * arr2=(T *)realloc(arr, maxSize * sizeof(T));
            if (arr2 != nullptr)
            {
                arr = arr2;
            }
        }

        int temp = pos;
        if(head==-1 && tail == -1)
        {
            //cout<<"first value inserted"<<endl;
            head =0;
            tail=0;
            arr[tail]=item;
            size++;
        }
        /*else
        {
            for(int i=size; i>temp; i--)
            {
                arr[i]=arr[i-1];
            }
            arr[temp]=item;
        }
        pos++;
        size++;*/
        else
        {
            //cout<<"tail value inserted"<<endl;
            tail = (tail+1)%maxSize;
            //cout<<"new tail is "<<tail<<endl;
            arr[tail]=item;
            size++;
        }
    }

    T remove()
    {
        if(size == 0)
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        T ret=arr[head];

        /*if(pos == size) return 0;
        for(int i = pos; i < size - 1; i++)
        {
            arr[i] = arr[i+1];
        }
        if(pos==size-1 && pos > 0)
        {
            pos=pos-1;
        }*/
        head++;
        size--;
        return ret;
    }

    void next()
    {
        /* if(pos==size-1)
             return ;*/
        pos++;
    }

    void prev()
    {
        if(pos==0)
            return;
        pos--;
    }

    void moveToPos(int p)
    {
        pos = p;
    }

    void moveToStart()
    {
        pos = 0;
    }

    void moveToEnd()
    {
        pos = size-1;
    }

    int lengt_h()
    {
        return size;
    }

    T getValue()
    {
        if(size ==0)
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[head];
    }
    T getLastValue()
    {
        if(size ==0)
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[tail];
    }

    int currPos()
    {
        return pos;
    }

    void display()
    {
        //cout<<pos<<" "<<size<<endl;
        //if(pos == -1) cout << "|";
        int temp = head ;
        for(int i = 0 ; i <size; i++)
        {

            cout << arr[temp] <<" ";
            temp=(temp+1)%maxSize;
        }
        //if(size==0) cout << "|";
        cout << endl;
    }
    void Clear()
    {
        head= -1;
        tail = -1;
        size=0;
    }
};
