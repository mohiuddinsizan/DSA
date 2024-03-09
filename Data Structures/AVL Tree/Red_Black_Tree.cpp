// Not Fully Functional !!! 
#include<bits/stdc++.h>
using namespace std;

class Map{

	int size = 0;

public:

    class Node{
        public:
        int key;
        string value;
        Node * left;
        Node * right;
        Node * parent;
        bool black;

        Node(int key,string value){
            this->key = key;
            this->value = value;
            left = NULL;
            right = NULL;
            parent = NULL;
            black = false;
        }

    };

    Node * new_root;

    Node *uncle(Node * root)
	{
		if (root->parent == NULL or root->parent->parent == NULL)
			return NULL;

		if (isOnLeft(root))
			return root->parent->parent->right;
		else
			return root->parent->parent->left;
	}

    bool isOnLeft(Node * root) { return root == root->parent->left; }

    Node *sibling(Node * root)
	{
		if (root->parent == NULL)
			return NULL;

		if (isOnLeft(root))
			return root->parent->right;

		return root->parent->left;
	}

    void moveDown(Node *nParent,Node * root)
	{
		if (root->parent != NULL)
		{
			if (isOnLeft(root))
			{
				root->parent->left = nParent;
			}
			else
			{
				root->parent->right = nParent;
			}
		}
		nParent->parent = root->parent;
		root->parent = nParent;
	}

    bool hasRedChild(Node * root)
	{
		return (root->left != NULL and root->left->black == false) or
			   (root->right != NULL and root->right->black == false);
	}

    Node * leftRotate(Node * rotator){
        Node * right = rotator->right;
        Node * left = right->left;
        right->left = rotator;
        rotator->right = left;
        rotator->parent = right;
        if(left!=NULL){
            left->parent = rotator;
        }
        return right;
    }

    Node * rightRotate(Node * rotator){
        Node * left = rotator->left;
        Node * right = left->right;
        left->right = rotator;
        rotator->left = right;
        rotator->parent = left;
        if(right!=NULL){
            right->parent = rotator;
        }
        return left;
    }

    void swapColors(Node *x1, Node *x2)
	{
        if(x1->black == false && x2->black == true){
            x1->black == true;
            x2->black == false;
        }
        else if(x1->black == true && x2->black == false){
            x1->black == false;
            x2->black == true;
        }
	}

	void swapValues(Node *u, Node *v)
	{
		int temp;
		temp = u->key;
		u->key = v->key;
		v->key = temp;
	}

    void fixRedRed(Node *x,Node * root)
	{
		if (x == root)
		{
			x->black = true;
			return;
		}

		Node *Parent = x->parent, *grandparent = Parent->parent,
			 *Uncle = uncle(x);

		if (Parent->black != true)
		{
			if (Uncle != NULL && Uncle->black == false)
			{
				Parent->black = true;
				Uncle->black = true;
				grandparent->black = false;
				fixRedRed(grandparent,root);
			}
			else
			{
				if ( isOnLeft(Parent))
				{
					if (isOnLeft(x))
					{
						swapColors(Parent, grandparent);
					}
					else
					{
						leftRotate(Parent);
						swapColors(x, grandparent);
					}
					rightRotate(grandparent);
				}
				else
				{
					if (isOnLeft(x))
					{
						rightRotate(Parent);
						swapColors(x, grandparent);
					}
					else
					{
						swapColors(Parent, grandparent);
					}
					leftRotate(grandparent);
				}
			}
		}
	}

    Node *successor(Node *x)
	{
		Node *temp = x;

		while (temp->left != NULL)
			temp = temp->left;

		return temp;
	}

    Node *BSTreplace(Node *x)
	{
		if (x->left != NULL and x->right != NULL)
			return successor(x->right);
		if (x->left == NULL and x->right == NULL)
			return NULL;

		if (x->left != NULL)
			return x->left;
		else
			return x->right;
	}

