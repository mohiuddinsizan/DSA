#include<bits/stdc++.h>
using namespace std;

class edges{
    public:

    int u;
    int v;
    int w;
    edges(int u,int v,int w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main(){
    
    int n,e;
    cin>>n>>e;
    vector<edges> edge;

    while(e--){
        int u,v,w;
        cin>>u>>v>>w;
        edges ed(u,v,w);
        edge.push_back(ed);
    }

    long long distances[n+1];

    for(int i = 0;i<=n+1;i++){
        distances[i] = INT_MAX;
    }

    int source;
    source = 1;
    bool cycle = false;
    distances[source] = 0;

    for(int i = 1;i<=n;i++){
        for(int j = 0;j<edge.size();j++){
            edges ed = edge[j];
            if(distances[ed.u]+ed.w<distances[ed.v]){
                distances[ed.v] = distances[ed.u]+ed.w;
            }
        }
    }

    for(int j = 0;j<edge.size();j++){
        edges ed = edge[j];
        if(distances[ed.u]+ed.w<distances[ed.v]){
            distances[ed.v] = distances[ed.u]+ed.w;
            cycle = true;
        }
    }

    if(!cycle){
        for(int i =1 ; i<=n;i++){
        cout<<i<<" "<<distances[i]<<endl;
        }
    }

    else cout<<"Cycle detected!"<<endl;

    return 0;
}