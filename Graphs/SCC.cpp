#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> adjacent[N];
vector<int> adjacent2[N];
bool visited[N];
bool visited2[N];
stack<int> dfs(stack<int> &s,int i){
    cout<<"hello"<<endl;
    visited[i] = true;
    for(int x : adjacent[i]){
        if(!visited[x]){
            dfs(s,x);
        }
    }
    s.push(i);
    return s;
}
void dfs2(int i){
    visited2[i] = true;
    cout<<i<<" ";
    for(int x : adjacent2[i]){
        if(!visited2[x]){
            dfs2(x);
        }
    }
}
int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int v,e;
    while(e--){
        int x,y;
        cin>>x>>y;
        adjacent[x].push_back(y);
    }
    //cout<<"hello"<<endl;
    stack<int> s;
    for(int i = 0;i<v;i++){
        if(!visited[i]){
            dfs(s,i);
        }
    }
    cout<<s.top()<<endl;
    for(int i = 0;i<v;i++){
        for(int x : adjacent[i]){
            adjacent2[x].push_back(i);
        }
    }
    while(!s.empty()){
        
        if(!visited2[s.top()]){
            dfs2(s.top());
            s.pop();
        }
        cout<<endl;
    }
    return 0;
}