#include<iostream>
using namespace std;

template<typename T>

class Node{
public:
    T data;
    Node * left;
    Node * right;

    Node(T data){
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};
template<typename T>
void inorder(Node <T> * root){
    if(root == nullptr) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
template<typename T>
void preorder(Node <T> * root){
    if(root == nullptr) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
template<typename T>
void postorder(Node <T> * root){
    if(root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}
template<typename T>
int totalNode(Node<T> * root){
    if(root == NULL) return 0;
    return 1+totalNode(root->left)+totalNode(root->right);
}
template<typename T>
Node<T>* insert(T data,Node<T>*root){
    if(root == nullptr){
        root = new Node<T>(data);
        return root;
    }
    else if(data<root->data){
        root->left = insert(data,root->left);
    }
    else{
        root->right = insert(data,root->right);
    }
    return root;
}
template<typename T>
Node<T> * find(T data,Node<T>*root){
    if(root == nullptr){
        cout<<"Doesn't Contain the value !"<<endl;
        return nullptr;
    }
    else if(root->data == data) return root;
    else if(data<root->data) return find(data,root->left);
    else if(data>root->data) return find(data,root->right);
}
template<typename T>
Node<T>* findMin(Node<T>* root){
    if(root == nullptr) return root;
    if(root->left == nullptr) return root;
    return findMin(root->left);
}
template<typename T>
Node<T>* Delete(T data,Node<T>*root){
    if(root == nullptr){
        cout<<"Empty Tree !"<<endl;
        return root;
    }
    Node<T>* deleteNode = find(data,root);
    if(deleteNode!=nullptr){
        if(deleteNode->left == nullptr && deleteNode->right == nullptr){
            delete deleteNode;
            return nullptr;
        }
        else if(deleteNode->left == nullptr){
            Node<T> * temp = deleteNode;
            deleteNode = deleteNode->right;
            delete temp;
            return deleteNode;
        }
        else if(deleteNode->right == nullptr){
            Node<T> * temp = deleteNode;
            deleteNode = deleteNode->left;
            delete temp;
            return deleteNode;
        }
        else{
            Node<T> * temp = findMin(deleteNode->right);
            deleteNode->data = temp->data;
            //delete temp;
            deleteNode->right = Delete(deleteNode->data,deleteNode->right);
            return deleteNode;
        }
    }
    return root;
}
int main(){
    Node<int>* root = nullptr;
    while(true){
        int op;cin>>op;
        if(op == 1){
            int x;cin>>x;
            root = insert(x,root);
        }
        else if(op == 2){
            int x;cin>>x;
            // if(find(x,root) != nullptr) cout<<"Found"<<endl;
            // else cout<<"Not Found !"<<endl;
            Delete(x,root);
        }
        else if(op == 3){
            inorder(root);
            cout<<endl;
            preorder(root);
            cout<<endl;
            postorder(root);
            cout<<endl;
        }
        else break;
    }

    // cout<<totalNode(root)<<endl;

    return 0;
}