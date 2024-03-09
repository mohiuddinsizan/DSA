#include<bits/stdc++.h>
using namespace std;

class FibonacciHeap{

    public:

    int size = 0;

    class Node{

        public:

        int key;
        int value;
        Node * parent;
        Node * child;
        Node * left;
        Node * right;
        int degree;
        bool marked;
        bool visited;

        Node(int key,int value){
            this->key = key;
            this->value = value;
            parent = NULL;
            child = NULL;
            left = this;
            right = this;
            marked = false;
            visited = false;
            degree = 0;
        }
    };

    Node * minimum;

    FibonacciHeap * create_heap(){
        minimum = NULL;
        return this;
    }

    void Insert(int key,int value){

        size++;

        Node * temp =new  Node(key,value);

        if(minimum == NULL){
            minimum = temp;
            minimum->left = minimum;
            minimum->right = minimum;
        }

        else{
            minimum->left->right=temp;
            temp->right = minimum;
            temp->left = minimum->left;
            minimum->left = temp;

            if(temp->key > minimum->key){
                minimum = temp;
            }
        }
    }

    void printTree(Node * root,int treeNum){
        
        cout<<"Tree "<<treeNum<<" : ";
        cout<<"("<<root->key<<","<<root->value<<")";

        printChilds(root);

        if(root->right != NULL  && root->right != minimum){
                root = root->right;
                printTree(root,treeNum+1);
        }
        
    }

    void printChilds(Node * root){
        
        if(root->child == NULL){
            return;
        }
        Node * temp = root->child;
        cout<<"-> ("<<temp->key<<","<<temp->value<<")";

        while(temp->right!=NULL && temp->right != root->child){
            
            temp=temp->right;

            cout<<",("<<temp->key<<","<<temp->value<<")";
        }
        cout<<endl;

        temp = root->child;
        // cout<<"temp "<<temp->right->child->key<<endl;

        if(temp->child!=NULL){
            cout<<"         ("<<temp->key<<","<<temp->value<<"),";
            printChilds(temp);
        }
        
        while(temp->right!=NULL && temp->right != root->child){
            
            temp=temp->right;

            if(temp->child!=NULL){
                cout<<"         ("<<temp->key<<","<<temp->value<<")";
                printChilds(temp);
            }
        }

    }

    FibonacciHeap * welding(FibonacciHeap * FH2){

        Node * FH_MIN_RIGHT = minimum->right;
        Node * FH2_MIN = FH2->minimum;
        Node * FH2_MIN_RIGHT = FH2->minimum->right;

        FH2_MIN_RIGHT->left = minimum;
        minimum->right = FH2_MIN_RIGHT;
        FH2->minimum->right = FH_MIN_RIGHT;
        FH_MIN_RIGHT->left = FH2_MIN;

        if(minimum->key < FH2_MIN->key){
            minimum = FH2_MIN;
        }
        
        return this;
    }

