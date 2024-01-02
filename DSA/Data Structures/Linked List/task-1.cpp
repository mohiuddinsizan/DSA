#include <iostream>
//#include "Array.cpp"
#include "LinkedList.cpp"
using namespace std ;


int main()
{

    int k;
    cin>>k;
    int x;
    cin>>x;

    /*List l(x);

    for(int i = 0; i < k; i++)
    {
        int tmp;
        cin >> tmp;
        l.Insert(tmp);
    }
    l.prev();
    l.display();*/



    List l;

    for(int i=0; i<k; i++)
    {
        int t;
        cin>>t;
        l.takeinput(t);
    }
    l.display();



    for(int t=0;; t++)
    {
        int q,p;
        cin >> q >> p;
        if(q==0)
            return 0;
        if(q == 1)
        {
            l.Insert(p);
            l.display();
            cout<<-1<<endl;
        }
        if(q == 2)
        {
            cout<<l.remove()<<endl;
            l.display();
        }
        if(q == 3)
        {
            l.moveToStart();
            l.display();
            cout<<-1<<endl;
        }
        if(q == 4)
        {
            l.moveToEnd();
            l.display();
            cout<<-1<<endl;
        }
        if(q == 5)
        {
            l.prev();
            l.display();
            cout<<-1<<endl;
        }
        if(q == 6)
        {
            l.next();
            l.display();
            cout<<-1<<endl;
        }
        if(q == 7)
        {
            l.display();
            cout << l.length() << endl;
        }
        if(q == 8)
        {
            l.display();
            cout << l.currPos() << endl;
        }
        if(q == 9)
        {
            l.moveToPos(p);
            l.display();
            cout<<-1<<endl;
        }
        if(q == 10)
        {
            l.display();
            cout << l.getValue() << endl;
        }

    }

    return 0;
}
