#include <bits/stdc++.h> 
using namespace std; 

vector<string> keyHolder;

int deleteNumber = 0;
int insertionNumber = 0;

class HashTable{

    public:

    int maxSize;
    int NodeCounter = 0;
    bool linkedList ;
    bool doubleHasing ;
    bool customProbing ;
    bool Hash_one_1 ;
    bool Hash_two_2 ;

    class Node{
        public:

        string key;
        int value;
        Node * next;
        int prob;
        int collision;

        Node(string key,int value){
            this->key = key;
            this->value = value;
            next = NULL;
            prob = 0;
            collision = 0;
        }
    };

    Node **table;

    HashTable(int size){
        maxSize = size;
        table = new Node*[maxSize];
        for (int i = 0; i < maxSize; ++i) {
            table[i] = NULL;
        }
        linkedList = false;
        doubleHasing = false;
        customProbing = false;
        Hash_one_1 = false;
        Hash_two_2 = false;
    }

    void insert(string key,int value){

        Node * newNode = new Node(key,value);

        if(linkedList) insertUsingLinkedList(newNode);

        else if(doubleHasing)insertUsingDoubleHashing(newNode);

        else if(customProbing)insertUsingCustomProbe(newNode);

    }

    void insertUsingLinkedList(Node * newNode){

        int index = countWeight(newNode->key) % maxSize;
        newNode->prob++;
        
        if(table[index] == NULL){
            table[index] = newNode;
        }

        else{
            Node * temp = table[index];
            newNode->next = temp;
            table[index] = newNode;
            newNode->collision++;
            newNode->prob++;
        }
        NodeCounter++;
    }

    void insertUsingDoubleHashing(Node * newNode){
        if(NodeCounter == maxSize){
            cout<<"Maximum amount reached !!"<<endl;
            return;
        }

        int index = doubleHash(newNode->key,newNode->prob);
        int i = 0;

        if(table[index] == NULL){
            table[index] = newNode;
            newNode->prob++;
        }
        else{
            while(i<maxSize){
                newNode->prob++;
                index = doubleHash(newNode->key,newNode->prob);
                if(table[index] == NULL){
                    table[index] = newNode;
                    newNode->prob++;
                    newNode->collision++;
                    break;
                }
            }
        }
        NodeCounter++;
    }

    void insertUsingCustomProbe(Node * newNode){
        if(NodeCounter == maxSize){
            cout<<"Maximum amount reached !!"<<endl;
            return;
        }

        int index = customProbe(newNode->key,newNode->prob);
        int i = 0;

        if(table[index] == NULL){
            table[index] = newNode;
            newNode->prob++;
        }

        else{
            while(i<maxSize){
                newNode->prob++;
                index = customProbe(newNode->key,newNode->prob);
                if(table[index] == NULL){
                    table[index] = newNode;
                    newNode->prob++;
                    newNode->collision++;
                
                    break;
                }
            }
        }
        NodeCounter++;
    }

    int countWeight(string s){
        int wordLength = s.length();
        int weight = 0;

        for(int i = 0;i<wordLength;i++){
            weight += s[i];
        }
        return weight;
    }
    
    void printTable(){
        for(int i = 0;i<maxSize;i++){
            if(table[i]!=NULL){
                Node * temp = table[i];
                while(temp!=NULL){
                    cout<<temp->key<<" "<<temp->value<<" "<<temp->prob<<endl;;
                    temp = temp->next;
                }
            }
            cout<<endl;
            cout<<endl;
        }
    }

    int Hash_one(string key){
        return countWeight(key) % maxSize;
    }
    
    int Hash_two(string key){
        return maxSize - (countWeight(key) % maxSize);
    }

    int auxilaryHash(string key){
        int n = maxSize / 3;
        return (n) - (countWeight(key)%n);
    }

    int doubleHash(string key,int prob){
        if(Hash_one_1)
            return (Hash_one(key) + (auxilaryHash(key) * prob))%maxSize;
        else return (Hash_two(key) + (auxilaryHash(key) * prob))%maxSize;
    }

    int customProbe(string key,int prob){
        if(Hash_one_1)
            return (Hash_one(key) + (2 * prob * auxilaryHash(key)) + (3*prob*prob))%maxSize;
        else return (Hash_two(key) + (2 * prob * auxilaryHash(key)) + (3*prob*prob))%maxSize;
    }

    bool find(string key){

        //for linked list

        if(linkedList){
            int index = countWeight(key) % maxSize;
            Node * temp = table[index];

            if(temp == NULL ) return false;
            else{
                while(temp != NULL){
                    if(temp->key == key) return true;
                    temp = temp->next;
                }
                return false;
            }
        }

        // for doubleHashing 

        else if(doubleHasing){
            int index = doubleHash(key,0);
            int i = 0;
            while(i < maxSize){
                if(table[index] == NULL){
                    i++;
                    index = doubleHash(key,i);
                    continue;
                }
                else if(table[index]->key == key){
                    return true;
                }
                i++;
                index = doubleHash(key,i);
            }
            return false;
        }

        //for custom Prob

        if(customProbing){
            int index = customProbe(key,0);
            int i = 0;
            while(i < maxSize){
                if(table[index] == NULL){
                    i++;
                    index = customProbe(key,i);
                    continue;
                }
                else if(table[index]->key == key){
                    return true;
                }
                i++;
                index = customProbe(key,i);
            }
            return false;
        }

    }

