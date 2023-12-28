#include<bits/stdc++.h>
using namespace std;
const long long N = 1e5+5;
vector<pair<long long,long long>> adjacent[N];
bool visited[N];
long long prims(long long source){
    priority_queue<pair<long long,pair<long long,long long>>, 
    vector<pair<long long,pair<long long,long long>>>, 
    greater<pair<long long,pair<long long,long long>>>> pq;
    pq.push({0,{source,source}});
    vector<pair<long long,pair<long long,long long>>> roads;
    while(!pq.empty()){
        pair<long long,pair<long long,long long>> parent = pq.top();
        pq.pop();
        long long w = parent.first;
        long long u = parent.second.first;
        long long v = parent.second.second;
        if(visited[v]) continue;
        visited[v] = true;
        roads.push_back({u,{v,w}});
        for(pair<long long,long long> x : adjacent[v]){
            if(!visited[x.first]){
                pq.push({x.second,{v,x.first}});
            }
        }
    }

    // roads.erase(roads.begin());
    // for(pair<long long,pair<long long,long long>> x : roads){
    //     cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<endl;
    // }
    
    long long sum = 0;
    for(pair<long long,pair<int,long long>> x : roads){
        sum+=x.second.second;
    }
    return sum;
}
int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    long long n,e;
    cin>>n>>e;
    long long source=-1;
    vector<long long> nodes;
    while(e--){
        long long u,v,w;
        cin>>u>>v>>w;
        nodes.push_back(u);
        nodes.push_back(v);
        
        adjacent[u].push_back({v,w});
        adjacent[v].push_back({u,w});
        if(source == -1) source = u;
    }
    long long x = prims(source);
    bool connected = true;
    for(long long f : nodes){
        if(!visited[f]) connected = false;
    }
    if(connected)
        cout<<x;
    else cout<<"IMPOSSIBLE";
    
    return 0;
}