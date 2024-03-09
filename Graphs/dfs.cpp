#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> adjacent[N];
bool visited[N];

void dfs(int source){
    visited[source] = true;
    cout<<source<<" ";
    for(int x : adjacent[source]){
        if(!visited[x]){
            dfs(x);
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    for(int i = 0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }
    dfs(1);

    return 0;
}