    void deleteNode(string key){

        NodeCounter--;

        // for linked list

        if(linkedList){
            int index = countWeight(key) % maxSize;
            int headConfirm = 0;
            Node * temp = table[index];

            if(temp == NULL ) return;
            else{
                while(temp != NULL){
                    if(temp->key == key) {
                        if(headConfirm == 0){
                            table[index] = table[index]->next;
                        }
                        else{
                            Node * temp2 = table[index];

                            while(temp2->next != temp){
                                temp2 = temp2->next;
                            }

                            temp2->next = temp->next;
                        }
                        return;
                    }
                    temp = temp->next;
                    headConfirm++;
                }
                return ;
            }
        }

        // for doubleHashing 

        else if(doubleHasing){
            int index = doubleHash(key,0);
            int i = 0;
            while(i < maxSize){
                if(table[index] == NULL){
                    i++;
                    index = doubleHash(key,i);
                    continue;
                }
                else if(table[index]->key == key){
                    table[index] = NULL;
                    return;
                }
                i++;
                index = doubleHash(key,i);
            }
        }

        //for custom Prob

        else if(customProbing){
            int index = customProbe(key,0);
            int i = 0;
            while(i < maxSize){
                if(table[index] == NULL){
                    i++;
                    index = customProbe(key,i);
                    continue;
                }
                else if(table[index]->key == key){
                    table[index] = NULL;
                    return;
                }
                i++;
                index = customProbe(key,i);
            }
        }

    }

    int numberOfCollision(){
        int collisionNumber = 0;
        for(int i = 0;i<maxSize;i++){
            if(table[i]!=NULL){
                Node * temp = table[i];
                while(temp!=NULL){
                    collisionNumber+=temp->collision;
                    temp = temp->next;
                }
            }
        }
        return collisionNumber;
    }

    double averageProbes(){
        double averageProbesNumber = 0;
        for(int i = 0;i<maxSize;i++){
            if(table[i]!=NULL){
                Node * temp = table[i];
                while(temp!=NULL){
                    averageProbesNumber+=temp->prob;
                    temp = temp->next;
                }
            }
        }
        return averageProbesNumber/double(NodeCounter);
    }

    void rehash(int c){
        if(c < MaximumChainLenght()){
            int lastIndex = maxSize;
            maxSize *= 2;
            HashTable * temp = new HashTable(maxSize);
            temp->linkedList = true;
            temp->Hash_one_1 = this->Hash_one_1;
            temp->Hash_two_2 = this->Hash_two_2;
            for(int i = 0;i<lastIndex;i++){
                if(table[i] != NULL){
                    Node * temp2 = table[i];
                    while(temp2!= NULL){
                        temp->insert(temp2->key,temp2->value);
                        temp2 = temp2->next;
                    }
                }

            }
            table = temp->table;
        }
        if(c > MaximumChainLenght()){
            int lastIndex = maxSize;
            maxSize /= 2;
            HashTable * temp = new HashTable(maxSize);
            temp->linkedList = true;
            temp->Hash_one_1 = this->Hash_one_1;
            temp->Hash_two_2 = this->Hash_two_2;
            for(int i = 0;i<lastIndex;i++){
                if(table[i] != NULL){
                    Node * temp2 = table[i];
                    while(temp2!= NULL){
                        temp->insert(temp2->key,temp2->value);
                        temp2 = temp2->next;
                    }
                }

            }
            table = temp->table;
        }
    }

    int MaximumChainLenght(){
        int checker = INT_MIN;
        int checker2 = 0;

        for(int i = 0;i<maxSize;i++){
            if(table[i]!=NULL){
                Node * temp = table[i];
                while(temp!=NULL){
                    checker2 += 1;
                    temp = temp->next;
                }
            }
            if(checker2 > checker){
                checker = checker2;
            }
            checker2 = 0;
        }
        return checker;
    }

    double loadFactor(){
        return double(NodeCounter)/double(maxSize);
    }
};

string wordGenerator(int length){
    string s = "";
    while(length--){
        s += ('a'+rand()%26);
    }
    return s;
}

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int originalSizeOfHashTable(int n){
    if(isPrime(n)) return n;
    n = originalSizeOfHashTable(n+1);
}

