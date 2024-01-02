#include<iostream>
#include<fstream>
using namespace std;

class Node
{
public:

    int val;
    Node * left;
    Node * right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void insert(Node * &root,int val)
{
    Node * newnode = new Node(val);

    if(root == NULL)
        root = newnode;
    else if(val>root->val)
        insert(root->right,val);
    else if(val<root->val)
        insert(root->left,val);
}
/*
void inorder(Node * &root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
*/
string inorder(Node*& root)
{
    if (root == NULL)
        return "";

    string result = "";
    result += inorder(root->left);
    result += to_string(root->val) + " ";
    result += inorder(root->right);

    return result;
}
/*
void preorder(Node * &root)
{
    if(root==NULL)
        return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node * &root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}
*/
string preorder(Node * &root)
{
    if (root == NULL)
        return "";

    string result = "";
    result += to_string(root->val) + " ";
    result += preorder(root->left);
    result += preorder(root->right);

    return result;
}
string postorder(Node * &root)
{
    if (root == NULL)
        return "";

    string result = "";
    result += postorder(root->left);
    result += postorder(root->right);
    result += to_string(root->val) + " ";

    return result;
}
bool Find(Node * &root,int val)
{
    if(root == NULL)
    {
        return false;
    }
    else if(root->val == val)
    {
        return true;
    }
    else if(val>root->val)
        Find(root->right,val);
    else if(val<root->val)
        Find(root->left,val);
}
string generateTreeString(Node * &root)
{
    if (root == nullptr) return "";
    string str = to_string(root->val);
    if (root->left == nullptr && root->right == nullptr) return str;
    str +="("+ generateTreeString(root->left)+",";
    str += generateTreeString(root->right)+")";
    return str;
}
Node *  min(Node * & root)
{
    if(root == NULL ) return root;
    if(root->left ==NULL)
    {
        return root;
    }
    min(root->left);
}
Node * deleteNode(Node * root, int value)
{
    if(root == NULL )
        return root;
    else if(value < root->val) root->left = deleteNode(root->left,value);
    else if(value > root->val) root->right = deleteNode(root->right,value);
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if(root->right == NULL)
        {
            Node * temp = root;
            root = root->left;
            delete temp;

        }
        else if(root->left == NULL)
        {
            Node * temp = root;
            root = root->right;
            delete temp;
        }
        else
        {
            Node * temp = min(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right,temp->val);
        }
    }
    return root;
}

int main()
{
    ifstream infile("in.txt");
    ofstream outfile("out.txt");
    Node * root = NULL;
    string operation;
    int value;

    while (infile >> operation)
    {
        if (operation == "I")
        {
            infile >> value;
            insert(root,value);
            outfile <<"("<< generateTreeString(root) <<")"<< endl;
        }
        else if (operation == "D")
        {
            infile >> value;
            deleteNode(root,value);
            outfile <<"("<< generateTreeString(root) <<")"<< endl;
        }
        else if (operation == "F")
        {
            infile >> value;
            bool found = Find(root,value);
            if (found)
                outfile << "found" << endl;
            else
                outfile << "not found" << endl;
        }
        else if (operation == "T")
        {
            string traversalType;
            infile >> traversalType;
            if (traversalType == "In")
            {
                outfile<<inorder(root)<<endl;
            }
            if (traversalType == "Pre")
            {
                outfile<<preorder(root)<<endl;
            }
            if (traversalType == "Post")
            {
                outfile<<postorder(root)<<endl;
            }
        }
    }
    return 0;
}

// 8 10 3 1 14 6 4 13 7 -1
// 5 3 9 0 4 7 10 -1
