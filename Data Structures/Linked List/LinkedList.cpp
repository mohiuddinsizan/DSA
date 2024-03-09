#include <iostream>
using namespace std;

class Node
{
public :
    int val;
    Node * next;

    Node()
    {
        val = 0;
        next = NULL;
    }

    Node(int val)
    {
        this->val=val;
        this->next=NULL;
    }
};

class List
{
    Node *cur;
    Node *head=NULL;
    int size = 0;
public:

    List()
    {
        cur = new Node;
        head = new Node;
        cur = head;
    }

    void takeinput(int t)
    {
        Node *newnode = new Node(t);
        Node *temp = head;

        if(head==NULL || size==0)
        {
            //cout<<"hello";
            head = newnode;
            size++;
            return;
            //return cur;
        }
        else
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            cur=temp->next;
            size++;
        }
        //return cur;
    }

    void display()
    {
        //cout<<"Current LIST : ";
        Node * temp=head;
        while(temp->next!=NULL)
        {
            if(temp==cur)
            {
                cout<<"|";
            }
            cout<<temp->val<<" ";

            temp=temp->next;
        }
        cout<<endl;
    }

    void Insert(int p)
    {
        if(head == nullptr)
        {
            //cout << "HEKK";
            Node * newnode = new Node(p);
            head = newnode;
            cur = head;
            size = 0;
            //cout << "DOME";
        }
        else if(cur==head)
        {
            Node * newnode = new Node(p);
            newnode->next=head;
            head=newnode;
            cur=head;
        }
        else
        {
            Node *temp = head;
            while(temp->next!= cur)
            {
                temp=temp->next;
            }
            Node * newnode = new Node(p);
            newnode->next = temp->next;
            temp->next=newnode;
            cur=newnode;
        }
    }

    int remove()
    {
        if(size == 1)
        {
            size = 0;
            head = nullptr;
            cur = head;
        }
        if(cur==head)
        {
            int ret=cur->val;
            //cout<<ret<<endl;
            cur=head->next;
            head=cur;

            return ret;
        }
        else
        {
            int ret=cur->val;
            Node * temp=head;
            while(temp->next!=cur)
            {
                temp=temp->next;
            }
            temp->next=cur->next;
            if(temp->next != NULL)
                cur=temp->next;
            else
            {
                Node * temp2=head;
                while(temp2->next->next!=NULL)
                {
                    temp2=temp2->next;
                }
                cur=temp2->next;
            }

            return ret;
        }
    }

    void moveToStart()
    {
        cur=head;
    }

    void moveToEnd()
    {
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
    }

    void prev()
    {
        if(cur==head)
        {
            return ;
        }
        else
        {
            Node * temp=head;
            while(temp->next!=cur)
            {
                temp=temp->next;
            }
            cur=temp;
        }
    }

    void next()
    {
        cur=cur->next;
    }

    int length()
    {
        int lng=0;
        Node * temp = head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
            lng++;
        }
        //cout<<lng<<endl;
        return lng;
    }

    int currPos()
    {
        Node * temp = head;
        int curpos=0;
        while(temp!=cur)
        {
            temp=temp->next;
            curpos++;
        }
        //cout<<curpos<<endl;
        return curpos;
    }

    void moveToPos(int p)
    {

        Node * temp = head;
        for(int i=0; i<p; i++)
        {
            temp=temp->next;
        }
        cur=temp;
    }

    int getValue()
    {
        //cout<<cur->val<<endl;
        return cur->val;
    }
};