int main() 
{
    srand(time(0));
    int n;cin>>n;
    int c;cin>>c;
    n = originalSizeOfHashTable(n);
    int value = 0;

    HashTable myHash_ll_1(n);
    HashTable myHash_dh_1(n);
    HashTable myHash_cp_1(n);

    myHash_ll_1.Hash_one_1 = true;
    myHash_dh_1.Hash_one_1 = true;
    myHash_cp_1.Hash_one_1 = true;

    myHash_ll_1.linkedList = true;
    myHash_dh_1.doubleHasing = true;
    myHash_cp_1.customProbing = true;


    HashTable myHash_ll_2(n);
    HashTable myHash_dh_2(n);
    HashTable myHash_cp_2(n);

    myHash_ll_2.Hash_two_2 = true;
    myHash_dh_2.Hash_two_2 = true;
    myHash_cp_2.Hash_two_2 = true;

    myHash_ll_2.linkedList = true;
    myHash_dh_2.doubleHasing = true;
    myHash_cp_2.customProbing = true;



    while(true){

        int operation;cin>>operation;

        if(operation == 0) break;

        if(operation == 1) {

            for(int i = 0;i<1000;i++){
                
                int length = (rand()%6)+5;
                string key = wordGenerator(length);
                cout<<length<<" "<<key<<endl;

                auto it = find(keyHolder.begin(),keyHolder.end(),key);

                if(it == keyHolder.end()){
                    value++;
                    keyHolder.push_back(key);
                    myHash_ll_1.insert(key,value);
                    myHash_dh_1.insert(key,value);
                    myHash_cp_1.insert(key,value);

                    myHash_ll_2.insert(key,value);
                    myHash_dh_2.insert(key,value);
                    myHash_cp_2.insert(key,value);
                    insertionNumber++;

                }

                if(insertionNumber % 100 == 0 && myHash_ll_1.MaximumChainLenght()>c){
                    myHash_ll_1.rehash(c);
                    cout<<"New Maximum Chainlength : "<<myHash_ll_1.MaximumChainLenght()<<" average probes : "<<myHash_ll_1.averageProbes()<<" load factor : "<<myHash_ll_1.loadFactor()<<endl;

                }

                if(insertionNumber % 100 == 0 && myHash_ll_2.MaximumChainLenght()>c){
                    myHash_ll_2.rehash(c);
                    cout<<"New Maximum Chainlength : "<<myHash_ll_2.MaximumChainLenght()<<" average probes : "<<myHash_ll_2.averageProbes()<<" load factor : "<<myHash_ll_2.loadFactor()<<endl;

                }

            }

        }

        if(operation == 2){

            myHash_ll_1.printTable();
            myHash_dh_1.printTable();
            myHash_cp_1.printTable();

            myHash_ll_2.printTable();
            myHash_dh_2.printTable();
            myHash_cp_2.printTable();

        }

        if(operation == 3){

            string key;cin>>key;

            if(myHash_ll_1.find(key) || myHash_dh_1.find(key) || myHash_cp_1.find(key)){
                cout<<"found that !"<<endl;
            }
            else{
                cout<<"didn't find !"<<endl;
            }

        }

        if(operation == 4){

            string key;cin>>key;

            if(myHash_ll_1.find(key) || myHash_dh_1.find(key) || myHash_cp_1.find(key)){
                myHash_ll_1.deleteNode(key);
                myHash_dh_1.deleteNode(key);
                myHash_cp_1.deleteNode(key);
                myHash_ll_2.deleteNode(key);
                myHash_dh_2.deleteNode(key);
                myHash_cp_2.deleteNode(key);
                deleteNumber++;
            }
            else{
                cout<<"Value not found !!"<<endl;
            }

            if(deleteNumber % 100 == 0 && (double(myHash_ll_1.MaximumChainLenght())*.8)>double(c) && double(myHash_ll_1.maxSize/2) >= n){
                myHash_ll_1.rehash(c);
            }

            if(deleteNumber % 100 == 0 && (double(myHash_ll_2.MaximumChainLenght())*.8)>double(c) && double(myHash_ll_2.maxSize/2) >= n){
                myHash_ll_2.rehash(c);
            }
        }

        if(operation == 5){
            cout<<"LinkedList : "<<myHash_ll_1.numberOfCollision()<<" "<<myHash_ll_1.averageProbes()<<endl;
            cout<<"Double Hashing : "<<myHash_dh_1.numberOfCollision()<<" "<<myHash_dh_1.averageProbes()<<endl;
            cout<<"Custom Probing : "<<myHash_cp_1.numberOfCollision()<<" "<<myHash_cp_1.averageProbes()<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"LinkedList : "<<myHash_ll_2.numberOfCollision()<<" "<<myHash_ll_2.averageProbes()<<endl;
            cout<<"Double Hashing : "<<myHash_dh_2.numberOfCollision()<<" "<<myHash_dh_2.averageProbes()<<endl;
            cout<<"Custom Probing : "<<myHash_cp_2.numberOfCollision()<<" "<<myHash_cp_2.averageProbes()<<endl;
        }

        if(operation == 6){
            cout<<myHash_ll_1.MaximumChainLenght()<<endl;
            cout<<myHash_ll_2.MaximumChainLenght()<<endl;
        }

    }
    
    return 0; 
}