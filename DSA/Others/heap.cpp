#include<bits/stdc++.h>
using namespace std;
class myHeap{
    int size;
    int * arr;
    int element;
    public:
    myHeap(){
        this->size = 2;
        arr = new int[size];
        element = 0;
    }
    void insert(int data){
        if(element>=size){
            int * arr2 = new int[size];
            for(int i = 0;i<element;i++)
                arr2[i] = arr[i];
            delete [] arr;
            size*=2;
            arr = new int[size];
            for(int i = 0;i<element;i++)
                arr[i] = arr2[i];
        }
        arr[element] = data;
        element++;
        int child = element - 1;
        int parent = (child-1)/2;
        while(true){
            if(arr[parent]>arr[child]  && parent>=0 && child > 0){
                swap(arr[parent],arr[child]);
                child = parent;
                parent = child/2;
            }
            else break;
        }
    }
    void display(){
        int counter = 0;
        int k = 0;
        for(int i = 0;i<element;i++){
            cout<<arr[i]<<" ";
            counter++;
            if(counter == pow(2,k)){
                k++;
                cout<<endl;
                counter = 0;
            }
        }
    }
    void extractmin(){
        if(element>0){
            int index = 0;
            arr[index] = arr[element-1];
            element--;
            while(true){
                int left_child = index*2 + 1;
                int right_child = index*2 + 2;
                if(left_child<element && right_child<element){
                    if(arr[left_child]<arr[right_child] && arr[left_child]<arr[index]){
                        swap(arr[left_child],arr[index]);
                        index = left_child;
                        cout<<"hey"<<endl;
                    }
                    else if(arr[right_child]<arr[left_child] && arr[right_child]<arr[index]){
                        swap(arr[right_child],arr[index]);
                        index = right_child;
                        cout<<"hello"<<endl;
                    }
                    else break;
                }
                else if(left_child<element){
                    if(arr[left_child]<arr[index]){
                        swap(arr[left_child],arr[index]);
                        index = left_child;
                        cout<<"bhelloo"<<endl;
                    }
                    else break;
                }
                else if(right_child<element){
                    if(arr[right_child]<arr[index]){
                        swap(arr[right_child],arr[index]);
                        index = right_child;
                        cout<<"ckelloo"<<endl;
                    }
                }
                else break;
            }
        }
    }
};
int main(){

    myHeap h;
    while(true){
        int op ;cin>>op;
        if(op == 1){
            int x;cin>>x;
            h.insert(x);
        }
        if(op == 2){
            h.display();
        }
        if(op == 3){
            h.extractmin();
        }
    }
    
    return 0;
}