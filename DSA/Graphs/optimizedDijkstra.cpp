#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<pair<int,int>> adjacent[N];
int distances[N];
int parent_tracking[N];
bool visited[N];

void dijkstra(int source){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    
    q.push({0,source});
    distances[source] = 0;
    parent_tracking[source] = -1;
    visited[source] = true;

    while(!q.empty()){
        pair<int,int> parent_pair = q.top();
        int parent = parent_pair.second;
        q.pop();

        for(pair<int,int> x : adjacent[parent]){
            int cost = x.second;

            if(parent_pair.first+cost<distances[x.first]){
                visited[x.first] = true;
                parent_tracking[x.first] = parent;
                q.push({parent_pair.first+cost,x.first});
                distances[x.first] =  parent_pair.first+cost;
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
        int u,v,w;
        cin>>u>>v>>w;
        adjacent[u].push_back({v,w});
        adjacent[v].push_back({u,w});
    }

    for(int i = 1;i<=n;i++){
        distances[i] = INT_MAX;
    }

    dijkstra(1);

    // for(int i=1;i<=n;i++){
    //     cout<<"node : "<<i<<" distance : "<<distances[i]<<endl;
    // }

    vector<int> vect;
    if(visited[5]){
        int p = 5;
        while(p!=-1){
            vect.push_back(p);
            p = parent_tracking[p];
        }
    }

    reverse(vect.begin(),vect.end());

    for(int x : vect)
        cout<<x<<" ";
    
    return 0;
}