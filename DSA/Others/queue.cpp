#include<iostream>
using namespace std;
class Queue{
    int size;
    int * arr;
    int front,rear;
    int elements;
public :
    Queue(){
        this->size = 3;
        arr = new int[size];
        front = -1;
        rear = -1;
        elements = 0;
    }
    void insert(int data){
        if(elements>=size){
            int * arr2 = new int[size];
            for(int i = 0;i<elements;i++){
                arr2[i] = arr[i];
            }
            delete [] arr;
            size*=2;
            arr = new int [size];
            for(int i = 0;i<elements;i++){
                arr[i] = arr2[i];
            }
            delete [] arr2;
        }
        if(front == -1){
            front++;
            rear++;
            arr[(front%size)] = data;
            elements++;
        }
        else{
            arr[(++rear)%size] = data;
            elements++;
        }
    }
    void display(){
        if(elements<=0){
            cout<<"empty queue ! "<<endl;
            return ;
        }
        for(int i = 0;i<elements;i++){
            cout<<arr[(front+i)%size]<<" ";
        }
        cout<<endl;
    }
    void pop(){
        if(elements<=0){
            cout<<"Queue is already empty!!!"<<endl;
            return ;
        }
        front++;
        elements--;
    }
};
int main(){
    Queue ll;
    while(true){
        cout<<" 1 -> insert "<<endl;
        cout<<" 2 -> append "<<endl;
        cout<<" 3 -> display "<<endl;
        cout<<" 4 -> clear "<<endl;
        cout<<" 5 -> currPos "<<endl;
        cout<<" 6 -> moveToStart "<<endl;
        cout<<" 7 -> moveToEnd "<<endl;
        cout<<" 8 -> length "<<endl;
        cout<<" 9 -> moveToPos "<<endl;
        cout<<" 10 -> prev "<<endl;
        cout<<" 11 -> next "<<endl;
        cout<<" 11 -> remove "<<endl;
        int operation;cin>>operation;
        if(operation == 1) {
            int x;cin>>x;
            ll.insert(x);
        }
        // if(operation == 2){
        //     int x;cin>>x;
        //     ll.append(x);
        // }
        if(operation == 3){
            ll.display();
        }
        // if(operation == 4){
        //     ll.clear();
        // }
        // if(operation == 5){
        //     ll.display();
        // }
        // if(operation == 6){
        //     ll.moveToStart();
        // }
        // if(operation == 7){
        //     ll.moveToEnd();
        // }
        // if(operation == 8){
        //     cout<<ll.length()<<endl;
        // }
        // if(operation == 9){
        //     int x;cin>>x;
        //     ll.moveToPos(x);
        // }
        // if(operation == 10){
        //     ll.prev();
        // }
        // if(operation == 11){
        //     ll.next();
        //}
        if(operation == 12){
            ll.pop();
        }
    }
    return 0;
}