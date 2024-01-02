#include <iostream>
//#include"Array.cpp"
#include"LinkedList.cpp"

using namespace std;
List arr;

void clea_r(List &arr)
{
    while(arr.length()!=0)
    {
        arr.remove();
    }
}
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
void searc_h(List &arr, int item)
{
    int pos2=arr.currPos();
    int flag=0;
    for(int i=0; i<arr.length(); i++)
    {
        arr.moveToPos(i);
        int l = arr.getValue();
        if(l==item)
        {
            cout<<i<<endl;
            flag=1;
        }
    }
    if(flag==0)
    {
        cout<<-1<<endl;
        return;
    }
    arr.moveToPos(pos2);
}

int main()
{
    List list;
    int k,x;
    cin>>k>>x;


    for(int i = 0; i < k; i++)
    {
        int tmp;
        cin >> tmp;
        append(list,tmp);
    }
    //list.prev();
    list.display();
    //cout<<list.length();

    while(true)
    {
        int q;
        cin>>q;

        int item;
        cin>>item;
        if(q==0)
        {
            clea_r(list);
        }
        if(q==1)
        {
            append(list,item);
            list.display();
        }
        if(q==2)
        {
            searc_h(list,item);
        }
        cout<<endl;
    }
    return 0;
}
