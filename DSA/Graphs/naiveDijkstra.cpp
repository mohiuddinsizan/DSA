#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<pair<int,int>> adjacent[N];
int distances[N];
void dijkstra(int source){
    distances[source] = 0;
    queue<int> q;
    q.push(source);
    while(!q.empty()){
        int parent = q.front();
        q.pop();
        for(pair<int,int> x : adjacent[parent]){
            int node = x.first;
            int dist = x.second;
            if(dist+distances[parent]<distances[node]){
                q.push(node);
                distances[node] = dist+distances[parent];
            }
        }
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,e;
    cin>>n>>e;
    for(int i = 0;i<N;i++){
        distances[i] = INT_MAX;
    }
    for (int i = 0; i < e; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adjacent[u].push_back(make_pair(v,w));
        adjacent[v].push_back(make_pair(u,w));
    }
    dijkstra(1);
    int sum = 0;
    for(int i=1;i<=n;i++){
        //cout<<"node : "<<i<<" distance : "<<distances[i]<<endl;
        sum+=distances[i];
    }
    cout<<sum<<endl;
    return 0;
}