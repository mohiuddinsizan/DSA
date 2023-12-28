#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> adjacent[N];
bool visited[N];
int level[N];
void bfs(int source){
    queue<int> search;
    search.push(source);
    visited[source] = true;
    level[source] = 0;
    while(!search.empty()){
        int parent = search.front();
        search.pop();
        for(int x : adjacent[parent]){
            if(!visited[x]){
                visited[x] = true;
                search.push(x);
                level[x] = level[parent] + 1;
            }   
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
    bfs(10);
    for(int i = 0;i<N;i++){
        if(visited[i] == true){
            cout<<"node : "<<i<<" level : "<<level[i]<<endl;
        }
    }
    return 0;
}