#include<iostream>
//#include"LinkedList.cpp"
#include"Array.cpp"
using namespace std;
List garage[1000];

/*void append(List &arr, int item)
{
    int pos2 = arr.currPos();
    //cout<<pos2<<" "<<arr.length()<<endl;
    if(arr.length()!=0)
    {
        arr.moveToEnd();
        arr.next();
        arr.Insert(item);
        arr.moveToPos(pos2);
    }
    else
    {
        arr.moveToStart();
        arr.Insert(item);
        arr.moveToPos(pos2);
    }
}*/
void append(List &arr, int item)
{
    int pos2 = arr.currPos();
    //cout<<pos2<<" "<<arr.length()<<endl;

    if(arr.length()!=0)
    {
        //cout<<"hey"<<endl;
        arr.moveToEnd();
        //cout<<arr.currPos()<<" ";
        //arr.next();
        //cout<<arr.currPos()<<endl;
        arr.Insert(item);
        arr.moveToPos(pos2);
    }
    else
    {
        //cout<<arr.currPos()<<" ";
        arr.moveToStart();
        arr.Insert(item);
        arr.moveToPos(pos2);
        //cout<<"hello"<<endl;
    }

}
int y;
void printGarage()
{
    for(int i=0; i<y; i++)
    {
        garage[i].display();
    }
}

int main()
{
    int x,z;
    cin>>x;
    cin>>y;
    cin>>z;

    for (int i=0; i<y; i++)
    {
        int garagenumber;
        cin>>garagenumber;

        int tot;
        cin >> tot;
        for(int i = 0; i < tot; i++)
        {
            int car;
            cin >> car;
            append(garage[garagenumber-1],car);
        }
    }

    printGarage();

    while(true)
    {
        string s;
        cin >> s;
        if(s == "req")
        {
            for(int i = 0; i < y; i++)
            {
                if(garage[i].length() > 0)
                {
                    garage[i].remove();
                    break;
                }
            }
        }
        else if(s == "ret")
        {
            int car;
            cin >> car;

            for(int i = y-1; i >= 0; i--)
            {
                if(garage[i].length() < z)
                {
                    append(garage[i], car);
                    break;
                }
            }
        }
        else
        {
            break;
        }

        printGarage();
    }

    printGarage();

    return 0;
}
