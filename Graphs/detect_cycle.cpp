// UNDIRECTED GRAPH !
#include<bits/stdc++.h>
using namespace std;
vector<int> adjacent[100000];
bool visited[100000];
int parent[100000];
bool cycle = false;
void dfs(int i){
    visited[i] = true;
    for(int x : adjacent[i]){
        if(!visited[x]) {
            parent[x] = i;
            dfs(x);
        }
        else{
            if(parent[x]!=i) cycle = true;
        }
    }
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int v,e;
    cin>>v>>e;
    while(e--){
        int u,v;
        cin>>u>>v;
        adjacent[u].push_back(v);
        //adjacent[v].push_back(u);
    }
    for(int i  = 1;i<=v;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    if(cycle) cout<<"cycle detected !"<<endl;
    else cout<<"NO cycle !"<<endl;
    return 0;
}