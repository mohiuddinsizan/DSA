#include<bits/stdc++.h>
using namespace std;

void maxHeapify(int arr[],int i,int length){
    int left = i*2+1;
    int right = i*2+2;
    int largest = i;
    if(left<length){
        if(arr[left]>arr[i]) largest = left;
    }
    if(right<length){
        if(arr[right]>arr[largest]) largest = right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        maxHeapify(arr,largest,length);
    }  
}

void buildheap(int arr[],int length){
    cout<<length<<endl;
    for(int i = (length/2)-1;i>=0;i--){
        maxHeapify(arr,i,length);
    }
}

void display(int arr[],int length){
    int counter = 0;
    int k = 0;
    for(int i = 0;i<length;i++){
        cout<<arr[i]<<" ";
        counter++;
        if(counter == pow(2,k)){
            k++;
            cout<<endl;
            counter = 0;
        }
    }
}

void heapsort(int arr[],int length){
    for(int i = length-1;i>=0;i--){
        swap(arr[i],arr[0]);
        length--;
        maxHeapify(arr,0,length);
    }
}

int main(){
    
    int arr []= {4,1,3,2,16,9,10,14,8,7};
    int length = sizeof(arr)/sizeof(arr[0]);

    display(arr,length);
    cout<<endl;
    buildheap(arr,length);
    display(arr,length);
    cout<<endl;
    heapsort(arr,length);
    for(int i = 0;i<length;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}