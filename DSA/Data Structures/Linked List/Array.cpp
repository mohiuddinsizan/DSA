#include <iostream>

using namespace std;

class List
{
    int *arr;
    int size;
    int maxSize;
    int pos;

public:
    List(int chunkSize=1000)
    {
        maxSize = chunkSize;
        arr = (int*)malloc(sizeof(int)*maxSize);
        pos = 0;
        size =0;
    }

    void Insert(int item)
    {
        if(size==maxSize)
        {
            maxSize=(maxSize*2);
            int * arr2=(int *)realloc(arr, maxSize * sizeof(int));
            if (arr2 != nullptr)
            {
                arr = arr2;
            }
        }
        int temp = pos;
        if(pos==size-1)
        {
            arr[size]=item;

        }
        else
        {
            for(int i=size; i>temp; i--)
            {
                arr[i]=arr[i-1];
            }
            arr[temp]=item;
        }
        pos++;
        size++;
    }

    int remove()
    {
        if(pos == size) return 0;
        int ret=arr[pos];
        for(int i = pos; i < size - 1; i++)
        {
            arr[i] = arr[i+1];
        }
        if(pos==size-1 && pos > 0)
        {
            pos=pos-1;
        }
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

    int length()
    {
        return size;
    }

    int getValue()
    {
        return arr[pos];
    }

    int currPos()
    {
        return pos;
    }

    void display()
    {
        //cout<<pos<<" "<<size<<endl;
        //if(pos == -1) cout << "|";
        for(int i = 0; i <size; i++)
        {
            if(i == pos) cout << "|";
            cout << arr[i] <<" ";
        }
        //if(size==0) cout << "|";
        cout << endl;
    }
};