	void deleteNode(Node *v,Node * root)
	{
		Node *u = BSTreplace(v);
		bool uvBlack = ((u == NULL or u->black == true) and (v->black == true));
		Node *Parent = v->parent;

		if (u == NULL)
		{
			if (v == root)
			{
				root = NULL;
			}
			else
			{
				if (uvBlack)
				{
					fixDoubleBlack(v,root);
				}
				else
				{
					if (sibling(v) != NULL)
						sibling(v)->black = false;
				}
				if (isOnLeft(v))
				{
					Parent->left = NULL;
				}
				else
				{
					Parent->right = NULL;
				}
			}
			delete v;
			return;
		}

		if (v->left == NULL or v->right == NULL)
		{
			if (v == root)
			{
				v->key = u->key;
				v->left = v->right = NULL;
				delete u;
			}
			else
			{
				if (isOnLeft(v))
				{
					Parent->left = u;
				}
				else
				{
					Parent->right = u;
				}
				delete v;
				u->parent = Parent;
				if (uvBlack)
				{
					fixDoubleBlack(u,root);
				}
				else
				{
					u->black = true;
				}
			}
			return;
		}
		swapValues(u, v);
		deleteNode(u,root);
	}

    void fixDoubleBlack(Node *x,Node * root)
	{
		if (x == root)
			return;

		Node *Sibling = sibling(x), *Parent = x->parent;
		if (Sibling == NULL)
		{
			fixDoubleBlack(Parent,root);
		}
		else
		{
			if (Sibling->black == false)
			{
				Parent->black = false;
				Sibling->black = true;
				if (isOnLeft(Sibling))
				{
					rightRotate(Parent);
				}
				else
				{
					leftRotate(Parent);
				}
				fixDoubleBlack(x,root);
			}
			else
			{
				if (hasRedChild(Sibling))
				{
					if (Sibling->left != NULL and Sibling->left->black == false)
					{
						if (isOnLeft(Sibling))
						{
							Sibling->left->black = Sibling->black;
							Sibling->black = Parent->black;
							rightRotate(Parent);
						}
						else
						{
							Sibling->left->black = Parent->black;
							rightRotate(Sibling);
							leftRotate(Parent);
						}
					}
					else
					{
						if (isOnLeft(Sibling))
						{
							Sibling->right->black = Parent->black;
							leftRotate(Sibling);
							rightRotate(Parent);
						}
						else
						{
							Sibling->right->black = Sibling->black;
							Sibling->black = Parent->black;
							leftRotate(Parent);
						}
					}
					Parent->black = true;
				}
				else
				{
					Sibling->black = false;
					if (Parent->black == true)
						fixDoubleBlack(Parent,root);
					else
						Parent->black = true;
				}
			}
		}
	}

    bool left_right_rotate = false;
    bool rigth_left_rotate = false;
    bool left_left_rotate = false;
    bool right_right_rotate = false;

    Node *  insert(Node * root,int key,string value){

        bool red_black_conflict = false;

        if (root == NULL) {
            root =  new Node(key, value);
			size++;
            return root;
        }

        else if (key > root->key) {
            root->right = insert(root->right, key, value);
            root->right->parent = root;
            if(root != new_root){
                if (!root->black && !root->right->black) {
                    red_black_conflict = true;
                }
            }
            
        } 
        else if (key < root->key) {
            root->left = insert(root->left, key, value);
            root->left->parent = root;
            if(root!=new_root){
                if (!root->black && !root->left->black) {
                    red_black_conflict = true;
                }
            }
        }

        if (left_left_rotate) {
            root = leftRotate(root);
            left_left_rotate = false;
            root->black = true;
            root->left->black = false;
        } else if (left_right_rotate) {
            root->left = leftRotate(root->left);
            root->left->parent = root;
            root = rightRotate(root);
            left_right_rotate = false;
            root->right->black = false;
            root->black = true;
        } else if (right_right_rotate) {
            root = rightRotate(root);
            right_right_rotate = false;
            root->black = true;
            root->right->black = true;
        } else if (rigth_left_rotate) {
            root->right = rightRotate(root->right);
            root->right->parent = root;
            root = leftRotate(root);
            rigth_left_rotate = false;
            root->black = true;
            root->left->black = false;
        }
        
        if(red_black_conflict){
            
            if(root->parent->right == root){
                if(root->parent->left == NULL || root->parent->left->black){
                    if(root->left != NULL && !root->left->black){
                        rigth_left_rotate = true;
                    }
                    else if(root->right != NULL && !root->right->black){
                        left_left_rotate = true;
                    }
                }
                else if(!root->parent->left->black){
                    root->parent->left->black = true;
                    root->black = true;
                    if(root->parent != new_root){
                        root->parent->black = true;
                    }
                }
            }
            else{
                if( root->parent->right == NULL || root->parent->right->black){
                    if(root->left != NULL && !root->left->black){
                        right_right_rotate = true;
                    }
                    else if(root->right != NULL && !root->right->black){
                        left_right_rotate = true;
                    }
                }
                else if(!root->parent->right->black  ){
                    root->parent->right->black = true;
                    root->black = true;
                    if(root->parent!=new_root){
                        root->parent->black = false;
                    }
                }
            }
            red_black_conflict = false;
        }
        
        return root;

    }

