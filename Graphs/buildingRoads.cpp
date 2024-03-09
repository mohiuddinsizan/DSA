#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> adjacent[N];
bool visited[N];
void bfs(int i){
    queue<int> q;
    q.push(i);
    visited[i] = true;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(int x : adjacent[p]){
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
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
    int roads = -1;
    vector<pair<int,int>> road;
    for(int i = 1;i<=n;i++){
        if(!visited[i]){
            roads++;
            if(roads>0){
                road.push_back({i-1,i});
            }
            bfs(i);
        }
    }
    cout<<roads<<endl;
    for(pair<int,int> x : road){
        cout<<x.first<<" "<<x.second<<endl;
    }

    return 0;
}