    bool Increase_Key(Node * root, int value,int key) {
        
        if (root == NULL)
            return false;

        if (root->value == value){
            if(root->key > key){
                cout<<"given key is less than the previous key !"<<endl;
                return false;
            }
            root->key = key;
            Node * temp = root->parent;
            if(temp != NULL){
                if(temp->key < root->key){
                    Node * temp2 = minimum->left;
                    temp2->right = root;
                    root->left = temp2;
                    root->right = minimum;
                    minimum->left = root;
                    root->parent = NULL;
                    if(temp != NULL){
                        if(temp->marked == false){
                            temp->marked = true;
                        }
                        else{
                            while(temp!=NULL){
                                Node * new_node = temp->parent;
                                Node * temp3 = minimum->left;
                                temp3->right = temp;
                                temp->left = temp3;
                                temp->right = minimum;
                                minimum->left = temp;
                                temp->parent = NULL;
                                temp->marked = false;
                                temp = new_node;
                                if(temp!=NULL){
                                    if(temp->marked == false){
                                        temp->marked = true;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            
            if(root->key > minimum->key){
                minimum = root;
            }
            return true;
                    Node* child = root->child;

            while (child != nullptr) {
                if (Increase_Key(child, value, key))
                {
                    return true;
                }
                child = child->right;
                if (child == root->child)
                    break;
            }
        }

        Node * temp = root->right;

        while(temp != minimum && temp != nullptr){
            if(Increase_Key(temp,value,key))
            {
                return true;
            }
            temp = temp->right;
            if(temp == minimum) break;
        }

        return false;
    }

    void Delete_max(){
        //cout<<minimum->key<<" "<<minimum->value<<endl;
        size--;
        Node * min_child = minimum->child;
        Node * min_right = minimum->right;
        Node * min_left = minimum->left;
        //cout<<min_right->key<<" "<<min_right->value<<endl;
        //cout<<min_left->key<<" "<<min_left->value<<endl;
        if(min_child!=NULL){
            Node * min_child_left = min_child->left;
            Node * min_child_right = min_child->right;
            min_child->left = min_left;
            min_left->right = min_child;
            min_child->left->right = min_right;
            min_right->left = min_child->left;
        }
        else{
            min_left->right = min_right;
            min_right->left = min_left;
        }
        minimum = min_right;
        //cout<<minimum->key<<" "<<minimum->value<<endl;
        //printTree(minimum,0);
        consolidation();
        //printTree(minimum,0);
    }

    void consolidation(){
        Node * root_holder = minimum;
        Node * Starter = minimum;
        int x = size_of_mainroot();
        Node * Arr [int(log2(x)+1)];
        //cout<<int(log2(x)+1)<<endl;

        for(int i = 0;i<int(log2(x)+1);i++){
            Arr[i] = NULL;
        }

        for(int i = 0;i<x;i++){
            //cout<<Starter->key<<endl;
            if(Starter->key > root_holder->key){
                root_holder = Starter;
            }

            int deg = Starter->degree;

            if(Arr[deg] == NULL){
                Arr[deg] = Starter;
                Starter = Starter->right;
            }

            else{
                Node * Existing = Arr[deg];
                Node * temp = Starter;
                Starter = Starter->right;
                if(Existing->key > temp->key){
                    Node * left_of_temp = temp->left;
                    Node * right_of_temp = temp->right;
                    Node * Child_of_Existing = Existing->child;
                    if(Child_of_Existing == NULL){
                        Existing->child = temp;
                        temp->parent = Existing;
                        temp->left = temp;
                        temp->right = temp;
                    }
                    else{
                        Node * left_child_exs = Child_of_Existing->left;
                        left_child_exs->right = temp;
                        temp->left = left_child_exs;
                        temp->right = Child_of_Existing;
                        Child_of_Existing->left = temp;
                    }
                    left_of_temp->right = right_of_temp;
                    right_of_temp->left = left_of_temp;
                    Arr[Existing->degree] = NULL;
                    Existing->degree = Existing->degree + 1;
                    if(Arr[Existing->degree] == NULL)
                        Arr[Existing->degree] = Existing;
                    else{
                        Starter = Existing;
                        x++;
                    }
                }
                else{
                    Node * left_of_existing = Existing->left;
                    Node * right_of_existing = Existing->right;
                    Node * Child_of_temp = temp->child;

                    //cout<<temp->child->key<<endl;
                    //cout<<temp->key<<" "<<Existing->key<<endl;
                    // if(Child_of_temp == NULL){
                        
                    //     Child_of_temp = Existing;
                    //     Existing->parent = temp;
                    //     Existing->left = Existing;
                    //     Existing->right = Existing;
                    //     cout<<Child_of_temp->key<<" "<<Child_of_temp->parent->key<<endl;
                    //     //cout<<Existing->key<<" "<<Existing->parent->key<<endl;
                    // }

                    if (Child_of_temp == NULL) {
                        temp->child = Existing; // Make Existing a child of temp
                        Existing->parent = temp;
                        Existing->left = Existing;
                        Existing->right = Existing;
                        //cout << Existing->key << " " << Existing->parent->key << endl;
                    }
                    else{
                        Node * left_child_temp = Child_of_temp->left;
                        left_child_temp->right = Existing;
                        Existing->left = left_child_temp;
                        Existing->right = Child_of_temp;
                        Child_of_temp->left = Existing;

                    }
                    //cout<<temp->key<<" "<<temp->child->key<<endl;
                    left_of_existing->right = right_of_existing;
                    right_of_existing->left = left_of_existing;
                    Arr[temp->degree] = NULL;   
                    temp->degree = temp->degree + 1;
                    
                    if(Arr[temp->degree]==NULL)
                        Arr[temp->degree] = temp;
                    else{
                        Starter = temp;
                        x++;
                    }
                }
            }
        }
        
        Node * temp = Starter;

        if(temp->key > minimum->key){
            minimum = temp;
        }

        while(temp->right != Starter && temp->right!=temp){            
            if(temp->key > minimum->key){
                minimum = temp;
            }
            temp = temp->right;
        }
        minimum = root_holder;
        //cout<<minimum->key<<" "<<minimum->value<<endl;

    }

    int size_of_mainroot(){
        int x = 1;
        Node * temp = minimum;
        while(temp->right != minimum){
            temp = temp->right;
            x++;
        }
        return x;
    }

};

class PriorityQueue{

    public:

    FibonacciHeap * make_heap(){
        
        FibonacciHeap * F = new FibonacciHeap();
        F->create_heap(); 
        return F;
    }

    bool is_empty(FibonacciHeap * FH){
        if(FH->minimum == NULL) return true;
        else return false;
    }

    void insert(FibonacciHeap * FH,int key,int value){
        FH->Insert(key,value);
    }
    void print(FibonacciHeap * FH){
        // cout<<FH->minimum->key;
        if(FH->minimum == NULL)
            return;
        else{
            FH->printTree(FH->minimum,1);
        }
    }
    
    int find_max(FibonacciHeap * FH){
        if(FH->minimum !=NULL )
            return FH->minimum->value;
        else return NULL;
    }

    FibonacciHeap * meld(FibonacciHeap *FH,FibonacciHeap * FH2){
        if(FH->minimum == NULL || FH2->minimum == NULL) return FH;
        
        FH = FH->welding(FH2);
        return FH;
    }

    void increase_key(FibonacciHeap *FH, int value,int key) {
        if (FH->Increase_Key(FH->minimum, value,key)) {
            //cout << "Value " << value << " found and increased it's key" << endl;
        } else {
            //cout << "Value " << value << " not found" << endl;
        }
    }

    void deletes(FibonacciHeap * FH,int value){
        if(FH->minimum == NULL) return ;
        FH->Increase_Key(FH->minimum,value,INT_MAX);
        FH->Delete_max();
    }

    void root_size(FibonacciHeap * FH){
        cout<<FH->size_of_mainroot()<<endl;
    }

    void test(){

        try{

            FibonacciHeap * FH = make_heap();
            FibonacciHeap * FH2 = make_heap();

            deletes(FH,10);
            insert(FH,10,20);
            insert(FH,20,2);
            insert(FH,30,6);
            insert(FH,40,1);
            insert(FH2,100,42);
            insert(FH2,200,5);
            insert(FH2,300,4);
            insert(FH2,400,0);
            meld(FH,FH2);
            increase_key(FH,0,1000);
            increase_key(FH,5,2000);
            increase_key(FH,6,4000);
            deletes(FH,4);
            print(FH);

            if(find_max(FH) != NULL) cout<<find_max(FH)<<endl;

            cout<<"passed"<<endl;

        }catch(const char* errorMessage){
            cout<<"not passed!"<<endl;
        }

    }

};


int main(){

    PriorityQueue myQueue;

    // FibonacciHeap * FH = myQueue.make_heap();
    // FibonacciHeap * FH2 = myQueue.make_heap();

    // myQueue.insert(FH,10,20);
    // myQueue.insert(FH,20,2);
    // myQueue.insert(FH,30,6);
    // myQueue.insert(FH,40,1);

    // myQueue.insert(FH2,100,42);
    // myQueue.insert(FH2,200,5);
    // myQueue.insert(FH2,300,4);
    // myQueue.insert(FH2,400,0);

    // myQueue.meld(FH,FH2);

    // myQueue.increase_key(FH,0,1000);
    // myQueue.increase_key(FH,5,2000);
    // myQueue.increase_key(FH,6,4000);

    // //myQueue.print(FH);
    // cout<<endl;
    // myQueue.deletes(FH,4);
    // myQueue.print(FH);
    
    myQueue.test();

    return 0;
}