    Node *search(int n,Node * root)
	{
		Node *temp = root;
		while (temp != NULL)
		{
            cout<<"hello"<<endl;
			if (n < temp->key)
			{
				if (temp->left == NULL)
					break;
				else
					temp = temp->left;
			}
			else if (n == temp->key)
			{
				break;
			}
			else
			{
				if (temp->right == NULL)
					break;
				else
					temp = temp->right;
			}
		}

		return temp;
	}
    
    void print_map(Node * root){
        if(root == NULL)  return;
        
        cout<<root->key<<"_"<<root->value;
        if(root->left == NULL && root->right == NULL) return ;
        cout<<"(";
        print_map(root->left);
        cout<<",";
        print_map(root->right);
        cout<<")";
    }

    void deleteByVal(int n,Node * root)
	{
		if (root == NULL)
			// Tree is empty
			return;

		Node *v = search(n,root);

		if (v->key != n)
		{
			cout << n<<" no found" << endl;
			return;
		}
		cout << n <<" found" << endl;
		size--;
		deleteNode(v,root);
	}

	int Size(){
		return size;
	}

	void inorder(Node * root){
		if(root == NULL) return;

		inorder(root->left);

		cout<<root->key<<" ==> "<<root->value<<endl;

		inorder(root->right);

	}

};

int main(){

    Map  map;
    map.new_root = NULL;
    int i = 0;
    while(true){
        // int operation;cin>>operation;
        // if(operation == 1 ){
        //     int key;
        //     string value;
        //     cin>>key>>value;
        //     map.new_root = map.insert(map.new_root,key,value);
        //     if(i == 0){
        //         map.new_root->black = true;
        //         i++;
        //     }
        //     map.print_map(map.new_root);
        //     cout<<endl;
        // }
        // if(operation == 2){
        //     int value;cin>>value;
        //     map.deleteByVal(value,map.new_root);
        //     map.print_map(map.new_root);
        // }

		string operation;cin>>operation;

		if(operation == "Clr"){
			if(map.new_root == NULL){
				cout<<"unsuccessfull"<<endl;
			}
			else{
				map.new_root = NULL;
			}
		}

		if(operation == "Em"){
			if(map.new_root == NULL){
				cout<<"yes"<<endl;
			}
			else{
				cout<<"no"<<endl;
			}
		}

		if(operation == "I"){
			int key;
            string value;
            cin>>key>>value;
            map.new_root = map.insert(map.new_root,key,value);
            if(i == 0){
                map.new_root->black = true;
                i++;
            }
            map.print_map(map.new_root);
            cout<<endl;
		}

		if(operation == "F"){
			int input;cin>>input;
			if(map.search(input,map.new_root) != NULL){
				cout<<input<<" found"<<endl;
			}
			else{
				cout<<input<<" not found"<<endl;
			}
		}

		if(operation == "S"){
			cout<<map.Size()<<endl;
		}

		if(operation == "Itr"){
			map.inorder(map.new_root);
		}

		if(operation == "E"){
			int value;cin>>value;
            map.deleteByVal(value,map.new_root);
            map.print_map(map.new_root);
			cout<<endl;
		}

    }

    return 0;
}

// 10 18 5 4 15 17 25 60 1 90