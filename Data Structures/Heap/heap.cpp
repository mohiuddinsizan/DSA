#include<iostream>
#include"functionforpq.cpp"
#include<fstream>
using namespace std;
int main()
{
    maxPriorityQueue <int> mp;
    ifstream infile("in1.txt");
    ofstream outfile("out.txt");
    int OP;
    int x;
    int i;
    while(infile >> OP)
    {
        cout<<"Select operation : ";
        if(OP==1)
        {
            cout<<"Enter key value : ";
            infile>>x;
            mp.insert(x);
        }
        if(OP==2)
        {
            mp.findMax(outfile);
        }
        if(OP==3)
        {
            int val = mp.extractMax();
            if(val != -1)
            outfile<<"Max: "+to_string(val)+" has been extracted."<<endl;
        }
        if(OP==4)
        {
            cout<<"Enter index : ";
            infile>>i;
            cout<<"Enter key value : ";
            infile>>x;
            mp.increaseKey(i-1,x,outfile);
        }
        if(OP==5)
        {
            cout<<"Enter index : ";
            infile>>i;
            cout<<"Enter key value : ";
            infile>>x;
            mp.decreaseKey(i-1,x,outfile);
        }
        if(OP==6)
        {
            mp.print(outfile);
        }
        if(OP==7)
        {
            mp.sort(outfile);
        }
        if(OP==8) break;
    }

    return 0;
}
