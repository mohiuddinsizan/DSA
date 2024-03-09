#include <iostream>
using namespace std;

template<typename T>
class List
{
    class Node
    {
    public :
        T val;
        Node * next;

        Node()
        {
            val = 0;
            next = NULL;
        }

        Node(T val)
        {
            this->val=val;
            this->next=NULL;
        }
    };

    Node *cur;
    Node *head=NULL;
    Node *tail=NULL;
    int size = 0;
public:

    List()
    {

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
        /*while(temp->next!=NULL)
        {
            if(temp==cur)
            {
                cout<<"|";
            }
            cout<<temp->val<<" ";

            temp=temp->next;
        }
        cout<<endl;
        */
        for(int i=0; i<size; i++)
        {
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void Insert(T p)
    {
        Node * newnode = new Node(p);
        if(head == nullptr)
        {
            head = newnode;
            tail = head;
            size ++;
            //cout << "DOME";
        }
        /*else if(cur==head)
        {
            newnode->next=head;
            head=newnode;
            cur=head;
        }*/
        else
        {
            tail->next = newnode;
            tail = tail->next;
            size++;
        }
    }

    int remove()
    {
        if(size==0)
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        cur = head;
        /*if(size == 1)
        {
            size = 0;
            head = nullptr;
            cur = head;
        }*/
        if(cur==head)
        {
            T ret=cur->val;
            //cout<<ret<<endl;
            cur=head->next;
            head=cur;
            size--;
            return ret;
        }
        /*
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
            size--;
            return ret;
        }
        */
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

    int lengt_h()
    {
        int lng=0;
        Node * temp = head;
        while(temp!=NULL)
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

    T getValue()
    {
        //cout<<cur->val<<endl;
        return head->val;
    }
    T getLastValue()
    {
        return tail->val;
    }
    void Clear()
    {
        size =0;
        head = NULL;
        tail = NULL;
        cur = NULL;
    }
};
