#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;

template<typename T>

class maxPriorityQueue
{
    T *arr;
    int size=-1;
    int maxSize = 1;
    int parentIndex;
    int childIndex;
public:

    maxPriorityQueue()
    {
        arr = new T [maxSize];
    }
    void insert(int x)
    {
        size++;
        if(size>=maxSize)
        {
            maxSize = maxSize*2;
            T * arr2 = new T [maxSize];
            for(int i = 0; i<size; i++)
            {
                arr2[i]=arr[i];
            }
            delete [] arr;
            arr = new T [maxSize];
            for(int i = 0; i<size; i++)
            {
                arr[i]=arr2[i];
            }
            delete [] arr2;
        }
        childIndex = size;
        arr[childIndex]=x;
        parentIndex = (childIndex-1)/2;
        while(parentIndex>=0 && arr[parentIndex]<arr[childIndex])
        {
            swap(arr[childIndex],arr[parentIndex]);
            childIndex = parentIndex;
            parentIndex = (childIndex-1)/2;
        }

    }
    void findMax(ofstream& outfile)
    {
        if(size>=0) outfile<<to_string(arr[0])<<endl;

        else
        {
            outfile<<"Heap is empty"<<endl;
        }
    }
    T extractMax()
    {
        if(size>=0)
        {
            T r = arr[0];
            arr[0]=arr[size];
            size--;
            int current = 0;
            while(true)
            {
                int leftIndex = current*2+1;
                int rightIndex = current*2+2;
                if(leftIndex<=size && rightIndex <=size)
                {
                    if(arr[leftIndex]>arr[rightIndex] && arr[leftIndex]>arr[current])
                    {
                        swap(arr[current],arr[leftIndex]);
                        current = leftIndex;
                    }
                    else if(arr[rightIndex]>=arr[leftIndex] && arr[rightIndex]>arr[current])
                    {
                        swap(arr[rightIndex],arr[current]);
                        current = rightIndex;
                    }
                    else break;
                }
                else if(leftIndex<= size)
                {
                    if(arr[leftIndex]>arr[current])
                    {
                        swap(arr[current],arr[leftIndex]);
                        current = leftIndex;
                    }
                    else break;
                }
                else if(rightIndex<=size)
                {
                    if(arr[rightIndex]>arr[current])
                    {
                        swap(arr[current],arr[rightIndex]);
                        current = rightIndex;
                    }
                    else break;
                }
                else break;
            }
            return r;
        }
        else
        {
            cout<<"Heap is empty"<<endl;
            return -1;
        }
    }
    void increaseKey(int i,T x,ofstream& outfile)
    {
        if(i<0 || i>size)
        {
            outfile<<"Invalid index"<<endl;
        }
        else if(arr[i]>x)
        {
            outfile<<"New key is not larger than the previous key"<<endl;
        }
        else
        {
            arr[i] = x;
            while(true)
            {
                parentIndex = (i-1)/2;
                if(arr[i]>arr[parentIndex] && parentIndex>=0)
                {
                    swap(arr[i],arr[parentIndex]);
                    i = parentIndex;
                }
                else break;
            }
            outfile<<"Key increased!"<<endl;
        }
        return ;
    }
    void decreaseKey(int i,T x,ofstream& outfile)
    {
        if(i<0 || i>size)
        {
            outfile<<"Invalid index"<<endl;
        }
        else if(arr[i]<x)
        {
            outfile<<"New key is not smaller than the previous key"<<endl;
        }
        else
        {
            arr[i] = x;
            while(true)
            {
                int left_index = i*2+1;
                int right_index = i*2+2;

                if(left_index<=size && right_index <=size)
                {
                    if(arr[left_index]>arr[right_index] && arr[left_index]>arr[i])
                    {
                        swap(arr[left_index],arr[i]);
                        i = left_index;
                    }
                    else if(arr[right_index]>arr[left_index] && arr[right_index]>arr[i])
                    {
                        swap(arr[right_index],arr[i]);
                        i = right_index;
                    }
                    else break;
                }
                else if(left_index<=size)
                {
                    if(arr[left_index]>arr[i])
                    {
                        swap(arr[left_index],arr[i]);
                        i = left_index;
                    }
                    else break;
                }
                else if(right_index<=size)
                {
                    if(arr[right_index]>arr[i])
                    {
                        swap(arr[right_index],arr[i]);
                        i = right_index;
                    }
                    else break;
                }
                else break;
            }
            outfile<<"Key decreased!"<<endl;
        }
        return ;
    }
    void print(ofstream& outfile)
    {
        if(size<0)
        {
            outfile<<"Heap is empty"<<endl;
            return ;
        }

        outfile<<"No of elements: "<<to_string(size+1)<<endl;
        int counter = 0;
        int level = 0;
        for(int i = 0; i <=size ; i++)
        {
            outfile<<to_string(arr[i])<<"	";
            counter++;
            if(counter == pow(2,level))
            {
                outfile<<endl;
                level++;
                counter=0;
            }
        }
        outfile<<endl;
    }
    void sort(ofstream& outfile)
    {
        if(size<0)
        {
            outfile<<"Heap is empty"<<endl;
            return ;
        }
        int Size = size+1;
        T * arr2 = new T[Size];
        for(int i = 0; i<Size; i++)
        {
            arr2[i]=arr[i];
        }
        int counter = 0;
        int level = 0;
        outfile<<"No of elements: "<<to_string(size+1)<<endl;
        T * sorted_array = new T [Size];
        for(int i = 0; i<Size; i++)
        {
            sorted_array[i]=arr[0];
            extractMax();
        }

        for(int i = Size-1; i >=0 ; i--)
        {
            outfile<<to_string(sorted_array[i])<<"	";
            counter++;
            if(counter == pow(2,level))
            {
                outfile<<endl;
                level++;
                counter=0;
            }
        }
        for(int i = 0; i<Size; i++)
        {
            arr[i]=arr2[i];
            size++;
        }
        delete [] arr2;
        delete [] sorted_array;
    }

};
