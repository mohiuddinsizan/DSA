#include<bits/stdc++.h>
using namespace std;
vector<int> adjacent[100000];
bool visited[100000];
int parent[100000];
bool cycle = false;
stack<int> toposort(int source,stack<int> &myStack,vector<int> cycleDetect){
    visited[source] = true;
    cycleDetect.push_back(source);
    for(int x : adjacent[source]){
        if(!visited[x]){
            parent[x] = source;
            toposort(x,myStack,cycleDetect);
        }
        else{
            for(int com : cycleDetect){
                if(com == x) cycle = true;
            }
        }

    }
    myStack.push(source);
    return myStack;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int v,e;
    cin>>v>>e;
    while(e--){
        int x,y;
        cin>>x>>y;
        adjacent[x].push_back(y);
    }
    parent[0] = -1;
    stack<int> myStack;
    vector<int> cycleDetect;
    for(int i = 0;i<v;i++){
        if(!visited[i]){
            toposort(i,myStack,cycleDetect);
        }
    }
    if(!cycle){
        while(!myStack.empty()){
            cout<<myStack.top()<<" ";
            myStack.pop();
        }
    }
    else cout<<"cycle detected !"<<endl;
    return 0;
}