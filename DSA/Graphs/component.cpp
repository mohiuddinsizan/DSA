#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> adjacent[N];
bool visited[N];
void dfs(int i){
    visited[i] = true;
    cout<<i<<" ";
    for(int x : adjacent[i]){
        if(!visited[x]){
            dfs(x);
        }
    }
}
void bfs(int i){
    queue<int> q;
    q.push(i);
    visited[i] = true;
    cout<<i<<" ";
    while(!q.empty()){
        int a = q.front();
        q.pop();
        for(int x : adjacent[a]){
            if(!visited[x]){
                cout<<x<<" ";
                q.push(x);
                visited[x] = true;
            }
        }
    }
}
int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n,e;
    cin>>n>>e;
    for(int i = 0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }

    for(int i = 1;i<=n;i++){

        if(!visited[i]){
            //dfs(i);
            bfs(i);
            cout<<endl;
        }
    }

    return 0;
}